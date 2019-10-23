#include <vector>
#include <string>
#include <iostream>
#include <random>

#include "Timer.h"

using std::vector;
using std::cerr;
using std::endl;

const uint64_t N = 100000000;

uint64_t sum1()
{
  TIME_IT;
  uint64_t ret = 0;
  for(uint64_t b=0; b < N; ++b)
  {
    if(b % 3 == 2 || b < N/2)
    {
      ret += b;
    }
  } 
  
  return ret;
}


uint64_t sum2()
{
  TIME_IT;
  uint64_t ret = 0;
  for(uint64_t b=0; b < N; ++b)
  {
    if(b < N/2 || b % 3 == 2)
    {
      ret += b;
    }
  } 
  
  return ret;
}

int main()
{
  volatile uint64_t dummy = 0;
  for(int i = 0; i < 100; ++i)
  {
    dummy = sum1();
  }

  for(int i = 0; i < 100; ++i)
  {
    dummy = sum2();
  }
 
  Timer::dump();
}

