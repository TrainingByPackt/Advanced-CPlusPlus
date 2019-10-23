#include <map>
#include <string>
#include <chrono>
#include <cstdint>

class Timer
{
  static std::map<std::string, int64_t> ms_Counts;
  static std::map<std::string, int64_t> ms_Times;
  
  std::string m_sName;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_tmStart;
  
public:
  
  // When constructed, save the name and current clock time
  Timer(std::string sName);
  
  // When destroyed, add the time elapsed and also increment the count under this name
  ~Timer();
  
  // Print out the stats for each measured block/function
  static void dump();
};


// Helper macro to time functions
#define TIME_IT Timer t(__func__)

