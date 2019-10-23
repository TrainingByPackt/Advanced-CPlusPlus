#include<CommonHeader.h>

// Utility function to remove spaces and tabs from start of string and end of string.. 
string trim (string &str) { // remove space and tab from string.
    string res("");
    if ((str.find(' ') != string::npos) || (str.find('\t') != string::npos)){ // if space or tab found.. 
        size_t begin, end;
        if ((begin = str.find_first_not_of(" \t")) != string::npos){ // if string is not empty.. 
            end = str.find_last_not_of(" \t");
            if ( end >= begin )
                res = str.substr(begin, end - begin + 1);
        }
    }else{
        res = str; // No space or tab found.. 
    }
    str = res;
    return res;
}

// Utility function to check if string contains only digits ( 0-9) and only single '.' 
// eg . 1121.23 , .113, 121. are valid, but 231.14.143 is not valid.
bool isAllNumbers(const string &str){ // make sure, it only contains digit and only single '.' if any 
    return ( all_of(str.begin(), str.end(), [](char c) { return ( isdigit(c) || (c == '.')); }) 
             && (count(str.begin(), str.end(), '.') <= 1) );
}

//Utility function to check if string contains only digits (0-9).. 
bool isDigit(const string &str){
    return ( all_of(str.begin(), str.end(), [](char c) { return isdigit(c); }));
}

// Utility function, where single line of file <infile> is parsed using delimiter. 
// And store the tokens in vector of string. 
void parseLine(ifstream &infile, vector<string> & vec, char delimiter){
    string line, token;

    getline(infile, line);
    istringstream ss(line);
    vec.clear();
    while(getline(ss, token, delimiter)) // break line using delimiter
        vec.push_back(token);  // store tokens in vector of string
}

// Utility function to check if vector string of 2 strings contain correct 
// currency and conversion ratio. currency should be 3 characters, conversion ratio
// should be in decimal number format. 
bool parseCurrencyParameters( vector<string> & vec){
    trim(vec[0]);  trim(vec[1]);
    return ( (!vec[0].empty()) && (vec[0].size() == 3) && (!vec[1].empty()) && (isAllNumbers(vec[1])) );
}

// Utility function, to check if vector of string has correct format for records parsed from Record File. 
// CustomerId, OrderId, ProductId, Quantity should be in integer format
// TotalPrice Regional and USD should be in decimal number format
// Currecny should be present in map. 
bool checkRecord(vector<string> &split){
    // Trim all string in vector
    for (auto &s : split)
        trim(s);
    
    if ( !(isDigit(split[0]) && isDigit(split[3]) && isDigit(split[4]) && isDigit(split[5])) ){
        cerr << "ERROR: Record with customer id:" << split[0] << " doesnt have right DIGIT parameter" << endl;
        return false;
    }

    if ( !(isAllNumbers(split[6]) && isAllNumbers(split[8])) ){
        cerr << "ERROR: Record with customer id:" << split[0] << " doesnt have right NUMBER parameter" << endl;
        return false;
    }

    if ( currencyMap.find(split[7]) == currencyMap.end() ){
        cerr << "ERROR: Record with customer id :" << split[0] << " has currency :" << split[7] << " not present in map" << endl;
        return false;
    }

    return true;
}

// Function to test initial conditions of file.. 
// Check if file is present and has correct header information. 
bool checkFile(ifstream &inFile, string &fileName, string parameter, char delimiter, string &error){
    bool flag = true;
    inFile.open(fileName);
    if ( inFile.fail() ){
        error = "Failed opening " + fileName + " file, with error: " + strerror(errno);
        flag = false;
    }
    if (flag){
        vector<string> split;
        // Parse first line as header and make sure it contains parameter as first token. 
        parseLine(inFile, split, delimiter);
        if (split.empty()){
            error = fileName + " is empty";
            flag = false;
        } else if ( split[0].find(parameter) == string::npos ){
            error = "In " + fileName + " file, first line doesnt contain header ";
            flag = false;
        }
    }   
    return flag;
}


// Function to parse Config file. Each line will have '<name> = <value> format
// Store CurrencyConversion file and Record File parameters correctly. 
bool parseConfig() {
    ifstream confFile;
    string error;
    if (!checkFile(confFile, configFile, "CONFIGURATION_FILE", '=', error)){
        cerr << "ERROR: " << error << endl;
        return false;
    }
 
    bool flag = true;
    vector<string> split;
    while (confFile.good()){
        parseLine(confFile, split, '=');
        if ( split.size() == 2 ){ 
            string name = trim(split[0]);
            string value = trim(split[1]);

            if ( name == "currencyFile" )
                currencyFile = value;
            else if ( name == "recordFile")
                recordFile = value;
        }
    }

    if ( currencyFile.empty() || recordFile.empty() ){
        cerr << "ERROR : currencyfile or recordfile not set correctly." << endl;
        flag = false;
    }

    return flag;
}

// Function to parse CurrencyConversion file and store values in Map.
bool fillCurrencyMap() {
    ifstream currFile;
    string error;
    if (!checkFile(currFile, currencyFile, "Currency", '|', error)){
        cerr << "ERROR: " << error << endl;
        return false;
    }

    bool flag = true;
    vector<string> split;
    while (currFile.good()){
        parseLine(currFile, split, '|');

        if (split.size() == 2){
            if (parseCurrencyParameters(split)){
                currencyMap[split[0]] = static_cast<float>(atof(split[1].c_str())); // make sure currency is valid.
            } else {
                cerr << "ERROR: Processing Currency Conversion file for Currency: "<< split[0] << endl;
                flag = false;
                break;
            }
        } else if (!split.empty()){
            cerr << "ERROR: Processing Currency Conversion , got incorrect parameters for Currency: " << split[0] << endl;
            flag = false;
            break;
        }
    }

    return flag;
}

// Function to parse Record File .. 
bool parseRecordFile(){
    ifstream recFile;
    string error;
    if (!checkFile(recFile, recordFile, "Customer Id", '|', error)){
        cerr << "ERROR: " << error << endl;
        return false;
    }

    bool flag = true;
    vector<string> split;
    while(recFile.good()){
        parseLine(recFile, split, '|');
        if (split.size() == 9){ 
            if (checkRecord(split)){
                vecRecord.push_back(split); //Construct struct record and save it in vector... 
            }else{
                cerr << "ERROR : Parsing Record, for Customer Id: " << split[0] << endl;
                flag = false;
                break;
            }
        } else if (!split.empty()){
            cerr << "ERROR: Processing Record, for Customer Id: " << split[0] << endl;
            flag = false;
            break;
        }
    }

    return flag;
}

void displayCurrencyMap(){
     
    cout << "Currency MAP :" << endl;
    for (auto p : currencyMap)
        cout << p.first <<"  :  " << p.second << endl;
    cout << endl;
}

ostream& operator<<(ostream& os, const record &rec){
    os << rec.customerId <<"|" << rec.firstName << "|" << rec.lastName << "|" 
       << rec.orderId << "|" << rec.productId << "|" << rec.quantity << "|" 
       << fixed << setprecision(2) << rec.totalPriceRegional << "|" << rec.currency << "|" 
       << fixed << setprecision(2) << rec.totalPriceUsd << endl;
    return os;
}


void displayRecords(){
    cout << " Displaying records with '|' delimiter" << endl;
    for (auto rec : vecRecord){
        cout << rec;
    }
    cout << endl;
}
