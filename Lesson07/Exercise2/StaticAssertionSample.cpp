#include<iostream>
#include"PersonLibrary.h"

void doSanityCheck(){
    static_assert(PERSON_LIB_VERSION > 1 , "PERSON LIBRARY VERSION not greater than 1");
    // Do any more sanity check before starting app ... 
}

int main(){
    doSanityCheck();
    return 0;
}
