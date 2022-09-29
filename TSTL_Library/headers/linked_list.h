#pragma once
#include "skip_iterator.h"
#include "linked_list_entry.h"
#include <initializer_list>
#include "global_allocation_policy.h"
namespace tstl{
     template<typename T>
    class linked_list{
        private:
            linked_list_entry<T> * head;
            linked_list_entry<T> * tail;
            size_t mSize;
        public:
            linked_list(){
                head = nullptr;
                tail = nullptr;
                mSize = 0;
            }
            linked_list(const linked_list & vx){
                head = nullptr;
                tail = nullptr;
                mSize = 0;
                for(auto it = vx.begin(); it != vx.end(); it++){
                    push_back(it->data);
                }
            }
            linked_list(linked_list && vx){
                head = vx.head;
                tail = vx.tail;
                mSize = vx.mSize;
                vx.head = nullptr;
                vx.tail = nullptr;
                vx.mSize = 0;
            }
            linked_list (std::initializer_list<T> il){
                head = nullptr;
                tail = nullptr;
                mSize = 0;
                for(auto it = il.begin(); it != il.end(); it++){
                    push_back(*it);
                }
            }
            linked_list &operator=(const linked_list<T> & vx){
                clear();
                for(auto it = vx.begin(); it != vx.end(); ++it){
                    push_back(it->data);
                }
                return *this;
            }
            linked_list &operator=(linked_list && vx){
                clear();
                head = vx.head;
                tail = vx.tail;
                mSize = vx.mSize;
                vx.head = nullptr;
                vx.tail = nullptr;
                vx.mSize = 0;
                return *this;
            }
           
            void push_back(const T & x){
                if(head == nullptr){
                    head = linked_list_entry<T>::newInstance(x, nullptr);
                    tail = head;
                }else{
                    tail->next = linked_list_entry<T>::newInstance(x, nullptr);
                    tail = tail->next;
                }
                mSize++;
            }
            void push_back(T && x){
                if(head == nullptr){
                    head = linked_list_entry<T>::newInstance(x, nullptr);
                    tail = head;
                }else{
                    tail->next = linked_list_entry<T>::newInstance(x, nullptr);
                    tail = tail->next;
                }
                mSize++;   
            }
            
            void pop_back(){
                if(head == nullptr){
                    return;
                }
                if(head == tail){
                    linked_list_entry<T>::deleteInstance(head);
                    head = nullptr;
                    tail = nullptr;
                    mSize = 0;
                    return;
                }
                linked_list_entry<T> * it = head;
                while(it->next != tail){
                    it = it->next;
                }
                linked_list_entry<T>::deleteInstance(tail);
                tail = it;
                tail->next = nullptr;
                mSize--;
            }
            void clear(){
                linked_list_entry<T> * it = head;
                while(it != nullptr){
                    linked_list_entry<T> * tmp = it;
                    it = it->next;
                    linked_list_entry<T>::deleteInstance(tmp);
                }
                head = nullptr;
                tail = nullptr;
                mSize = 0;
            }
            void reserve(size_t sz){
                //do nothing
            }
            void resize(size_t sz){
                //do nothing
            }
            void assign(const linked_list & vx){
                clear();
                for(auto it = vx.begin(); it != vx.end(); it++){
                    push_back(it->data);
                }
            }
            void assign(linked_list && vx){
                clear();
                head = vx.head;
                tail = vx.tail;
                mSize = vx.mSize;
                vx.head = nullptr;
                vx.tail = nullptr;
                vx.mSize = 0;
            }
            T &operator[](size_t idx) const{
                linked_list_entry<T> * it = head;
                for(size_t i = 0; i < idx; i++){
                    it = it->next;
                }
                return it->data;
            }
            T &at(size_t idx) const{
                linked_list_entry<T> * it = head;
                for(size_t i = 0; i < idx; i++){
                    it = it->next;
                }
                return it->data;
            }
            size_t size() const{
                return mSize;
            }
            template< class... Args >
            void emplace_back( Args&&... args ){
                if(head == nullptr){
                    head = linked_list_entry<T>::newInstance(T::newInstance(args...), nullptr);
                    tail = head;
                }else{
                    tail->next = linked_list_entry<T>::newInstance(T::newInstance(args...), nullptr);
                    tail = tail->next;
                }
                mSize++;
            }
            bool empty(){
                return mSize == 0;
            }
            size_t indexOf(const T & x){
                linked_list_entry<T> * it = head;
                size_t idx = 0;
                while(it != nullptr){
                    if(it->data == x){
                        return idx;
                    }
                    it = it->next;
                    idx++;
                }
                return -1;
            }
            void erase(int idx){
                if(idx == 0){
                    linked_list_entry<T> * tmp = head;
                    head = head->next;
                    linked_list_entry<T>::deleteInstance(tmp);
                    mSize--;
                    return;
                }
                linked_list_entry<T> * it = head;
                for(int i = 0; i < idx - 1; i++){
                    it = it->next;
                }
                linked_list_entry<T> * tmp = it->next;
                it->next = it->next->next;
                linked_list_entry<T>::deleteInstance(tmp);
                mSize--;
            }
            T &back(){
                return tail->data;
            }

            static linked_list<T> * newInstance(){
                return global_allocation_policy::getMemoryManager()->newInstance<linked_list<T>>();
            }

            //predecessorOf
            static linked_list_entry<T> * predecessorOf(linked_list_entry<T> * ptr){
                linked_list_entry<T> * it = head;
                while(it != nullptr){
                    if(it->next == ptr){
                        return it;
                    }
                    it = it->next;
                }
                return nullptr;
            }
            //successorOf
            static linked_list_entry<T> * successorOf(linked_list_entry<T> * ptr){
                return ptr->next;
            }

            //begin and end
            skip_iterator<const linked_list<T>, linked_list_entry<T>> begin() const {
                return skip_iterator<const linked_list<T>, linked_list_entry<T>>(this, head);
            }
            skip_iterator<const linked_list<T>, linked_list_entry<T>>  end() const {
                return skip_iterator<const linked_list<T>, linked_list_entry<T>>(this, (linked_list_entry<T>*)nullptr);
            }
      
    };
}