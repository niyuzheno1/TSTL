#pragma once
#include "vector.h"
#include "pair.h"
#include "assert.h"
#include "splay_tree.h"
#include "global_allocation_policy.h"
namespace tstl{
    // class map
    template<class T1, class T2>
    class map{
        public:
            //constructors
            map() : m_data(nullptr){
                
            }
            map(const map & mx) : m_data(nullptr){
                assign(mx);
            }
            map(map && mx) : m_data(nullptr){
                assign(mx);
            }
            map &operator=(const map & mx){
                assign(mx);
                return *this;
            }
            map &operator=(map && mx){
                assign(mx);
                return *this;
            }
            void assign(const map & mx){
                accessData();
                this->m_data->assign(*mx.m_data);
            }
            void assign(map && mx){
                this->m_data = mx.m_data;
                mx.m_data = nullptr;
            }
            void accessData(){
                if(this->m_data == nullptr){
                    this->m_data = global_allocation_policy::getMemoryManager()->newInstance<splay_tree<T1, T2>>();
                }
            }
            bool empty() const{
                if(this->m_data == nullptr){
                    return true;
                }
                return m_data->empty();
            }
            size_t size() const{
                if(this->m_data == nullptr){
                    return 0;
                }
                return m_data->size();
            }

            // Element access:
            // operator[]	Access element (public member function)
            T2& operator[](const T1& key) {
                accessData();
                auto it = this->m_data->find(key);
                if(it == this->m_data->end()){
                    this->m_data->insert(key, T2());
                }
                it = this->m_data->find(key);
                return it->second;
            }
            // at	Access element (public member function)
            T2& at(const T1& key) const {
                if(this->m_data == nullptr){
                    assert(false); //TODO: throw exception
                }
                auto it = this->m_data->find(key);
                if(it == this->m_data->end()){
                    //throw std::out_of_range("key not found");
                    assert(false);
                    exit(0);
                }
                return it->second;
            }
            // Modifiers:
            // insert	Insert elements (public member function)
            void insert(const T1& key, const T2& value){
                accessData();
                auto it = this->m_data->find(key);
                if(it == this->m_data->end()){
                    this->m_data->insert(key, value);
                }
                it = this->m_data->find(key);
                it->second = value;
            }
            // erase	Erase elements (public member function)
            void erase(const T1& key){
                accessData();
                auto it = this->m_data->find(key);
                if(it == this->m_data->end()){
                    //throw std::out_of_range("key not found");
                    assert(false);
                    exit(0);
                }
                this->m_data->erase(it);
            }
            void clear(){
                m_data->clear();
            }
            int count(const T1& key) const {
                if(this->m_data == nullptr){
                    return 0;
                }
                auto it = this->m_data->find(key);
                if(it == this->m_data->end()){
                    return 0;
                }
                return 1;
            }
            

        private:
            splay_tree<T1, T2> * m_data;

    };
    
}