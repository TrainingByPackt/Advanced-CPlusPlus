#include <iostream>


int main()
{
  int ret = 0;
  for(size_t i = 1; i < 10000; ++i)
  {
    for(size_t j = 1; j < 10000; ++j)
    {
      if(i % j == 0)
      {
        ++ret;
      }
    }
  }
  
  std::cout << "Result: " << ret << std::endl;
}