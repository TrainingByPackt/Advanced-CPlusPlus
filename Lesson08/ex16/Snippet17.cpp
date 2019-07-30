#include <string>
#include <numeric>

int wordCount(const std::string &s)
{
  // Create a lookup table for every char
  bool table[256];
  for(int i = 0; i < 256; ++i)
  {
    table[i] = isspace((unsigned char)i) ? 1 : 0;
  }
  
  auto isWordEnd = [&](char a, char b) 
  {
    return !table[a] & table[b]; 
  };
  
  return std::inner_product(s.begin(), s.end()-1, s.begin()+1, 0, std::plus<int>(), isWordEnd);
}
