#pragma once
//support for set, map, linked_list
template<typename U, typename T> //U for underlying container and T for value type
class skip_iterator{
    public:
        //support for operator=, operator==, operator!=, operator++, operator--, operator*, operator->
        skip_iterator(U* container, T* ptr) : container(container), ptr(ptr){}
        skip_iterator& operator=(const skip_iterator& other){
            container = other.container;
            ptr = other.ptr;
            return *this;
        }
        bool operator==(const skip_iterator& other){
            return container == other.container && ptr == other.ptr;
        }
        bool operator!=(const skip_iterator& other){
            return !(*this == other);
        }
        skip_iterator& operator++(){
            ptr = container->successorOf(ptr);
            return *this;
        }
        skip_iterator& operator--(){
            ptr = container->predecessorOf(ptr);
            return *this;
        }
        T& operator*(){
            return *ptr;
        }
        T* operator->(){
            return ptr;
        }
       
    private:
        U * container; //underlying container
        T * ptr; //value
};