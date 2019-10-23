#ifndef __PERSON_H__
#define __PERSON_H__

#include<string>

using std::string;

#define PERSON_LIB_VERSION 1

struct person{
    string name;
    int age;
    string address;
};

#endif
