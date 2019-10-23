#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <iterator>
#include <set>
#include <algorithm>

#include "Timer.h"
using namespace std;

// This method must return a vector containing the strings in vecText that are not in vecDict
vector<string> getMisspelt(const vector<string> &vecDict, const vector<string> &vecText)
{
  vector<string> ret;
  return ret;
}

// Reads a file and puts each word in a vector
vector<string> readFile(const char *sFile)
{
  ifstream ifs(sFile);
  vector<string> ret{istream_iterator<string>(ifs), istream_iterator<string>()};
  return ret;
}

// Main program reads the data and checks the output against out.txt
int main()
{
  // Read data
  const vector<string> &vecText = readFile("test.txt");
  const vector<string> &vecDict = readFile("dict.txt");

  //Get the misspelt words, and time it
  vector<string> vecMisspelt;
  {
    Timer t("Spell check");
    vecMisspelt = getMisspelt(vecDict, vecText);
  }

  // Check if we have the the desired output (after getting the unique sorted words in vecMisspelt)
  const vector<string> &vecOut = readFile("out.txt");
  set<string> setTemp(vecMisspelt.begin(), vecMisspelt.end());
  if(equal(setTemp.begin(), setTemp.end(), vecOut.begin()))
  {
    cerr << "\nOutput is correct\n";
  }
  else
  {
    cerr << "\nOutput is incorrect\n";
  }
  
  Timer::dump();
}
