#pragma once
#include "global_allocation_policy.h"
namespace tstl{
    class string{
        public:
            string();
            string(const char * );
            string(const string & );
            string(string && );
            string &operator=(const string &);
            string &operator=(string &&);
            const char *c_str() const;
            operator const char *() const;
            string operator+(const string &);
            string operator+(const char *);
            string operator+(const char );
            string& operator+=(const string &);
            string& operator+=(const char *);
            string& operator+=(const char );
            bool operator<=(const string &)  const;
            bool operator<=(const char *)  const;
            bool operator>=(const string &)  const;
            bool operator>=(const char *)  const;
            bool operator<(const string &)  const;
            bool operator<(const char *)  const;
            bool operator>(const string &)  const;
            bool operator>(const char *)  const;
            bool operator==(const string &) const;
            bool operator==(const char *) const;
            bool operator!=(const string &)  const;
            bool operator!=(const char * )  const;
            size_t size() const;
            size_t length() const;
            void clear();
            void resize(size_t n);
            void reserve(size_t n);
            size_t find(const string & content, size_t pos = 0) const;
            size_t find(const char *content, size_t pos = 0) const;
            size_t find(const char content, size_t pos = 0) const;
            string substr(size_t pos = 0, size_t len = (size_t)(-1)) const;
            void assign(const string &content, size_t len = (size_t)(-1));
            void assign(const char *content, size_t len = (size_t)(-1));
            void assign(const char ch, size_t len = (size_t)(1));
            void append(const string &content);
            void append(const char *content);
            void append(const char ch);
            int compare(const string &content, size_t pos= 0, size_t len = (size_t)(-1)) const;
            int compare(const char *content, size_t pos= 0, size_t len = (size_t)(-1)) const;
            char& operator[] (size_t index);
            char& at(size_t index) const;
            long long tolonglong();

        private:
            char * m_string_ptr;
            int m_capacity;
            int m_length;

    };
    string operator+(const string &, const string &);
    string operator+(const char * , const string &);
    string operator+(const char , const string &);
    string to_string(int);
    string to_string(double);
    string to_string(bool);
    string to_string(const char *);
    string to_string(long long);
    
}