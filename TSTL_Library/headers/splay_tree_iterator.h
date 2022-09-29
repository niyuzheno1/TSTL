#pragma once
#include "node.h"
namespace tstl{
    template <class U, class splay_key_value_pair>
    class splay_tree_iterator
    {
    public:
        splay_tree_iterator(U *container, node *node) : container(container), ptr(node) {}
        splay_tree_iterator &operator=(const splay_tree_iterator &other)
        {
            container = other.container;
            ptr = other.ptr;
            return *this;
        }
        bool operator==(const splay_tree_iterator &other)
        {
            return container == other.container && ptr == other.ptr;
        }
        bool operator!=(const splay_tree_iterator &other)
        {
            return !(*this == other);
        }
        splay_tree_iterator &operator++()
        {
            *this = container->successor(*this);
            return *this;
        }
        splay_tree_iterator &operator--()
        {
            *this = container->predecessor(*this);
            return *this;
        }
        splay_key_value_pair &operator*()
        {
            
            return container->get_key_value_ref(ptr);
        }
        splay_key_value_pair *operator->()
        {
            return container->get_key_value_ptr(ptr);
        }
        node *getPtr()
        {
            return ptr;
        }

    private:
        U *container; // underlying container
        node *ptr;   // value
    };

}
