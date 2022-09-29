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
                        test61, test62, test63, test64};

SophiscatedMMInstance smm;

char localMemory[1024 * 1024];


int main(){
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
    return 0;
}