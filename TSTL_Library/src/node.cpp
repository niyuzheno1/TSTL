#include "node.h"
#include "assert.h"
#include "splay_tree_node_count_pair.h"
using namespace tstl;

node::node()
{
    p = c[0] = c[1] = &nil;
    sz = 0;
    if (this != &nil)
        sz = 1;
    flip = 0;
}
void node::setLink(node *x, node *y, int d)
{
    if (y != &nil)
        y->p = x;
    if (d >= 0)
        x->c[d] = y;
}

int node::dir()
{
    if (p == &nil)
        return -1;
    for (int i = 0; i < 2; ++i)
    {
        if (p->c[i] == this)
            return i;
    }
    return -1;
}

void node::calc()
{
    if (this == &nil)
    {
        this->c[0] = this->c[1] = this->p = &nil;
        this->sz = 0;
        return;
    }
    for (int i = 0; i < chsz; i++)
    {
        c[i]->prop();
    }
    sz = 1;
    for (int i = 0; i < chsz; i++)
    {
        sz += c[i]->size();
    }
}
void node::prop()
{
    if (this == &nil)
        return;
    if (flip)
    {
        node *tmp = c[0];
        c[0] = c[1];
        c[1] = tmp;
        for (int i = 0; i < chsz; i++)
            if (c[i])
                c[i]->flip ^= 1;
        flip = 0;
    }
}

size_t node::size() const
{
    if (this == &nil)
        return 0;
    return sz;
}

bool node::r()
{
    int d = dir();
    return d == -1;
}

void node::rot()
{
    if (r())
        return;
    int x = dir();
    node *pa = p;
    setLink(pa->p, this, pa->dir());
    setLink(pa, c[x ^ 1], x);
    setLink(this, pa, x ^ 1);
    pa->calc();
    calc();
}
bool node::ok0()
{
    int d = dir();
    return d == 0 || d == 1;
}
void node::splay()
{
    if (this == &nil)
        return;
    if (r())
    {
        prop();
        calc();
        return;
    }
    while (!r() && !p->r())
    {
        p->p->prop(), p->prop(), prop();
        dir() == p->dir() ? p->rot() : rot();
        rot();
    }
    if (!r())
        p->prop(), prop(), rot();
    prop();
    calc();
}

void node::make_child(node *n)
{
    assert(!flip && r());
    if (c[1] != &nil)
    {
        node *v = c[1];
        c[1] = &nil;
        assert(v->r());
        calc();
    }
    assert(!flip && c[1] == &nil);
    if (n != &nil)
    {
        assert(n->r());
        assert(n->p == this);
        c[1] = n;
        assert(c[1]->p == this);
        calc();
    }
}

void node::access()
{
    splay();
    assert(!flip);
    make_child(&nil);
    while (p != &nil)
    {
        assert(r());
        p->splay();
        p->make_child(this);
        assert(!p->flip);
        assert(!flip);
        rot();
        calc();
        assert(r());
    }
    assert(p == &nil && c[1] == &nil);
}
void node::makeRoot()
{
    access();
    assert(p == &nil && r());
    flip ^= 1;
}

node * node::lca(node *x, node *y)
{
    if (x == y)
        return x;
    x->access();
    y->access();
    if (x->p == &nil)
        return &nil;
    x->splay();
    return x->p ? x->p : x;
}

bool node::connected(node *x, node *y)
{
    return lca(x, y);
}

bool node::link(node *x, node *y)
{
    if (connected(x, y))
        assert(false);
    x->makeRoot();
    setLink(y, x, 0);
    y->calc();
    return 1;
}

bool node::cut(node *x, node *y)
{
    x->makeRoot();
    y->access();
    if (y->c[0] != x || x->c[0] != &nil || x->c[1] != &nil) assert(false);
    x->p = y->c[0] = &nil;
    y->calc();
    return 1;
}

void node::propAll()
{
    prop();
    for (int i = 0; i < chsz; ++i)
    {
        if (c[i] != &nil)
            c[i]->propAll();
    }
}


node * node::get_end_point(node **root, bool endding, bool do_splay )
{
    if (this == &nil)
        return &nil;
    node *v = this;
    while (v->c[endding] != &nil)
        v = v->c[endding];
    if (do_splay)
    {
        *root = v;
        v->splay();
    }
    return v;
}
node * node::begin(node **root, bool do_splay )
{
    if (this == &nil)
        return &nil;
    return get_end_point(root, false, do_splay);
}
node * node::end(node **root, bool do_splay )
{
    if (this == &nil)
        return &nil;
    return get_end_point(root, true, do_splay);
}

node * node::cessor(node **root, bool succ, bool do_splay) const
{
    if (this == &nil)
        return &nil;
    if (c[succ] != &nil)
        return c[succ]->get_end_point(root, !succ, do_splay);
    const node *v = this;
    while (v->p != &nil && v->p->c[succ] == v)
        v = v->p;
    return v->p;
}

node * node::predecessor(node **root, bool do_splay) const
{
    if (this == &nil)
        return &nil;
    return cessor(root, false, do_splay);
}
node * node::successor(node **root, bool do_splay) const
{
    if (this == &nil)
        return &nil;
    return cessor(root, true, do_splay);
}

int node::compare_key(const node *other) const
{
    return 0;
}

void node::swap_key(node *other)
{
}

splay_tree_node_count_pair node::insert(node **root, node *x, bool require_unique)
{
    if (this == &nil)
    {
        *root = x;
        return splay_tree_node_count_pair(x, 0);
    }
    node *cur = this, *pre = &nil;
    while (cur != &nil)
    {
        pre = cur;
        // if (cur->get_key() < x->get_key())
        if (cur->compare_key(x) < 0)
        {
            cur = cur->c[1];
        }
        else
        {
            if (require_unique && !(x->compare_key(cur) < 0))
            {
                cur->splay();
                *root = cur;
                assert(cur->r());
                // return {cur, cur->c[0]->size()};
                return splay_tree_node_count_pair(cur, cur->c[0]->size());
            }
            cur = cur->c[0];
        }
    }
    node::setLink(pre, x, pre->compare_key(x) < 0);
    x->splay();
    *root = x;
    return splay_tree_node_count_pair(x, x->c[0]->size());
}

node *node::remove(node **root)
{
    if (this == &nil)
        return &nil;
    assert(this->c[0] == &nil || this->c[1] == &nil);
    node *child = this->c[0] ? this->c[0] : this->c[1];
    if (this->p != &nil)
    {
        node *p = this->p;
        node::setLink(p, child, this->dir());
        p->calc();
        if (child != &nil)
        {
            child->splay();
            *root = child;
        }
        else
        {
            assert(p != &nil);
            p->splay();
            *root = p;
        }
    }
    else
    {
        if (child != &nil)
        {
            child->p = &nil;
        }
        child->splay();
        *root = child;
    }

    return child;
}
node *node::erase(node **root)
{
    if (this == &nil)
        return &nil;
    node *x = this;
    if (x->c[0] != &nil && x->c[1] != &nil)
    {
        node *y = x->predecessor(root, false);
        x->swap_key(y);
        x = y;
    }
    return x->remove(root);
}

node *node::at(node **root, int index)
{
    if (this == &nil)
        return &nil;
    if (index < 0 || index >= size())
        return &nil;
    node *cur = this;
    while (cur != &nil)
    {
        int left_size = cur->c[0]->size();
        if (index == left_size)
        {
            cur->splay();
            *root = cur;
            return cur;
        }
        if (index < left_size)
        {
            cur = cur->c[0];
        }
        else
        {
            cur = cur->c[1];
            index -= left_size + 1;
        }
    }
    assert(false);
    return &nil;
}

node *node::query_prefix_count(node **root, int count)
{
    if (this == &nil)
        return &nil;
    if (count <= 0)
        return &nil;
    node *node = this->at(root, count);
    if (node == &nil)
        return this;
    node->splay();
    *root = node;
    return node->c[0];
}
node *node::query_suffix_count(node **root, int count)
{
    if (this == &nil)
        return &nil;
    if (count <= 0)
        return &nil;
    else if (count >= size())
        return this;
    int index = size() - count;
    node *node = at(root, index);
    node->splay();
    return node->c[1];
}

node *node::query_range(node **root, int start, int end)
{
    if (this == &nil)
        return &nil;
    if (start >= end)
        return &nil;
    else if (start <= 0)
        return this->query_prefix_count(root, end);
    else if (end >= size())
        return this->query_suffix_count(root, size() - start);

    node *before = at(root, start - 1);
    node *after = at(root, end);

    after->splay();
    *root = after;

    before->splay();
    *root = before;
    if (after->p != before)
    {
        after->rot();
        if (after->r())
        {
            *root = after;
        }
    }
    assert(before->c[1] == after);
    return after->c[0];
}