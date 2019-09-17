#include"CheckIp.h"

int main(){
    const char * ip;
    //ip = "111.111.111.111";
    ip = "111.111.111.11111";

    if (checkValidIp(ip)) 
        cout << "IP address is correctly validated" << endl;
    else {
        /// work on error condition 
        // if needed exit program gracefully.
	cout << " Got error in valid ip " << endl;
        return -1;
    }
    return 0;
}
