#include <string>
#include <cctype>
#include <cstring>

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

  int count = 0;
  for(int i = 0; i < s.size() - 1; ++i)
  {
    // grab the 2 bytes at s[i] as a 16 bit value
    unsigned short idx;
    memcpy(&idx, &s[i], 2);
    count += table[idx];
  }
    
  return count;
}
