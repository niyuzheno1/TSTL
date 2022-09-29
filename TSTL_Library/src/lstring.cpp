#include "lstring.h"
#include "lstring.h"
#include <cstdlib>
#include <memory>
#include <cstring>
#include <cassert>


using namespace tstl;
// string();
string::string(){
    m_string_ptr = nullptr;
    m_capacity = 0;
    m_length = 0;
    assign("");
}
// string(const char * );
string::string(const char *s){
    m_string_ptr = nullptr;
    m_capacity = 0;
    m_length = 0;
    assign(s);
}
// string(const string &s );
string::string(const string &s){
    m_string_ptr = nullptr;
    m_capacity = 0;
    m_length = 0;
    assign(s);
}
// string(string && s);
string::string(string &&s){
    m_string_ptr = nullptr;
    m_capacity = -1;
    m_length = 0;
    assign(s);
}
string &string::operator=(const string &s){
    this->m_string_ptr = s.m_string_ptr;
    this->m_capacity = s.m_capacity;
    this->m_length = s.m_length;
    return *this;
}
string &string::operator=(string &&s){
    this->m_string_ptr = s.m_string_ptr;
    this->m_capacity = s.m_capacity;
    this->m_length = s.m_length;
    return *this;
}
// const char *c_str() const;
const char *string::c_str() const{
    return m_string_ptr;
}
// operator const char *() const;
string::operator const char *() const{
    return m_string_ptr;
}
// string operator+(const string &str);
string string::operator+(const string & sx){
    string s;
    s.reserve(m_length + sx.m_length);
    s.assign(*this);
    s.append(sx);
    return s;
}
// string operator+(const char *str);
string string::operator+(const char *sx){
    string s;
    s.reserve(m_length + strlen(sx));
    s.assign(*this);
    s.append(sx);
    return s;
}
// string operator+(const char ch);
string string::operator+(const char ch){
    string s;
    s.reserve(m_length + 1);
    s.assign(*this);
    s.append(ch);
    return s;
}
// string operator+=(const string &str);
string &string::operator+=(const string &sx){
    append(sx);
    return *this;
}
// string operator+=(const char *str);
string &string::operator+=(const char *sx){
    append(sx);
    return *this;
}
// string operator+=(const char ch);
string &string::operator+=(const char ch){
    append(ch);
    return *this;
}
// bool operator<=(const string &str);
bool string::operator<=(const string &sx) const{
    return compare(sx) <= 0;
}
// bool operator<=(const char *sx);
bool string::operator<=(const char *sx)  const{
    return compare(sx) <= 0;
}
// bool operator>=(const string &str);
bool string::operator>=(const string &sx)  const{
    return compare(sx) >= 0;
}
// bool operator>=(const char *str);
bool string::operator>=(const char *sx)  const{
    return compare(sx) >= 0;
}
// bool operator<(const string &str);
bool string::operator<(const string &sx)  const{
    return compare(sx) < 0;
}
// bool operator<(const char *str);
bool string::operator<(const char *sx)  const{
    return compare(sx) < 0;
}
// bool operator>(const string &str);
bool string::operator>(const string &sx)  const{
    return compare(sx) > 0;
}
// bool operator>(const char *str);
bool string::operator>(const char *sx)  const{
    return compare(sx) > 0;
}
bool string::operator==(const string &sx) const{
    return compare(sx) == 0;
}
bool string::operator==(const char *sx) const{
    return compare(sx) == 0;
}
// bool operator!=(const string &str);
bool string::operator!=(const string &sx)  const{
    return compare(sx) != 0;
}
// bool operator!=(const char *str);
bool string::operator!=(const char *sx)  const{
    return compare(sx) != 0;
}
// size_t size() const;
size_t string::size() const{
    return m_length;
}
// size_t m_length() const;
size_t string::length() const{
    return this->m_length;
}
// void clear();
void string::clear(){
    if(m_string_ptr != nullptr){
        m_string_ptr = nullptr;
    }
    m_length = 0;
    m_capacity = 0;
}
// void resize(size_t n);
void string::resize(size_t n){
    reserve(n);
    m_length = n;
}
// void reserve(size_t n);
void string::reserve(size_t n){
    if(n > m_capacity || m_string_ptr == nullptr){
        char *new_str;
        new_str  = (char*)global_allocation_policy::getMemoryManager()->allocate(n + 1 * sizeof(char));
        memset(new_str, 0, n + 1);
        if(m_string_ptr != nullptr){
            memcpy(new_str, m_string_ptr, m_length);
        }
        m_string_ptr = new_str;
    }else{
        m_string_ptr[n] = '\0';
    }
    m_capacity = n; 
}
// size_t find(const string &str, size_t pos = 0) const;
size_t string::find(const string &sx, size_t pos) const{
    if(pos >= m_length){
        return (size_t)-1;
    }
    int their_length = sx.m_length;
    size_t i = pos;
    while(i < m_length){
        if(m_length - i >= their_length && compare(sx, i, their_length) == 0){
            return i;
        }
        i++;
    }
    return  (size_t)-1;
}
// size_t find(const char *str, size_t pos = 0) const;
size_t string::find(const char *sx, size_t pos) const{
    return find(string(sx), pos);
}
// size_t find(const char ch, size_t pos = 0) const;
size_t string::find(const char ch, size_t pos) const{
    if(pos >= m_length){
        return (size_t)-1;
    }
    size_t i = pos;
    while(i < m_length){
        if(m_string_ptr[i] == ch){
            return i;
        }
        i++;
    }
    return  (size_t)-1;
}
// string substr(size_t pos = 0, size_t len = (size_t)(-1)) const;
string string::substr(size_t pos, size_t len) const{
    if(pos >= m_length){
        return string();
    }
    if(len == (size_t)(-1)){
        len = m_length - pos;
    }
    if(pos + len > m_length){
        len = m_length - pos;
    }
    string s;
    s.reserve(len);
    s.assign(m_string_ptr + pos, len);
    return s;
}

// void assign(const string &str, size_t len = (size_t)(-1));
void string::assign(const string &sx, size_t len){
    if(len == (size_t)(-1)){
        len = sx.m_length;
    }
    reserve(len);
    m_length = len;
    memcpy(this->m_string_ptr, sx.m_string_ptr, len);
}
// void assign(const char *str, size_t len = (size_t)(-1));
void string::assign(const char *sx, size_t len){
    if(len == (size_t)(-1)){
        len = strlen(sx);
    }
    reserve(len);
    m_length = len;
    memcpy(this->m_string_ptr, sx, len);
}

// void assign(const char ch, size_t len = (size_t)(-1));
void string::assign(const char ch, size_t len){
    if(len == (size_t)(-1)){
        len = 1;
    }
    reserve(len);
    m_length = len;
    memset(this->m_string_ptr, ch, len);
}
// void append(const string &str);
void string::append(const string &sx){
    if(sx.m_length > 0){
        reserve(m_length + sx.m_length);
        memcpy(this->m_string_ptr + m_length, sx.m_string_ptr, sx.m_length);
        m_length += sx.m_length;
    }
}
// void append(const char *str);
void string::append(const char *sx){
    if(sx == nullptr){
        return;
    }
    size_t len = strlen(sx);
    if(len > 0){
        reserve(m_length + len);
        memcpy(this->m_string_ptr + m_length, sx, len);
        m_length += len;
    }
}
// void append(const char ch);
void string::append(const char ch){
    if(m_capacity < 1){
        reserve(1);
    }
    if(m_length == m_capacity){
        reserve(m_capacity + 1);
    }
    m_string_ptr[m_length] = ch;
    m_length++;
}
// int compare(const string &str, size_t pos= 0) const;
int string::compare(const string &sx, size_t pos, size_t len) const{
    bool substringCompare = true;
    if(len == (size_t)(-1)){
        substringCompare = false;
    }
    len = std::min(len, (size_t)(m_length) - pos);
    len = std::min(len, (size_t)(sx.m_length));
    for(size_t i = 0; i < len; ++i){
        if(sx.m_string_ptr[i] != this->m_string_ptr[i + pos]){
            return  this->m_string_ptr[i + pos] - sx.m_string_ptr[i];
        }
    }
    if(substringCompare){
        return 0;
    }
    
    if(m_length - pos < sx.m_length){
        return 1;
    }
    if(m_length - pos > sx.m_length){
        return -1;
    }
    return 0;
}
// int compare(const char *str, size_t pos= 0) const;
int string::compare(const char *sx, size_t pos, size_t len) const{
    return compare(string(sx), pos, len);
}

char& string::operator[](size_t index){
    //, "out of range"
    assert(index < m_length);   
    return m_string_ptr[index];
}
char& string::at(size_t index) const{
    //, "out of range"
    assert(index < m_length);   
    return m_string_ptr[index];
}

string tstl::to_string(int x){
    char buf[32];
    sprintf(buf, "%d", x);
    return string(buf);
}
string tstl::to_string(double x){
    char buf[32];
    sprintf(buf, "%f", x);
    return string(buf);
}
string tstl::to_string(bool x){
    return x ? string("true") : string("false");
}
// string tree_sitter_util::to_string(const char *);
string tstl::to_string(const char *x){
    return string(x);
}
//string to_string(long long);
string tstl::to_string(long long x){
    char buf[32];
    sprintf(buf, "%lld", x);
    return string(buf);
}

long long string::tolonglong(){
    long long ans = 0;
    for(size_t i = 0; i < m_length; i++){
        //test if the char is a digit
        if(m_string_ptr[i] >= '0' && m_string_ptr[i] <= '9'){
            ans = ans * 10 + m_string_ptr[i] - '0';
        }else{
            // "not a number"
            assert(false);
        }
    }
    return ans;
}

string tstl::operator+(const string & sx, const string & sy){
    string ans(sx);
    ans.append(sy);
    return ans;
}
string tstl::operator+(const char * sx, const string & sy){
    string ans(sx);
    ans.append(sy);
    return ans;
}
string tstl::operator+(const char sx, const string & sy){
    string ans;
    ans.append(sx);
    ans.append(sy);
    return ans;
}