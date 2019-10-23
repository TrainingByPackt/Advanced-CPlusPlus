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
  
  const char *p = s.c_str();
  return std::inner_product(p, p + s.size(), p+1, 0, std::plus<int>(), isWordEnd);
}
