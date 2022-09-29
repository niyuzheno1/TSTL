#pragma once
#include "global_allocation_policy.h"
namespace tstl{
    template<class splay_key, class splay_value>
    class splay_key_value_pair
    {
    public:
        splay_key first;
        splay_value second;
        splay_key_value_pair(splay_key key, splay_value value) : first(key), second(value) {}
        splay_key_value_pair() {}
        static splay_key_value_pair<splay_key, splay_value>* newInstance(splay_key key, splay_value value){
            return global_allocation_policy::getMemoryManager()->newInstance<splay_key_value_pair<splay_key, splay_value>>(key, value);
        }
        //newInstance
        static splay_key_value_pair<splay_key, splay_value>* newInstance(){
            return global_allocation_policy::getMemoryManager()->newInstance<splay_key_value_pair<splay_key, splay_value>>();
        }
    };
}
