#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Timer.h"

using std::string;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ostringstream;

int wordCount(const string &s);

int main(int argc, char **argv)
{
  if(argc > 1)
  {
    Timer t("|Total Time|");
    ifstream ifs(argv[1]);
    
    string sContent;
    size_t len; 
    {
      Timer t("String Alloc");
      
      // Seek to end 
      ifs.seekg(0, std::ios::end); 
      
      // Get length and allow for 1 extra character at the end
      len = ifs.tellg();
      ++len;
      
      // Pad to 32 byte boundary
      size_t rem = len % 32;
      if(rem)
      {
        len += (32 - rem);
      }
      sContent.resize(len);
    }
    
    {
      Timer t("File read");
      
      // Seek back to start and read data
      ifs.seekg(0, std::ios::beg);
      ifs.read(&sContent[0], sContent.size());
    }
    
    int wc;
    {
      Timer t("Word count");
      wc = wordCount(sContent);
    }  

    cerr << wc << endl;
  }
  
  Timer::dump();
}
