#include <string>
#include <numeric>
#include <cctype>
#include <cstring>

int wordCount(const std::string &s)
{
  auto isWordEnd = [&](char a, char b) 
  {
    return a > 32 & b < 33; 
  };
  
  return std::inner_product(s.begin(), s.end()-1, s.begin()+1, 0, std::plus<int>(), isWordEnd);
}
