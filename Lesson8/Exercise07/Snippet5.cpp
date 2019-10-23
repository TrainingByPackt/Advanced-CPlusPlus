#include <vector>
#include <string>
#include <iostream>

#include "Timer.h"

using std::vector;
using std::cerr;
using std::endl;

const int N = 1000000;

void withoutReserve(vector<int> &v)
{
  TIME_IT;
  for(int i = 0; i < N; ++i)
  {
    v.push_back(i);
  } 
}

void withReserve(vector<int> &v)
{
  TIME_IT;
  v.reserve(N);
  for(int i = 0; i < N; ++i)
  {
    v.push_back(i);
  } 
}


int main()
{
  {
    vector<int> v1;
    for(int i = 0; i < 100; ++i)
    {
      withoutReserve(v1);
    }
  }
  
  {
    vector<int> v2;
    for(int i = 0; i < 100; ++i)
    {
      withReserve(v2);
    }
  }
  
  Timer::dump();
  
}

