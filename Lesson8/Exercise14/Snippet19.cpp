#include <string>
#include <numeric>
#include <cctype>
#include <cstring>

int wordCount(const std::string &s)
{
  auto isWordStart = [&](char a, char b) 
  {
    return a < 33 & b > 32; 
  };
  
  // Count the first word if any
  int count = s[0] > 32;
  
  // count the remaining
  return std::inner_product(s.begin(), s.end()-1, s.begin()+1, count, std::plus<int>(), isWordStart);
}
