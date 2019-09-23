#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <iterator>
#include <set>
#include <unordered_set>
#include <algorithm>

#include "Timer.h"

using namespace std;

// This method must return a vector containing the strings in vecText that are not in vecDict
vector<int> getMisspelt(const vector<string> &vecDict, const vector<string>  &vecText)
{
  // Make an unordered_set for the set of the dict words
  unordered_set<string> setDict(vecDict.begin(), vecDict.end());

  // Manually iterate through the text words and check if the word is missing in the dict
  // If so add it to result
  vector<int> ret;
  for(int i = 0; i < vecText.size(); ++i)
  {
    const string &s = vecText[i];
    if(!setDict.count(s))
    {
      ret.push_back(i);
    }
  }
  
  return ret;
}

// Reads a file and puts each word in a vector
template<typename T>
vector<T> readFile(const char *sFile)
{
  ifstream ifs(sFile);
  vector<T> ret{istream_iterator<T>(ifs), istream_iterator<T>()};
  return ret;
}

// Main program reads the data and prints the output after sorting
int main()
{
  // Read data
  const vector<string> &vecText = readFile<string>("test.txt");
  const vector<string> &vecDict = readFile<string>("dict.txt");
  
  //Get the misspelt words, and time it
  vector<int> vecMisspelt;
  {
    Timer t("Spell check");
    vecMisspelt = getMisspelt(vecDict, vecText);
  }
  
  // Check if we have the the desired output 
  const vector<int> &vecOut = readFile<int>("out.txt");
  if(vecOut == vecMisspelt)
  {
    cerr << "\nOutput is correct\n";
  }
  else
  {
    cerr << "\nOutput is incorrect\n";
  }
  
  Timer::dump();
}
