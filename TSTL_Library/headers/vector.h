#pragma once
#pragma once
#include "assert.h"
#include "global_allocation_policy.h"
namespace tstl{
    // class vector
    template<typename T>
    class vector{
        public:
            vector(){
                m_data = nullptr;
                m_size = 0;
                m_capacity = 0;
            }
            vector(const vector & vx){
                m_data = nullptr;
                m_size = 0;
                m_capacity = 0;
                assign(vx);
            }
            vector(vector && vx){
                m_data = nullptr;
                m_size = 0;
                m_capacity = 0;
                assign(vx);
            }
            vector (std::initializer_list<T> il){
                m_data = nullptr;
                m_size = 0;
                m_capacity = 0;
                for (auto &i : il){
                    push_back(i);
                }
            }
            vector &operator=(const vector & vx){
                assign(vx);
                return *this;
            }
            vector &operator=(vector && vx){
                assign(vx);
                return *this;
            }
            void push_back(const T & x){
                if(m_size == m_capacity){
                    stretch();
                }
                m_data[m_size] = x;
                m_size++;
            }
            void push_back(T && x){
                if(m_size == m_capacity){
                    stretch();
                }
                m_data[m_size] = x;
                m_size++;
            }
            
            void pop_back(){
                m_size--;
            }
            void clear(){
                m_size = 0;

            }
            void reserve(size_t sz){
                if(sz <= m_capacity){
                    return;
                }
                T * new_data;
                new_data = (T*)global_allocation_policy::getMemoryManager()->allocate(sz * sizeof(T));
                memset(new_data, 0, sz*sizeof(T));
                for(size_t i = 0; i < m_size; i++){
                    new_data[i] = m_data[i];
                }
                
                m_data = new_data;
                m_capacity = sz;
            }
            void resize(size_t sz){
                if(sz <= m_capacity){
                    return;
                }
                T * new_data;
                new_data = (T*)global_allocation_policy::getMemoryManager()->allocate(sz * sizeof(T));                
                for(size_t i = 0; i < m_size; i++){
                    new_data[i] = m_data[i];
                }
                
                m_data = new_data;
                m_capacity = sz;
            }
            void assign(const vector & vx){
                if(this == &vx){
                    return;
                }
                m_size = vx.m_size;
                m_capacity = vx.m_capacity;
                // use walloc1d 
                m_data = (T*)global_allocation_policy::getMemoryManager()->allocate(m_capacity * sizeof(T));
                // copy from memory
                for(size_t i = 0; i < m_size; i++){
                    m_data[i] = vx.m_data[i];
                }
            }
            void assign(vector && vx){
                if(this == &vx){
                    return;
                }
                m_size = vx.m_size;
                m_capacity = vx.m_capacity;
                m_data = vx.m_data;
               
            }
            T &operator[](size_t idx) const{
                return m_data[idx];
            }
            T &at(size_t idx) const{
                return m_data[idx];
            }
            size_t size() const{
                return m_size;
            }
            template< class... Args >
            void emplace_back( Args&&... args ){
                if(m_size == m_capacity){
                    stretch();
                }
                m_data[m_size] = T(std::forward<Args>(args)...);
                m_size++;
            }
            bool empty() const{
                return m_size == 0;
            }
            //findidx
            size_t findidx(const T & x){
                for(size_t i = 0; i < m_size; i++){
                    if(m_data[i] == x){
                        return i;
                    }
                }
                return m_size;
            }
            void erase(int idx){
                for(size_t i = idx; i < m_size; i++){
                    m_data[i] = m_data[i+1];
                }
                m_size--;
            }
            //back
            T &back(){
                assert(m_size > 0);
                return m_data[m_size-1];
            }
        private:
            void stretch(){
                //futureCapacity = computeFutureCapacity();
                int futureCapacity = m_capacity * 2 + 1;
                if(futureCapacity > 7){
                    futureCapacity = m_capacity * 3 / 2;
                }
                reserve(futureCapacity);
            }
            T *m_data;
            size_t m_size;
            size_t m_capacity;
    };
}
