#include<gtest/gtest.h>
#include"../CommonHeader.h"

using namespace std;

// Global variables ... 
string configFile = "./parse.conf";
string recordFile;
string currencyFile;
map<string, float>  currencyMap;
vector<record>      vecRecord;

void setDefault(){
    configFile = "./parse.conf";
    recordFile.clear();
    currencyFile.clear();
    currencyMap.clear();
    vecRecord.clear();
}

// Test Cases for trim function ... 
TEST(trim, empty){
    string str="    ";
    EXPECT_EQ(trim(str), string());
}

TEST(trim, start_space){
    string str = "  adas";
    EXPECT_EQ(trim(str), string("adas"));
}

TEST(trim, end_space){
    string str = "trip      ";
    EXPECT_EQ(trim(str), string("trip"));
}

TEST(trim, string_middle){
    string str = "       hdgf   ";
    EXPECT_EQ(trim(str), string("hdgf"));
}

TEST(trim, space_middle){
    string str = "hd  gf";
    EXPECT_EQ(trim(str), string("hd  gf"));
}

TEST(trim, single_char_start){
    string str = "c  ";
    EXPECT_EQ(trim(str), string("c"));
}

TEST(trim, single_char_end){
    string str = "   c";
    EXPECT_EQ(trim(str), string("c"));
}

TEST(trim, single_char_middle){
    string str = "      c  ";
    EXPECT_EQ(trim(str), string("c"));
}


// Test Cases for isAllNumbers function.. 
TEST(isNumber, alphabets_present){
    string str = "11.qwe13";
    ASSERT_FALSE(isAllNumbers(str));
}

TEST(isNumber, special_character_present){
    string str = "34.^%3";
    ASSERT_FALSE(isAllNumbers(str));
}

TEST(isNumber, correct_number){
    string str = "54.765";
    ASSERT_TRUE(isAllNumbers(str));
}

TEST(isNumber, decimal_begin){
    string str = ".624";
    ASSERT_TRUE(isAllNumbers(str));
}

TEST(isNumber, decimal_end){
    string str = "53.";
    ASSERT_TRUE(isAllNumbers(str));
}



// Test Cases for isDigit funtion... 
TEST(isDigit, alphabet_present){
    string str = "527A";
    ASSERT_FALSE(isDigit(str));
}

TEST(isDigit, decimal_present){
    string str = "21.55";
    ASSERT_FALSE(isDigit(str));
}

TEST(isDigit, correct_digit){
    string str = "9769";
    ASSERT_TRUE(isDigit(str));
}


// Test Cases for parseCurrencyParameters function..
TEST(CurrencyParameters, extra_currency_chararcters){
    vector<string> vec {"ASAA","34.22"};
    ASSERT_FALSE(parseCurrencyParameters(vec));
}

TEST(CurrencyParameters, correct_parameters){
    vector<string> vec {"INR","1.44"};
    ASSERT_TRUE(parseCurrencyParameters(vec));
}


//Test Cases for checkFile function...
TEST(checkFile, no_file_present){
    string fileName = "./NoFile";
    ifstream infile; 
    string parameter("nothing");
    char delimit =';';
    string err;
    ASSERT_FALSE(checkFile(infile, fileName, parameter, delimit, err));
}

TEST(checkFile, empty_file){
    string fileName = "./emptyFile";
    ifstream infile; 
    string parameter("nothing");
    char delimit =';';
    string err;
    ASSERT_FALSE(checkFile(infile, fileName, parameter, delimit, err));
}


TEST(checkFile, no_header){
    string fileName = "./noHeaderFile";
    ifstream infile; 
    string parameter("header");
    char delimit ='|';
    string err;
    ASSERT_FALSE(checkFile(infile, fileName, parameter, delimit, err));
}


TEST(checkFile, incorrect_header){
    string fileName = "./correctHeaderFile";
    ifstream infile; 
    string parameter("header");
    char delimit ='|';
    string err;
    ASSERT_FALSE(checkFile(infile, fileName, parameter, delimit, err));
}

TEST(checkFile, correct_file){
    string fileName = "./correctHeaderFile";
    ifstream infile; 
    string parameter("Currency");
    char delimit ='|';
    string err;
    ASSERT_TRUE(checkFile(infile, fileName, parameter, delimit, err));
}


//Test Cases for parseConfig function...
TEST(parseConfig, missing_currency_file){
    setDefault();
    configFile = "./parseMissingCurrency.conf";
    ASSERT_FALSE(parseConfig());
}

TEST(parseConfig, missing_record_file){
    setDefault();
    configFile = "./parseMissingRecord.conf";
    ASSERT_FALSE(parseConfig());
}

TEST(parseConfig, correct_config_file){
    setDefault();
    configFile = "./parse.conf";
    ASSERT_TRUE(parseConfig());
}


//Test Cases for fillCurrencyMap function...
TEST(fillCurrencyMap, wrong_delimiter){
    currencyFile = "./CurrencyWrongDelimiter.txt";
    ASSERT_FALSE(fillCurrencyMap());
}

TEST(fillCurrencyMap, extra_column){
    currencyFile = "./CurrencyExtraColumn.txt";
    ASSERT_FALSE(fillCurrencyMap());
}

TEST(fillCurrencyMap, correct_file){
    currencyFile = "./CurrencyConversion.txt";
    ASSERT_TRUE(fillCurrencyMap());
}


//Test Cases for parseRecordFile function...
TEST(parseRecordFile, wrong_delimiter){
    recordFile = "./RecordWrongDelimiter.txt";
    ASSERT_FALSE(parseRecordFile());
}

TEST(parseRecordFile, extra_column){
    recordFile = "./RecordExtraColumn.txt";
    ASSERT_FALSE(parseRecordFile());
}

TEST(parseRecordFile, correct_file){
    recordFile = "./RecordFile.txt";
    ASSERT_TRUE(parseRecordFile());
}
