#pragma once
//support for string, vector
namespace tstl{
    template<typename T>
    class linear_iterator{
        public:
            //support for operator=, operator==, operator!=, operator++, operator--, operator*, operator->
            linear_iterator(T* ptr):ptr(ptr){}
            linear_iterator& operator=(const linear_iterator& other){
                ptr = other.ptr;
                return *this;
            }
            bool operator==(const linear_iterator& other){
                return ptr == other.ptr;
            }
            bool operator!=(const linear_iterator& other){
                return ptr != other.ptr;
            }
            linear_iterator& operator++(){
                ptr++;
                return *this;
            }
            linear_iterator& operator--(){
                ptr--;
                return *this;
            }
            T& operator*(){
                return *ptr;
            }
            T* operator->(){
                return ptr;
            }
        private:
            T * p; //underlying address
    };
}
