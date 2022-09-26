#pragma once
namespace tstl{
    template<class splay_key, class splay_value>
    class splay_key_value_pair
    {
    public:
        splay_key first;
        splay_value second;
        splay_key_value_pair(splay_key key, splay_value value) : first(key), second(value) {}
        splay_key_value_pair() {}
    };
}
