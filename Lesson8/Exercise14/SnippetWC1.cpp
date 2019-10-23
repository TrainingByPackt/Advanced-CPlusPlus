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
    string sContent;
    ostringstream buf;
    ifstream ifs(argv[1]);
    
    {
      Timer t("File read");
      buf << ifs.rdbuf(); 
      
      sContent.reserve(buf.str().size() + 1);
      sContent.resize(buf.str().size());
      
      cerr << uint64_t(sContent.data()) <<  " before pb" << endl;
      sContent.push_back(' ');
      cerr << uint64_t(sContent.data()) << endl;
      
      
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
