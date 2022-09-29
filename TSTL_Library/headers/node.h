#pragma once
#include "tstl.h"
namespace tstl{

class node {
public:
    static node nil;
    static const int chsz = 2;
    node *p, *c[chsz]; 
    bool flip = 0;
    int sz;
    void * data;
    node();
    static void setLink(node *x, node *y, int d);
    int dir();
    virtual void calc();
    virtual void prop();
    size_t size() const;
    bool r();
    void rot();
    bool ok0();
    void splay();
    void make_child(node *n);
    void access();
    void makeRoot();
    node *lca(node *x, node *y);
    bool connected(node *x, node *y);
    bool link(node *x, node *y);
    bool cut(node *x, node *y);
    void propAll();
    node *get_end_point(node ** root, bool endding = false, bool do_splay = true);
    node *begin(node ** root, bool do_splay = true);
    node *end(node ** root, bool do_splay = true);
    node *cessor(node ** root, bool succ, bool do_splay = true) const;
    node *predecessor(node ** root, bool do_splay = true) const;
    node *successor(node ** root, bool do_splay = true) const;
    virtual int compare_key(const node *other) const;
    virtual void swap_key(node *other);
    splay_tree_node_count_pair insert(node **root, node *x, bool require_unique);
    node *remove(node ** root);
    node *erase(node **root);
    node *at(node ** root, int index);
    node *query_prefix_count(node ** root, int count);
    node *query_suffix_count(node ** root, int count);
    node *query_range(node ** root, int start, int end);
};


}