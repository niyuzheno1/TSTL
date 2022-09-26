#pragma once
#include "tstl.h"
namespace tstl {
    class splay_tree_node_count_pair
    {
    public:
        splay_tree_node_count_pair(node *node, int count);
        node *first;
        int second;
    };
}