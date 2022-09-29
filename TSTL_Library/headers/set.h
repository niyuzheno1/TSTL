#pragma once
#include "map.h"
namespace tstl{
    template<typename T1>
    class set{
        public:
            set(){

            }
            set (std::initializer_list<T1> il){
                for (auto &i : il){
                    insert(i);
                }
            }
            bool empty() const{
                return m_data.empty();
            }
            size_t size() const{
                return m_data.size();
            }

            void insert(const T1& key){
                m_data.insert(key, true);
            }
            void erase(const T1& key){
                m_data.erase(key);
            }
            void clear(){
                m_data.clear();
            }
            int count(const T1& key) const {
                return m_data.count(key);
            }
           
        private:
            map<T1, bool> m_data;
    };
    
}