#pragma once
#include "global_allocation_policy.h"
namespace tstl{
    template<typename T>
    class linked_list_entry{
        public:
            linked_list_entry(T data, linked_list_entry * next){
                this->data = data;
                this->next = next;
            }
            T data;
            linked_list_entry * next;
            //newInstance 
            static linked_list_entry * newInstance( T  data, linked_list_entry * next){
                return global_allocation_policy::getMemoryManager()->newInstance<linked_list_entry>(data, next);
            }
            //deleteInstance
            static void deleteInstance(linked_list_entry * ptr){
                //tree_sitter_system_util::system_initializer::gmm->deleteInstance(ptr);
            }
    };
}