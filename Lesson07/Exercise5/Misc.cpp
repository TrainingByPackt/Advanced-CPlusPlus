#include"Misc.h"
#include <unistd.h>

string ConnectDatabase::getResult(string query){
    // dummy func, need to implement.. 
    // assuming query sent to DB is success and 
    // will return some dummy string 
    return string("DB returned success");
}

string WebServerConnect::getRequest(string req){
    // dummy func, need to implement.. 
    // assume no req string is sent to webserver. .
    // its returns the result returned from server. 
    return string("Webserver returned success");
}

void App::connectDB(string dbname, string user, string passwd){
    if ( DB )
        delete DB;
    DB = new ConnectDatabase(dbname, user, passwd);
}

void App::connectDB(ConnectDatabase *db){
    if ( DB )
        delete DB;
    DB = db;
}

void App::connectWeb(string webname, string user, string passwd){
    if ( WB )
        delete WB;
    WB = new WebServerConnect(webname, user, passwd);
}

string App::getDBResult(string query){
    return DB->getResult(query);
}

string App::getWebResult(string query) {
    return WB->getRequest(query);
}

void App::run(){
    if ( (DB == NULL) || (WB == NULL) )
        return ;
    while( true ){
        // read some request to be run on web and get result. .. 
        cout << getWebResult("dummy request to webserver") << endl;;
        sleep(5);
    }
}

bool App::checkValidIp(string ip){
    if(ip.empty()){
	    cout << "ERROR : IP passed is NULL " << endl;
        return false;
    }

    if(ip.size() > 15){
	    cout << "ERROR : IP size is greater than 15" <<endl;
        return false;
    }

    //check if last character in ip is not '.' as that is not captured in tokenizing
    if (ip[ip.size()-1] == '.'){
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

    cout << "strlen: " << ip.size() << endl;
    return true;
}

