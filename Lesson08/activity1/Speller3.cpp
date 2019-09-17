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

const size_t SIZE = 524287;

template<size_t SEED> size_t hasher(const string &s)
{
  size_t h = 0;
  size_t len = s.size();
  for(size_t i = 0; i < len; i++)
  {
    h = h * SEED + s[i];
  }
  return h & SIZE;
}


// This method must return a vector containing the strings in vecText that are not in vecDict
vector<int> getMisspelt(const vector<string> &vecDict, const vector<string>  &vecText)
{
  // Make an unordered_set for the set of the dict words
  unordered_set<string> setDict(vecDict.begin(), vecDict.end());
  
  // Bloom filter
  vector<bool> m_Bloom;
  
  // Add all the words to the bloom filter
  m_Bloom.resize(SIZE);
  for(auto i = vecDict.begin(); i != vecDict.end(); ++i)
  {
    m_Bloom[hasher<131>(*i)] = true;
    //m_Bloom[hasher<3131>(*i)] = true;
    //m_Bloom[hasher<31313>(*i)] = true;
    //m_Bloom[hasher<313131>(*i)] = true;
  }

  // Manually iterate through the text words and check if the word is missing in the dict
  // If so add it to result
  vector<int> ret;
  double j=0, k=0;
  for(int i = 0; i < vecText.size(); ++i)
  {
    const string &s = vecText[i];
    bool hasNoBloom = 
          !m_Bloom[hasher<131>(s)] 
      //&&  !m_Bloom[hasher<3131>(s)]
      //&&  !m_Bloom[hasher<31313>(s)]
      //&&  !m_Bloom[hasher<313131>(s)]
    ;

    if(hasNoBloom)
    {
      ++j;
      ret.push_back(i);
    }
    else if(!setDict.count(s))
    {
      ++k;
      ret.push_back(i);
    }
  }

  cerr << (100.0 * (j/(j+k))) << "% hit rate\n";
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
    copy(vecMisspelt.begin(), vecMisspelt.end(), ostream_iterator<int>(cout, "\n"));
  }
  
  Timer::dump();
}
