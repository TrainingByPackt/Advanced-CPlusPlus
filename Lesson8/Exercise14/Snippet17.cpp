#include <string>
#include <numeric>
#include <cctype>

int wordCount(const std::string &s)
{
  // Create a lookup table for every pair of chars
  bool table[65536];
  
  for(int i = 0; i < 256; ++i)
  {
    for(int j = 0; j < 256; ++j)
    {
      int idx = j + i * 256;
      table[idx] = !isspace(j) && isspace(i);
    }
  }
    
  auto isWordEnd = [&](char a, char b) 
  {
    unsigned idx = (unsigned)a | (((unsigned)b) << 8);
    return table[idx]; 
  };
  
  return std::inner_product(s.begin(), s.end()-1, s.begin()+1, 0, std::plus<int>(), isWordEnd);
}
