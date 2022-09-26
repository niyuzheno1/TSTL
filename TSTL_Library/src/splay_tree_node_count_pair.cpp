#include "splay_tree_node_count_pair.h"
using namespace tstl;
splay_tree_node_count_pair::splay_tree_node_count_pair(
    node *node,
    int count)
    : first(node),
      second(count)
{
}