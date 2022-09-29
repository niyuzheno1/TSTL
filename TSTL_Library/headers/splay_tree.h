#pragma once

#include "global_allocation_policy.h"
#include "splay_key_value_pair.h"
#include "splay_tree_iterator.h"
#include "snode.h"
#include "splay_tree_count.h"
namespace tstl
{
    template<class splay_key, class splay_value>
    class splay_tree
    {
    public:
        using splay_k_v_pair = splay_key_value_pair<splay_key, splay_value>;
        using iterator = splay_tree_iterator<const splay_tree, splay_key_value_pair<splay_key, splay_value>>;
        using snode_type  = snode<splay_key, splay_value>;
        splay_k_v_pair &get_key_value_ref(node *ptr) const
        {
            return ((snode_type*)(ptr))->get_key_value_ref();
        }
        splay_k_v_pair *get_key_value_ptr(node *ptr) const
        {
            return ((snode_type*)(ptr))->get_key_value_ptr();
        }

        node *root;
        bool isLCT;
        bool require_unique;

        
        static snode_type  *new_node(const splay_key &key, const splay_value &value)
        {
            snode_type * ret = global_allocation_policy::getMemoryManager()->newInstance<snode_type>();
            ret->set_key(key);
            ret->set_value(value);
            return ret;
        }

        ~splay_tree()
        {
        }

        splay_tree()
        {
            this->isLCT = 0;
            this->require_unique = 0;
            root = &node::nil;
        }

        void assign(const splay_tree & mx)
        {
            this->isLCT = mx.isLCT;
            this->require_unique = mx.require_unique;
            this->root = &node::nil;
            for(auto & x : mx){
                this->insert(x.first, x.second);
            }
        }

        bool empty() const
        {
            return root == &node::nil;
        }

        int size() const
        {
            return root->size();
        }

        splay_tree_node_count_pair insert(const splay_key &key, const splay_value &value)
        {
            snode_type *nd = new_node(key, value);
            splay_tree_node_count_pair ret = root->insert(&root, nd, require_unique);
            return ret;
        }

        snode_type * rt(){
            return snode_cast(root);
        }

        snode_type * snode_cast(node * t) const{
            return snode_type::snode_cast(t);
        }

        iterator begin() const
        {
            snode_type *ret = snode_cast(((splay_tree*)this)->root->begin(&(((splay_tree*)this)->root)));
            return iterator(this, ret);
        }

        splay_value operator[](splay_tree_count index)
        {
            snode_type *ret = snode_cast(root->at(&root, index.count));
            return ret->get_value_ref();
        }

        splay_value &operator[](const splay_key &index)
        {
            if (this->contains(index))
            {
                snode_type * tmp = snode_cast(this->find(index).getPtr());
                return tmp->get_value_ref();
            }
            else
            {
                snode_type * snnode = snode_cast(this->insert(index, splay_value()).first);
                return snnode->get_value_ref();
            }
        }

        iterator find(const splay_key &key)
        {
            snode_type *ret = snode_cast(rt()->find(&root, key));
            return iterator(this, ret);
        }

        iterator successor(iterator &x) const
        {
            snode_type *ret = snode_cast(x.getPtr()->successor(&(((splay_tree*)this)->root)));
            return iterator(this, ret);
        }

        iterator predecessor(iterator &x) const
        {
            snode_type *ret = snode_cast(x.getPtr()->predecessor(&(((splay_tree*)this)->root)));
            return iterator(this, ret);
        }

        iterator end() const
        {
            return iterator(this, &node::nil);
        }

        void clear()
        {
            root = &snode_type::nil;
        }

        // erase by iterator
        void erase(iterator &it)
        {
            snode_type *node = snode_cast(it.getPtr()->erase(&root));
        
        }

        bool contains(const splay_key &key)
        {
            return rt()->contains(&root, key);
        }

        bool count(const splay_key &key)
        {
            return this->contains(key);
        }

        bool erase(const splay_key &key)
        {
            return rt()->erase(&root, key);

        }

        iterator prefix(const splay_key &key)
        {
            snode_type *ret = snode_cast(rt()->query_prefix_key(&root, key));
            return iterator(this, ret);
        }

        iterator prefix(splay_tree_count count)
        {
            snode_type *ret = snode_cast(rt()->query_prefix_count(&root, count.count));
            return iterator(this, ret);
        }

        iterator suffix(const splay_key &key)
        {
            snode_type *ret = snode_cast(rt()->query_suffix_key(&root, key));
            return iterator(this, ret);
        }

        iterator suffix(splay_tree_count count)
        {
            snode_type *ret = snode_cast(rt()->query_suffix_count(&root, count.count));
            return iterator(this, ret);
        }

        iterator range(splay_tree_count start, splay_tree_count end)
        {
            snode_type *ret = snode_cast(rt()->query_range(&root, start.count, end.count));
            return iterator(this, ret);
        }

        iterator range(const splay_key &lower, const splay_key &upper)
        {
            snode_type *ret = snode_cast(rt()->query_range_key(&root, lower, upper));
            return iterator(this, ret);
        }
        // index
        iterator index(int index)
        {
            snode_type *ret = snode_cast(rt()->at(&root, index));
            return iterator(this, ret);
        }
    };  
} 

