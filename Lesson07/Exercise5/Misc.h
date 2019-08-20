#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<iterator>
#include<regex>

using namespace std; 

class ConnectDatabase{
    string DBname;
    string user;
    string passwd;

    public:
        ConnectDatabase() {} 
        ConnectDatabase(string _dbname, string _uname, string _passwd) :
            DBname(_dbname), user(_uname), passwd(_passwd) { }

        virtual ~ConnectDatabase() {} 
        virtual string getResult(string query);
};

class WebServerConnect{
    string Webserver;
    string uname;
    string passwd;

    public :
        WebServerConnect(string _sname, string _uname, string _passwd) :
            Webserver(_sname), uname(_uname), passwd(_passwd) { }

        virtual ~WebServerConnect() {}
        virtual string getRequest(string req);
};

class App {
    ConnectDatabase *DB;
    WebServerConnect *WB;

    public : 
        App():DB(NULL), WB(NULL) {} 
        ~App() { 
            if ( DB )  delete DB;
            if ( WB )  delete WB;
        }
        bool checkValidIp(string ip);
        string getDBResult(string query);
        string getWebResult(string query);
        void connectDB(string, string, string);
        void connectDB(ConnectDatabase *db);
        void connectWeb(string, string, string);
        void run();
};
