#include <map>
#include <string>
#include <chrono>
#include <iostream>

#include <cstdint> 

using std::map;
using std::string;
using std::cerr;
using std::endl;

class Timer
{
  static map<string, int64_t> ms_Counts;
  static map<string, int64_t> ms_Times;
  
  const string &m_sName;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_tmStart;

public:
  
  // When constructed, save the name and current clock time
  Timer(const string &sName): m_sName(sName)
  {
    m_tmStart = std::chrono::high_resolution_clock::now();
  }
  
  // When destroyed, add the time elapsed and also increment the count under this name
  ~Timer()
  {
    auto tmNow = std::chrono::high_resolution_clock::now();
    auto msElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(tmNow - m_tmStart);
    
    ms_Counts[m_sName]++;
    ms_Times[m_sName] += msElapsed.count();
  }
  
  // Print out the stats for each measured block/function
  static void dump()
  {
    cerr << "Name\t\t\tCount\t\t\tTime(ms)\t\tAverage(ms)\n";
    cerr << "-----------------------------------------------------------------------------------\n";
    for(const auto& it: ms_Times)
    {
      auto iCount = ms_Counts[it.first];
      cerr << it.first << "\t\t\t" << iCount << "\t\t\t" << it.second << "\t\t\t" << it.second / iCount << "\n";
    }
  }
};


// Define static members
map<string, int64_t> Timer::ms_Counts;
map<string, int64_t> Timer::ms_Times;

#define TIME_IT Timer t(__func__)

const int64_t N = 1'000'000'000;

unsigned int testMul()
{
  Timer t("Test Mul");
  
  unsigned int x = 1;
  for(int i = 0; i < N; ++i)
  {
    x *= i;
  }
  
  return x;
}

unsigned int testAdd()
{
  Timer t("Test Add");
  
  unsigned int x = 1;
  for(int i = 0; i < N; ++i)
  {
    x += i;
  }
  
  return x;
}


int main()
{
  volatile unsigned int dummy;
  
  for(int i = 0; i < 10; ++i)
    dummy = testAdd();
  
  for(int i = 0; i < 10; ++i)
    dummy = testMul();
  
  Timer::dump();
}
