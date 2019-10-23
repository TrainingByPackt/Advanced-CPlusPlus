#include"CheckIp.h"
#include<string>
#include<sstream>
#include<vector>
#include<iterator>
#include<regex>

bool checkValidIp(const char * ip){
    if(ip == NULL){
	    cout << "ERROR : IP passed is NULL " << endl;
        return false;
    }

    if(strlen(ip) > 15){
	    cout << "ERROR : IP size is greater than 15" <<endl;
        return false;
    }

    //check if last character in ip is not '.' as that is not captured in tokenizing
    if (ip[strlen(ip)-1] == '.'){
        cout <<"ERROR : Incorrect token at end" << endl;
        return false;
    }

    istringstream istrstr(ip);
    vector<string> tokens;
    string token;
    regex expression("[^0-9]");
    smatch m;
    while( getline(istrstr, token, '.') ){
        if ( token.empty() ){
            cout << "ERROR : Got empty token " << endl;
            return false;
        } 
        if ( token.find(' ') != string::npos){
            cout << "ERROR : Space character in token " << endl;
            return false;
        } 
        if ( regex_search(token, m, expression) ){
            cout << "ERROR : NonDigit character in token " << endl;
            return false;
        }
        int val = atoi(token.c_str());
        if ( val < 0 || val > 255 ){
            cout << "ERROR : Invalid Digit in token " << endl;
            return false;
        }
	        tokens.push_back(token);
    }

    if ( tokens.size() != 4 ){
        cout << " ERROR : Incorect IP tokens used" << endl;
        return false;
    }

    cout << "strlen: " << strlen(ip) << endl;
    return true;
}

