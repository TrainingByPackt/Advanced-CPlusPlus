#include<iostream>
#include<cassert>
#include<cstring>

using std::cout;
using std::endl;

bool checkValidIp(const char * ip){
    assert(ip != NULL);
    assert(strlen(ip) < 16);
    cout << "strlen: " << strlen(ip) << endl;
    return true;
}

int main(){
    const char * ip;
    //ip = "111.111.111.111";
    //ip = NULL;
    ip = "111.111.111.11111";
    bool check = checkValidIp(ip);
    cout << " IP address is validated as :" << (check ? "true" : "false") << endl;
    return 0;
}
