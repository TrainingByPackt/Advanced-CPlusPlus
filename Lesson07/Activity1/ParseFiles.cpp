#include <CommonHeader.h>

// Global variables ... 
string configFile = "./parse.conf";
string recordFile;
string currencyFile;
map<string, float>  currencyMap;
vector<record>      vecRecord;


int main(){
    // Read Config file to set global configuration variables. 
    if (!parseConfig()){
        cerr << "Error parsing Config File " << endl;
        return false;
    }

    // Read Currency file and fill map
    if (!fillCurrencyMap()){
        cerr << "Error setting CurrencyConversion Map " << endl;
        return false;
    }

    if (!parseRecordFile()){
        cerr << "Error parsing Records File " << endl;
        return false;
    }
    
    displayCurrencyMap();
    displayRecords();
	return 0;
}
