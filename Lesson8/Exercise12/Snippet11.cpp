#include <string>
#include <iostream>
#include <random>

#include "Timer.h"

using std::string;
using std::cerr;
using std::endl;

// Size of the vector
const int N = 10'000'000;

const char* fruits[] = 
  {"apple", "banana", "cherry", "durian", "guava", "jackfruit", "kumquat", "mango", "orange", "pear"}; 


uint64_t fun1()
{
  TIME_IT;
  uint64_t sum = 0;
  string s1;
  for(uint64_t i = 0; i < N; ++i)
  {
    s1 = fruits[i % 10];
    for(int k = 0; k < s1.size(); ++k) sum += s1[k];
  }
  
  return sum;
}

uint64_t fun2()
{
  TIME_IT;
  uint64_t sum = 0;
  char s1[32];
  
  for(uint64_t i = 0; i < N; ++i)
  {
    char *ps1 = s1;
    const char *p1 = fruits[i % 10];
    do { *ps1++ = *p1; } while(*p1++);
    for(ps1 = s1; *ps1; ++ps1) sum += *ps1;
  }

  return sum;
}


int main()
{
  for(int i = 0; i < 10; ++i)
  {
    volatile uint64_t asum1 = fun1();
    volatile uint64_t asum2 = fun2();  
  }
  
  Timer::dump();
  
}

