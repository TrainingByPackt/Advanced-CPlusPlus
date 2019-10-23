#ifndef __COMMON_HEADER__H
#define __COMMON_HEADER__H
#include<iostream>
#include<cstring>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<iterator>
#include<algorithm>
#include<iomanip>

using namespace std;

// Forward declaration of global variables. 
extern string configFile;
extern string recordFile;
extern string currencyFile;
extern map<string, float> currencyMap;
struct record;
extern vector<record>      vecRecord;

//Structure to hold Record Data . 
struct record{
    int     customerId;
    string  firstName;
    string  lastName;
    int     orderId;
    int     productId;
    int     quantity;
    float   totalPriceRegional;
    string  currency;
    float   totalPriceUsd;
    
    record(vector<string> & in){
        customerId      = atoi(in[0].c_str());
        firstName       =  in[1];
        lastName        = in[2];
        orderId         = atoi(in[3].c_str());
        productId       = atoi(in[4].c_str());
        quantity        = atoi(in[5].c_str());
        totalPriceRegional = static_cast<float>(atof(in[6].c_str()));
        currency        = in[7];
        totalPriceUsd   = static_cast<float>(atof(in[8].c_str()));
    }
};


// Declaration of Utility Functions.. 
string trim (string &);
bool isAllNumbers(const string &);
bool isDigit(const string &);
void parseLine(ifstream &, vector<string> &, char);
bool checkFile(ifstream &, string &, string, char, string &);
bool parseConfig();
bool parseCurrencyParameters( vector<string> &);
bool fillCurrencyMap();
bool parseRecordFile();
bool checkRecord(vector<string> &);
void displayCurrencyMap();
ostream& operator<<(ostream &, const record &);
void displayRecords();
#endif
