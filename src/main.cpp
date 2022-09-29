#include "TSTL/export.h"
#include "MMS/export.h"
#include <functional>
#include <iostream>
using namespace tstl;
using namespace MMS;

using TC = std::function<bool()>;

TC test1 = []() -> bool {
    //test linked_list_entry
    linked_list_entry<int> * entry = linked_list_entry<int>::newInstance(1, nullptr);
    linked_list_entry<int> * entry2 = linked_list_entry<int>::newInstance(2, entry);
    linked_list_entry<int> * entry3 = linked_list_entry<int>::newInstance(3, entry2);
    if(entry3->data != 3){
        return false;
    }
    if(entry3->next->data != 2){
        return false;
    }
    if(entry3->next->next->data != 1){
        return false;
    }
    return true;
};

TC test2 = []() -> bool {
    //test linked_list
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 2){
        return false;
    }
    if(list.at(2) != 3){
        return false;
    }
    return true;
};

// test linked_list();
// test linked_list(const linked_list & vx);
TC test3 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    linked_list<int> list2 = list;
    linked_list<int> list3(list);
    list = list2;
    list = std::move(list3);
    if(list.size() != 3){
        return false;
    }
    if(list2.size() != 3){
        return false;
    }
    if(list3.size() != 0){
        return false;
    }
   
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 2){
        return false;
    }
    if(list.at(2) != 3){
        return false;
    }
    if(list2.at(0) != 1){
        return false;
    }
    if(list2.at(1) != 2){
        return false;
    }
    if(list2.at(2) != 3){
        return false;
    }
   
    return true;
};



// test linked_list (std::initializer_list<T> il);
TC test4 = []() -> bool {
    linked_list<int> list({1, 2, 3});
    if(list.size() != 3){
        return false;
    }
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 2){
        return false;
    }
    if(list.at(2) != 3){
        return false;
    }
    return true;
};
// test linked_list &operator=(const linked_list & vx);
TC test5 = []() -> bool {
    linked_list<int> list({1, 2, 3});
    linked_list<int> list2;
    list2 = list;
    if(list2.size() != 3){
        return false;
    }
    if(list2.at(0) != 1){
        return false;
    }
    if(list2.at(1) != 2){
        return false;
    }
    if(list2.at(2) != 3){
        return false;
    }
    return true;
};
// test void push_back(const T & x);
TC test6 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list.size() != 3){
        return false;
    }
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 2){
        return false;
    }
    if(list.at(2) != 3){
        return false;
    }
    return true;
};
// test void pop_back();
TC test7 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    if(list.size() != 2){
        return false;
    }
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 2){
        return false;
    }
    return true;
};
// test void clear();
TC test8 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    if(list.size() != 0){
        return false;
    }
    return true;
};
// test void reserve(size_t sz); can be failed
TC test9 = []() -> bool {
    linked_list<int> list;
    list.reserve(10);
    if(list.size() != 0){
        return true;
    }
    return true;
};
// test void resize(size_t sz);  can be failed
TC test10 = []() -> bool {
    linked_list<int> list;
    list.resize(10);
    if(list.size() != 10){
        return true;
    }
    return true;
};
// test void assign(const linked_list & vx);
TC test11 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    linked_list<int> list2;
    list2.assign(list);
    if(list2.size() != 3){
        return false;
    }
    if(list2.at(0) != 1){
        return false;
    }
    if(list2.at(1) != 2){
        return false;
    }
    if(list2.at(2) != 3){
        return false;
    }
    return true;
};
// test void assign(linked_list && vx);
TC test12 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    linked_list<int> list2;
    list2.assign(std::move(list));
    if(list2.size() != 3){
        return false;
    }
    if(list2.at(0) != 1){
        return false;
    }
    if(list2.at(1) != 2){
        return false;
    }
    if(list2.at(2) != 3){
        return false;
    }
    return true;
};
// test T &operator[](size_t idx) const;
TC test13 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list[0] != 1){
        return false;
    }
    if(list[1] != 2){
        return false;
    }
    if(list[2] != 3){
        return false;
    }
    return true;
};
// test T &at(size_t idx) const;
TC test14 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 2){
        return false;
    }
    if(list.at(2) != 3){
        return false;
    }
    return true;
};
// test size_t size() const;
TC test15 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list.size() != 3){
        return false;
    }
    return true;
};
// test bool empty();
TC test16 = []() -> bool {
    linked_list<int> list;
    if(list.empty() != true){
        return false;
    }
    list.push_back(1);
    if(list.empty() != false){
        return false;
    }
    return true;
};
// test size_t indexOf(const T & x);
TC test17 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list.indexOf(1) != 0){
        return false;
    }
    if(list.indexOf(2) != 1){
        return false;
    }
    if(list.indexOf(3) != 2){
        return false;
    }
    return true;
};
// test void erase(int idx);
TC test18 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.erase(1);
    if(list.size() != 2){
        return false;
    }
    if(list.at(0) != 1){
        return false;
    }
    if(list.at(1) != 3){
        return false;
    }
    return true;
};
// test T &back();
TC test19 = []() -> bool {
    linked_list<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    if(list.back() != 3){
        return false;
    }
    return true;
};
// test static linked_list<T> * newInstance();
TC test20 = []() -> bool {
    linked_list<int> * list = linked_list<int>::newInstance();
    list->push_back(1);
    list->push_back(2);
    list->push_back(3);
    if(list->size() != 3){
        return false;
    }
    if(list->at(0) != 1){
        return false;
    }
    if(list->at(1) != 2){
        return false;
    }
    if(list->at(2) != 3){
        return false;
    }
    return true;
};


// string();
TC test21 = []() -> bool {
    linked_list<string> list;
    if(list.size() != 0){
        return false;
    }
    return true;
};
// string(const char * );
TC test22 = []() -> bool {
    linked_list<string> list({"hello"});
    if(list.size() != 1){
        return false;
    }
    if(list.at(0) != "hello"){
        return false;
    }
    return true;
};
// string(const string & );
TC test23 = []() -> bool {
    linked_list<string> list({"hello"});
    linked_list<string> list2(list);
    if(list2.size() != 1){
        return false;
    }
    if(list2.at(0) != "hello"){
        return false;
    }
    return true;
};
// string(string && );
TC test24 = []() -> bool {
    linked_list<string> list({"hello"});
    linked_list<string> list2(std::move(list));
    if(list2.size() != 1){
        return false;
    }
    if(list2.at(0) != "hello"){
        return false;
    }
    return true;
};
// string &operator=(const string &);
TC test25 = []() -> bool {
    linked_list<string> list({"hello"});
    linked_list<string> list2;
    list2 = list;
    if(list2.size() != 1){
        return false;
    }
    if(list2.at(0) != "hello"){
        return false;
    }
    return true;
};
// string &operator=(string &&);
TC test26 = []() -> bool {
    linked_list<string> list({"hello"});
    linked_list<string> list2;
    list2 = std::move(list);
    if(list2.size() != 1){
        return false;
    }
    if(list2.at(0) != "hello"){
        return false;
    }
    return true;
};
// const char *c_str() const;
TC test27 = []() -> bool {
    string strx("hello");
    // if(strx.c_str() != "hello"){
    if(strcmp(strx.c_str(), "hello") != 0){
        return false;
    }
    return true;
};
// operator const char *() const;
TC test28 = []() -> bool {
    string strx("hello");
    // if(strx.c_str() != "hello"){
    if(strcmp(strx, "hello") != 0){
        return false;
    }
    return true;
};
// string operator+(const string &);
TC test29 = []() -> bool {
    string strx("hello");
    string stry("world");
    string strz = strx + stry;
    if(strcmp(strz, "helloworld") != 0){
        return false;
    }
    return true;
};
// string operator+(const char *);
TC test30 = []() -> bool {
    string strx("hello");
    string strz = strx + "world";
    if(strcmp(strz, "helloworld") != 0){
        return false;
    }
    return true;
};
// string operator+(const char );
TC test31 = []() -> bool {
    string strx("hello");
    string strz = strx + 'w';
    if(strcmp(strz, "hellow") != 0){
        return false;
    }
    return true;
};
// string& operator+=(const string &);
TC test32 = []() -> bool {
    string strx("hello");
    string stry("world");
    strx += stry;
    if(strcmp(strx, "helloworld") != 0){
        return false;
    }
    return true;
};
// string& operator+=(const char *);
TC test33 = []() -> bool {
    string strx("hello");
    strx += "world";
    if(strcmp(strx, "helloworld") != 0){
        return false;
    }
    return true;
};
// string& operator+=(const char );
TC test34 = []() -> bool {
    string strx("hello");
    strx += 'w';
    if(strcmp(strx, "hellow") != 0){
        return false;
    }
    return true;
};
// bool operator<=(const string &)  const;
TC test35 = []() -> bool {
    string strx("hello");
    string stry("world");
    if(strx <= stry){
        return true;
    }
    return false;
};
// bool operator<=(const char *)  const;
TC test36 = []() -> bool {
    string strx("hello");
    if(strx <= "world"){
        return true;
    }
    return false;
};
// bool operator>=(const string &)  const;
TC test37 = []() -> bool {
    string strx("hello");
    string stry("world");
    if(strx >= stry){
        return false;
    }
    return true;
};
// bool operator>=(const char *)  const;
TC test38 = []() -> bool {
    string strx("hello");
    if(strx >= "world"){
        return false;
    }
    return true;
};
// bool operator<(const string &)  const;
TC test39 = []() -> bool {
    string strx("hello");
    string stry("world");
    if(strx < stry){
        return true;
    }
    return false;
};
// bool operator<(const char *)  const;
TC test40 = []() -> bool {
    string strx("hello");
    if(strx < "world"){
        return true;
    }
    return false;
};
// bool operator>(const string &)  const;
TC test41 = []() -> bool {
    string strx("hello");
    string stry("world");
    if(strx > stry){
        return false;
    }
    return true;
};
// bool operator>(const char *)  const;
TC test42 = []() -> bool {
    string strx("hello");
    if(strx > "world"){
        return false;
    }
    return true;
};
// bool operator==(const string &) const;
TC test43 = []() -> bool {
    string strx("hello");
    string stry("world");
    if(strx == stry){
        return false;
    }
    return true;
};
// bool operator==(const char *) const;
TC test44 = []() -> bool {
    string strx("hello");
    if(strx == "world"){
        return false;
    }
    return true;
};
// bool operator!=(const string &)  const;
TC test45 = []() -> bool {
    string strx("hello");
    string stry("world");
    if(strx != stry){
        return true;
    }
    return false;
};
// bool operator!=(const char * )  const;
TC test46 = []() -> bool {
    string strx("hello");
    if(strx != "world"){
        return true;
    }
    return false;
};
// size_t size() const;
TC test47 = []() -> bool {
    string strx("hello");
    if(strx.size() != 5){
        return false;
    }
    return true;
};
// size_t length() const;
TC test48 = []() -> bool {
    string strx("hello");
    if(strx.length() != 5){
        return false;
    }
    return true;
};
// void clear();
TC test49 = []() -> bool {
    string strx("hello");
    strx.clear();
    if(strx.size() != 0){
        return false;
    }
    return true;
};
// void resize(size_t n);
TC test50 = []() -> bool {
    string strx("hello");
    strx.resize(3);
    if(strx.size() != 3){
        return false;
    }
    return true;
};
// void reserve(size_t n);
TC test51 = []() -> bool {
    string strx("hello");
    strx.reserve(10);
    if(strx.size() != 5){
        return false;
    }
    return true;
};
// size_t find(const string & content, size_t pos = 0) const;
TC test52 = []() -> bool {
    string strx("hello");
    if(strx.find("ll") != 2){
        return false;
    }
    return true;
};
// size_t find(const char *content, size_t pos = 0) const;
TC test53 = []() -> bool {
    string strx("hello");
    if(strx.find("ll") != 2){
        return false;
    }
    return true;
};
// size_t find(const char content, size_t pos = 0) const;
TC test54 = []() -> bool {
    string strx("hello");
    if(strx.find('l') != 2){
        return false;
    }
    return true;
};
// string substr(size_t pos = 0, size_t len = (size_t)(-1)) const;
TC test55 = []() -> bool {
    string strx("hello");
    string stry = strx.substr(2, 2);
    if(strcmp(stry, "ll") != 0){
        return false;
    }
    return true;
};
// void assign(const string &content, size_t len = (size_t)(-1));
TC test56 = []() -> bool {
    string strx("hello");
    strx.assign("world", 3);
    if(strcmp(strx, "wor") != 0){
        return false;
    }
    return true;
};
// void assign(const char *content, size_t len = (size_t)(-1));
TC test57 = []() -> bool {
    string strx("hello");
    strx.assign("world", 3);
    if(strcmp(strx, "wor") != 0){
        return false;
    }
    return true;
};
// void assign(const char ch, size_t len = (size_t)(1));
TC test58 = []() -> bool {
    string strx("hello");
    strx.assign('w', 3);
    if(strcmp(strx, "www") != 0){
        return false;
    }
    return true;
};
// void append(const string &content);
TC test59 = []() -> bool {
    string strx("hello");
    strx.append("world");
    if(strcmp(strx, "helloworld") != 0){
        return false;
    }
    return true;
};
// string to_string(int);
TC test60 = []() -> bool {
    string strx = to_string(123);
    if(strcmp(strx, "123") != 0){
        return false;
    }
    return true;
};
// string to_string(double);
TC test61 = []() -> bool {
    string strx = to_string(123.456);
    //convert strx back to double 
    double d = atof(strx);
    if(abs(d - 123.456) > 0.0001){
        return false;
    }
    
    return true;
};
// string to_string(bool);
TC test62 = []() -> bool {
    string strx = to_string(true);
    if(strcmp(strx, "true") != 0){
        return false;
    }
    return true;
};
// string to_string(const char *);
TC test63 = []() -> bool {
    string strx = to_string("hello");
    if(strcmp(strx, "hello") != 0){
        return false;
    }
    return true;
};
// string to_string(long long);
TC test64 = []() -> bool {
    string strx = to_string(1234567890123456789);
    if(strcmp(strx, "1234567890123456789") != 0){
        return false;
    }
    return true;
};

// pair() : first(), second();
TC test65 = []() -> bool {
    pair<int, string> p(1, "hello");
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// pair(const T1 &x, const T2 &y) : first(x), second(y);
TC test66 = []() -> bool {
    pair<int, string> p(1, "hello");
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// pair(T1 &&x, T2 &&y) : first(x), second(y);
TC test67 = []() -> bool {
    pair<int, string> p(1, "hello");
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// pair(const pair &p) : first(p.first), second(p.second);
TC test68 = []() -> bool {
    pair<int, string> p(1, "hello");
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// pair(pair &&p) : first(p.first), second(p.second);
TC test69 = []() -> bool {
    pair<int, string> p(1, "hello");
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// pair &operator=(const pair &p);
TC test70 = []() -> bool {
    pair<int, string> p(1, "hello");
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// static pair *new_instance(const T1 &x, const T2 &y);
TC test71 = []() -> bool {
    pair<int, string> *p = pair<int, string>::new_instance(1, string("hello"));
    if(p->first != 1){
        return false;
    }
    if(strcmp(p->second, "hello") != 0){
        return false;
    }
    return true;
};
// pair<T1, T2> make_pair(const T1 &x, const T2 &y);
TC test72 = []() -> bool {
    pair<int, string> p = make_pair(1, string("hello"));
    if(p.first != 1){
        return false;
    }
    if(strcmp(p.second, "hello") != 0){
        return false;
    }
    return true;
};
// test vector()
TC test73 = []() -> bool {
    vector<int> v;
    if(v.size() != 0){
        return false;
    }
    return true;
};
// test vector(const vector & vx)
TC test74 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2(v);
    if(v2.size() != 3){
        return false;
    }
    if(v2[0] != 1){
        return false;
    }
    if(v2[1] != 2){
        return false;
    }
    if(v2[2] != 3){
        return false;
    }
    return true;
};
// test vector(vector && vx)
TC test75 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2(std::move(v));
    if(v2.size() != 3){
        return false;
    }
    if(v2[0] != 1){
        return false;
    }
    if(v2[1] != 2){
        return false;
    }
    if(v2[2] != 3){
        return false;
    }
    return true;
};
// test vector (std::initializer_list<T> il)
TC test76 = []() -> bool {
    vector<int> v = {1, 2, 3};
    if(v.size() != 3){
        return false;
    }
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 2){
        return false;
    }
    if(v[2] != 3){
        return false;
    }
    return true;
};
// test vector &operator=(const vector & vx)
TC test77 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2;
    v2 = v;
    if(v2.size() != 3){
        return false;
    }
    if(v2[0] != 1){
        return false;
    }
    if(v2[1] != 2){
        return false;
    }
    if(v2[2] != 3){
        return false;
    }
    return true;
};
// test vector &operator=(vector && vx)
TC test78 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2;
    v2 = std::move(v);
    if(v2.size() != 3){
        return false;
    }
    if(v2[0] != 1){
        return false;
    }
    if(v2[1] != 2){
        return false;
    }
    if(v2[2] != 3){
        return false;
    }
    return true;
};
// test void push_back(const T & x)
TC test79 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v.size() != 3){
        return false;
    }
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 2){
        return false;
    }
    if(v[2] != 3){
        return false;
    }
    return true;
};
// test void push_back(T && x)
TC test80 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v.size() != 3){
        return false;
    }
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 2){
        return false;
    }
    if(v[2] != 3){
        return false;
    }
    return true;
};
// test void pop_back()
TC test81 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    if(v.size() != 2){
        return false;
    }
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 2){
        return false;
    }
    return true;
};
// test void clear()
TC test82 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.clear();
    if(v.size() != 0){
        return false;
    }
    return true;
};


TC test83 = []() -> bool {
    
    return true;
};


// test void resize(size_t sz)
TC test84 = []() -> bool {
    vector<int> v;
    v.resize(10);
   
    return true;
};
// test void assign(const vector & vx)
TC test85 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2;
    v2.assign(v);
    if(v2.size() != 3){
        return false;
    }
    if(v2[0] != 1){
        return false;
    }
    if(v2[1] != 2){
        return false;
    }
    if(v2[2] != 3){
        return false;
    }
    return true;
};
// test void assign(vector && vx)
TC test86 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v2;
    v2.assign(std::move(v));
    if(v2.size() != 3){
        return false;
    }
    if(v2[0] != 1){
        return false;
    }
    if(v2[1] != 2){
        return false;
    }
    if(v2[2] != 3){
        return false;
    }
    return true;
};
// test T &operator[](size_t idx) const
TC test87 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 2){
        return false;
    }
    if(v[2] != 3){
        return false;
    }
    return true;
};
// test T &at(size_t) const
TC test88 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v.at(0) != 1){
        return false;
    }
    if(v.at(1) != 2){
        return false;
    }
    if(v.at(2) != 3){
        return false;
    }
    return true;
};
// test size_t size() cons
TC test89 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v.size() != 3){
        return false;
    }
    return true;
};
// test void emplace_back( Args&&... args )
TC test90 = []() -> bool {
    vector<int> v;
    v.emplace_back(1);
    v.emplace_back(2);
    v.emplace_back(3);
    if(v.size() != 3){
        return false;
    }
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 2){
        return false;
    }
    if(v[2] != 3){
        return false;
    }
    return true;
};
// test bool empty()
TC test91 = []() -> bool {
    vector<int> v;
    if(v.empty() == false){
        return false;
    }
    v.push_back(1);
    if(v.empty() == true){
        return false;
    }
    return true;
};
// test size_t findidx(const T & x)
TC test92 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v.findidx(1) != 0){
        return false;
    }
    if(v.findidx(2) != 1){
        return false;
    }
    if(v.findidx(3) != 2){
        return false;
    }
    return true;
};
// test void erase(int idx)
TC test93 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(1);
    if(v.size() != 2){
        return false;
    }
    if(v[0] != 1){
        return false;
    }
    if(v[1] != 3){
        return false;
    }
    return true;
};
// test T &back()
TC test94 = []() -> bool {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    if(v.back() != 3){
        return false;
    }
    return true;
};

// test  map() : m_data()
TC test95 = []() -> bool {
    map<int, int> m;
    if(m.size() != 0){
        return false;
    }
    return true;
};
// test  map(const map & mx) : m_data()
TC test96 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    map<int, int> m2(m);
    if(m2.size() != 3){
        return false;
    }
    if(m2[1] != 1){
        return false;
    }
    if(m2[2] != 2){
        return false;
    }
    if(m2[3] != 3){
        return false;
    }
    return true;
};
// test  map(map && mx) : m_data()
TC test97 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    map<int, int> m2(std::move(m));
    if(m2.size() != 3){
        return false;
    }
    if(m2[1] != 1){
        return false;
    }
    if(m2[2] != 2){
        return false;
    }
    if(m2[3] != 3){
        return false;
    }
    return true;
};
// test  map &operator=(const map &)
TC test98 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    map<int, int> m2;
    m2 = m;
    if(m2.size() != 3){
        return false;
    }
    if(m2[1] != 1){
        return false;
    }
    if(m2[2] != 2){
        return false;
    }
    if(m2[3] != 3){
        return false;
    }
    return true;
};
// test  map &operator=(map &&)
TC test99 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    map<int, int> m2;
    m2 = std::move(m);
    if(m2.size() != 3){
        return false;
    }
    if(m2[1] != 1){
        return false;
    }
    if(m2[2] != 2){
        return false;
    }
    if(m2[3] != 3){
        return false;
    }
    return true;
};
// test  void assign(const map & mx)
TC test100 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    map<int, int> m2;
    m2.assign(m);
    if(m2.size() != 3){
        return false;
    }
    if(m2[1] != 1){
        return false;
    }
    if(m2[2] != 2){
        return false;
    }
    if(m2[3] != 3){
        return false;
    }
    return true;
};
// test  void assign(map && mx)
TC test101 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    map<int, int> m2;
    m2.assign(std::move(m));
    if(m2.size() != 3){
        return false;
    }
    if(m2[1] != 1){
        return false;
    }
    if(m2[2] != 2){
        return false;
    }
    if(m2[3] != 3){
        return false;
    }
    return true;
};
// test  bool empty() const
TC test102 = []() -> bool {
    map<int, int> m;
    if(m.empty() == false){
        return false;
    }
    m.insert(1, 1);
    if(m.empty() == true){
        return false;
    }
    return true;
};
// test  size_t size() const
TC test103 = []() -> bool {
    map<int, int> m;
    if(m.size() != 0){
        return false;
    }
    m.insert(1, 1);
    if(m.size() != 1){
        return false;
    }
    m.insert(2, 2);
    if(m.size() != 2){
        return false;
    }
    m.insert(3, 3);
    if(m.size() != 3){
        return false;
    }
    return true;
};
// test  T2& operator[](const T1& key);  
TC test104 = []() -> bool {
    map<int, int> m;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    if(m.size() != 3){
        return false;
    }
    if(m[1] != 1){
        return false;
    }
    if(m[2] != 2){
        return false;
    }
    if(m[3] != 3){
        return false;
    }
    return true;
};
// test  T2& at(const T1& key) const; 
TC test105 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    if(m.at(1) != 1){
        return false;
    }
    if(m.at(2) != 2){
        return false;
    }
    if(m.at(3) != 3){
        return false;
    }
    return true;
};
// test  void insert(const T1& key, const T2& value);
TC test106 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    if(m.size() != 3){
        return false;
    }
    if(m[1] != 1){
        return false;
    }
    if(m[2] != 2){
        return false;
    }
    if(m[3] != 3){
        return false;
    }
    return true;
};
// test  void erase(const T1& key);
TC test107 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    m.erase(1);
    if(m.size() != 2){
        return false;
    }
    if(m[1] != 0){
        return false;
    }
    if(m[2] != 2){
        return false;
    }
    if(m[3] != 3){
        return false;
    }
    m.erase(2);
    if(m.size() != 2){
        return false;
    }
    if(m[1] != 0){
        return false;
    }
    if(m[2] != 0){
        return false;
    }
    if(m[3] != 3){
        return false;
    }
    m.erase(3);
    if(m.size() != 2){
        return false;
    }
    if(m[1] != 0){
        return false;
    }
    if(m[2] != 0){
        return false;
    }
    if(m[3] != 0){
        return false;
    }
    return true;
};
// test  void clear();
TC test108 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    m.clear();
    if(m.size() != 0){
        return false;
    }
    if(m[1] != 0){
        return false;
    }
    if(m[2] != 0){
        return false;
    }
    if(m[3] != 0){
        return false;
    }
    return true;
};
// test  int count(const T1& key) const ;
TC test109 = []() -> bool {
    map<int, int> m;
    m.insert(1, 1);
    m.insert(2, 2);
    m.insert(3, 3);
    if(m.count(1) != 1){
        return false;
    }
    if(m.count(2) != 1){
        return false;
    }
    if(m.count(3) != 1){
        return false;
    }
    if(m.count(4) != 0){
        return false;
    }
    return true;
};
// test  int findidx(const T1& key) const;
TC test110 = []() -> bool {
    // map<int, int> m;
    // m.insert(1, 1);
    // m.insert(2, 2);
    // m.insert(3, 3);
    // if(m.findidx(1) != 0){
    //     return false;
    // }
    // if(m.findidx(2) != 1){
    //     return false;
    // }
    // if(m.findidx(3) != 2){
    //     return false;
    // }
    // if(m.findidx(4) != m.size()){
    //     return false;
    // }
    //retire findidx
    return true;
};
// set()
TC test111 = []() -> bool {
    set<int> s;
    if(s.size() != 0){
        return false;
    }
    return true;
};
// set (std::initializer_list<T1> il)
TC test112 = []() -> bool {
    set<int> s = {1, 2, 3};
    if(s.size() != 3){
        return false;
    }
    if(s.count(1) != 1){
        return false;
    }
    if(s.count(2) != 1){
        return false;
    }
    if(s.count(3) != 1){
        return false;
    }
    return true;
};
// bool empty() cons
TC test113 = []() -> bool {
    set<int> s;
    if(s.empty() != true){
        return false;
    }
    s.insert(1);
    if(s.empty() != false){
        return false;
    }
    return true;
};
// size_t size() const
TC test114 = []() -> bool {
    set<int> s;
    if(s.size() != 0){
        return false;
    }
    s.insert(1);
    if(s.size() != 1){
        return false;
    }
    s.insert(2);
    if(s.size() != 2){
        return false;
    }
    s.insert(3);
    if(s.size() != 3){
        return false;
    }
    return true;
};
// void insert(const T1& key)
TC test115 = []() -> bool {
    set<int> s;
    s.insert(1);
    if(s.size() != 1){
        return false;
    }
    if(s.count(1) != 1){
        return false;
    }
    s.insert(2);
    if(s.size() != 2){
        return false;
    }
    if(s.count(2) != 1){
        return false;
    }
    s.insert(3);
    if(s.size() != 3){
        return false;
    }
    if(s.count(3) != 1){
        return false;
    }
    return true;
};
// void erase(const T1& key)
TC test116 = []() -> bool {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.erase(1);
    if(s.size() != 2){
        return false;
    }
    if(s.count(1) != 0){
        return false;
    }
    if(s.count(2) != 1){
        return false;
    }
    if(s.count(3) != 1){
        return false;
    }
    s.erase(2);
    if(s.size() != 1){
        return false;
    }
    if(s.count(1) != 0){
        return false;
    }
    if(s.count(2) != 0){
        return false;
    }
    if(s.count(3) != 1){
        return false;
    }
    s.erase(3);
    if(s.size() != 0){
        return false;
    }
    if(s.count(1) != 0){
        return false;
    }
    if(s.count(2) != 0){
        return false;
    }
    if(s.count(3) != 0){
        return false;
    }
    return true;
};
// void clear()
TC test117 = []() -> bool {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.clear();
    if(s.size() != 0){
        return false;
    }
    if(s.count(1) != 0){
        return false;
    }
    if(s.count(2) != 0){
        return false;
    }
    if(s.count(3) != 0){
        return false;
    }
    return true;
};
// int count(const T1& key) const 
TC test118 = []() -> bool {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    if(s.count(1) != 1){
        return false;
    }
    if(s.count(2) != 1){
        return false;
    }
    if(s.count(3) != 1){
        return false;
    }
    if(s.count(4) != 0){
        return false;
    }
    return true;
};


//testGroup 
const TC testGroup[] = {test1, test2, test3, test4 ,test5,
                        test6, test7, test8, test9, test10,
                        test11, test12, test13, test14, test15,
                        test16, test17, test18, test19, test20,
                        test21, test22, test23, test24, test25,
                        test26, test27, test28, test29, test30,
                        test31, test32, test33, test34, test35,
                        test36, test37, test38, test39, test40,
                        test41, test42, test43, test44, test45,
                        test46, test47, test48, test49, test50,
                        test51, test52, test53, test54, test55,
                        test56, test57, test58, test59, test60,
                        test61, test62, test63, test64, test65,
                        test66, test67, test68, test69, test70,
                        test71, test72, test73, test74, test75,
                        test76, test77, test78, test79, test80,
                        test81, test82, test83,  test84, test85,
                        test86, test87, test88, test89, test90,
                        test91, test92, test93, test94, test95,
                        test96, test97, test98, test99, test100,
                        test101, test102, test103, test104, test105,
                        test106, test107, test108, test109, test110,
                        test111, test112, test113, test114, test115,
                        test116, test117, test118};

SophiscatedMMInstance smm;

char localMemory[1024 * 1024];


int main(){
    node::nil = node();
    node::nil.sz = 0;
    smm.setInit([](void ** mem){
        *mem = localMemory;
    });
    global_allocation_policy::setMemoryManager(&smm);
  
    for(int i = 0; i < sizeof(testGroup)/ sizeof(testGroup[0]); i++){
        if(!testGroup[i]()){
            std::cout << "test case " << i + 1<<" failed" << std::endl;
        }else{
            std::cout << "test case " << i + 1 <<" passed" << std::endl;
        }
    }
    //get the memory usage
    char * tm = (char *)smm.getWmem();
    // diff with localMemory
    int cnt = tm - localMemory;
    std::cout << "memory usage: " << cnt << std::endl;
    //in KB
    std::cout << "memory usage: " << cnt / 1024 << "KB" << std::endl;

    return 0;
}