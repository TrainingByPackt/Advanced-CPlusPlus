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
  for(int i = 0; i < N; ++i)
  {
    for(int j = 0; j < 100; ++j)
    {
      ret += i ^ j;
    }
  } 
  
  return ret;
}


uint64_t sum2()
{
  TIME_IT;
  uint64_t ret = 0;
  for(int i = 0; i < 100; ++i)
  {
    for(int j = 0; j < N; ++j)
    {
      ret += i ^ j;
    }
  } 
  
  return ret;
}


int main()
{
  volatile uint64_t dummy;
  dummy = sum1();
  dummy = sum2();
  Timer::dump();
}

