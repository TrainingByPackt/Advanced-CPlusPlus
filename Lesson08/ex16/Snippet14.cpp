#include <string>
#include <cctype>

int wordCount(const std::string &s)
{
  int count = 0;
  for(int i = 0, j = 1; i < s.size() - 1; ++i, ++j)
  {
    if(!isspace(s[i]) && isspace(s[j]))
    {
      ++count;
    }
  }
    
  return count;
}
