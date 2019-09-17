#include <string>
#include <iostream>

#include <cstdint> 

#include "Timer.h"


using std::map;
using std::string;
using std::cerr;
using std::endl;


// When constructed, save the name and current clock time
Timer::Timer(string sName): m_sName(sName)
{
  m_tmStart = std::chrono::high_resolution_clock::now();
}
  
// When destroyed, add the time elapsed and also increment the count under this name
Timer::~Timer()
{
  auto tmNow = std::chrono::high_resolution_clock::now();
  auto msElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(tmNow - m_tmStart);
  
  ms_Counts[m_sName]++;
  ms_Times[m_sName] += msElapsed.count();
}
  
// Print out the stats for each measured block/function
void Timer::dump()
{
  cerr << "Name\t\t\tCount\t\t\tTime(ms)\t\tAverage(ms)\n";
  cerr << "-----------------------------------------------------------------------------------\n";
  for(const auto& it: ms_Times)
  {
    auto iCount = ms_Counts[it.first];
    cerr << it.first << "\t\t\t" << iCount << "\t\t\t" << it.second << "\t\t\t" << it.second / iCount << "\n";
  }
}


// Define static members
map<string, int64_t> Timer::ms_Counts;
map<string, int64_t> Timer::ms_Times;

