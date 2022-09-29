#pragma once
#include "global_allocation_policy.h"
namespace tstl{
    // class pair
    template<class T1, class T2>
    class pair{
        public:
            pair() : first(), second(){

            }
            pair(const T1 &x, const T2 &y) : first(x), second(y){

            }
            pair(T1 &&x, T2 &&y) : first(x), second(y){

            }
            pair(const pair &p) : first(p.first), second(p.second){

            }
            pair(pair &&p) : first(p.first), second(p.second){

            }
            //operator =
            pair &operator=(const pair &p){
                first = p.first;
                second = p.second;
                return *this;
            }
            T1 first;
            T2 second;
            //new instance
            static pair *new_instance(const T1 &x, const T2 &y){
                return global_allocation_policy::getMemoryManager()->newInstance<pair<T1, T2>>(x, y);
            }
    };
    template<typename T1, typename T2>
    pair<T1, T2> make_pair(const T1 &x, const T2 &y){
        return pair<T1, T2>(x, y);
    }
    
}
