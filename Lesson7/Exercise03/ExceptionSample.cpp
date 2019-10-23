#include<iostream>
#include<cstring>

using std::cout;
using std::endl;

bool checkValidIp(const char * ip){
    try{
        if(ip == NULL)
            throw ("ip is NULL");

        if(strlen(ip) > 15)
            throw int(strlen(ip));
    }
    catch(const char * str){
        cout << "Error in checkValidIp :"<< str << endl;
        return false;
    }
    catch(int len){
        cout << "Error in checkValidIp, ip len:" << len <<" greater than 15 characters, condition fail" << endl;
        return false;
    }

    cout << "strlen: " << strlen(ip) << endl;
    return true;
}

int main(){
    const char * ip;
    ip = "111.111.111.111";
    //ip = NULL;
    //ip = "111.111.111.11111";

    if (checkValidIp(ip)) 
        cout << "IP address is correctly validated" << endl;
    else {
        /// work on error condition 
        // if needed exit program gracefully.
        return -1;
    }
    return 0;
}
