#pragma once
#include "tstl.h"
#include "global_allocation_policy.h"
namespace tstl
{
    template<class splay_key, class splay_value>
    class snode : public node 
    {
    public:
        using splay_k_v_pair = splay_key_value_pair<splay_key, splay_value>;
        splay_k_v_pair & key_value() const{
            return *(splay_k_v_pair*)this->data;
        }
        // customizable
        void set_value(const splay_value &value)
        {
            this->key_value().second = value;
        }
        splay_value get_value() const
        {
            return this->key_value().second;
        }
        void set_key(const splay_key &key)
        {
            this->key_value().first = key;
        }
        splay_key get_key() const
        {
            return key_value().first;
        }
        splay_k_v_pair *get_key_value_ptr()
        {
            return (splay_k_v_pair*)this->data;
        }
        splay_k_v_pair &get_key_value_ref()
        {
            return *this->get_key_value_ptr();
        }
        // get_value_ref
        splay_value &get_value_ref()
        {
            return key_value().second;
        }
        void swap_key(node *other) override
        {
            swap(key_value().first, ((snode*)other)->key_value().first);
        }
        static const snode * const_snode_cast(const node * _other) {
            const snode* other = dynamic_cast<const snode*>(_other);
            if(other == nullptr){
                other = (const snode*)&node::nil;
            }
            return other;
        }
        static snode * snode_cast(node * _other){
            snode* other = dynamic_cast<snode*>(_other);
            if(other == nullptr){
                other = (snode*)&node::nil;
            }
            return other;
        }
        int compare_key(const node *_other) const override
        {
            const snode* other = const_snode_cast(_other);
            return key_value().first - other->key_value().first;
        }

        snode()
        {
            if (this == &nil)
            {
                sz = 0;
            }
            else
            {
                sz = 1;
            }
            p = &nil;
            for (int i = 0; i < chsz; i++)
                c[i] = &nil;
            this->data = splay_k_v_pair::newInstance();
        }

        splay_tree_node_count_pair lower_bound(node ** root, const splay_key &key)
        {
            if (this == &nil)
                return splay_tree_node_count_pair(&nil, 0);
            snode *cur = this, *previous = (snode *)&nil, *answer = (snode *)&nil;
            int below = 0;
            while (cur != &nil)
            {
                previous = cur;
                if (cur->get_key() < key)
                {
                    below += cur->c[0]->size() + 1;
                    cur = snode_cast(cur->c[1]);
                }
                else
                {
                    answer = cur;
                    cur = snode_cast(cur->c[0]);
                }
            }
            previous->splay();
            *root = previous;
            return splay_tree_node_count_pair(answer, below);
        }

        snode *query_prefix_key(node ** root, const splay_key &key)
        {
            if (this == &nil) return (snode*)&nil;
            snode *node = snode_cast(this->lower_bound(root, key).first);
            if (node == &nil)
                return this;
            node->splay();
            *root = node;
            snode * ret = snode_cast(node->c[0]);
            return ret;
        }

        snode *query_suffix_key(node ** root, const splay_key &key)
        {
            if (this == &nil) return (snode*)&nil;
            snode *_node = snode_cast(lower_bound(root, key).first);
            if (  _node == &nil) return this;
            _node = snode_cast(_node->successor(root));
            if (_node == nullptr || _node == &nil) return this;
            _node->splay();
            *root = _node;
            snode * ret  = snode_cast(_node->c[1]);
            return ret;
        }

        snode *query_range_key(node ** root, const splay_key &lower, const splay_key &upper)
        {
            snode *  ret = snode_cast(query_range(root, lower_bound(root, lower).second, lower_bound(root, upper).second));
            return ret;
        }

        bool contains(node ** root, const splay_key &key)
        {
            if (this == &nil) return false;
            snode * _node = snode_cast(lower_bound(root, key).first);
            if (_node == &nil) return false;
            return _node != &nil && _node->get_key() == key;
        }
        bool erase(node **root, const splay_key &key)
        {
            snode * _node = snode_cast(this->lower_bound(root, key).first);
            if (_node == &nil || _node->get_key() != key)
                return false;
            ((node*)_node)->erase(root);
            return true;
        }
        snode *find(node **root, const splay_key &key)
        {
            snode * _node = snode_cast(this->lower_bound(root, key).first);
            if ( _node == &nil || _node->get_key() != key) return (snode*)&nil;
            _node->splay();
            *root = _node;
            return _node;
        }
        //newInstance
        static snode * newInstance()
        {
            return global_allocation_policy::getMemoryManager()->newInstance<snode>();
        }
        
    };
} 

