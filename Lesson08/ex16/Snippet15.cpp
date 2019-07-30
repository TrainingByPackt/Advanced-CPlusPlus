#include <string>
#include <cctype>

int wordCount(const std::string &s)
{
  // Create a lookup table
  bool isSpace[256];
  for(int i = 0; i < 256; ++i)
  {
    isSpace[i] = isspace((unsigned char)i);
  }

  int count = 0;
  int len = s.size() - 1;
  for(int i = 0, j = 1; i < len; ++i, ++j)
  {
    count += !isSpace[s[i]] & isSpace[s[j]];
  }
    
  return count;
}
