#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#include <random>

#include "Timer.h"

using std::vector;
using std::list;
using std::cerr;
using std::endl;

const int N = 100'000'000;


// Initialize a random number generator
std::random_device dev;
std::mt19937 rng(dev());

// Create a distribution range from 1 to N-1
std::uniform_int_distribution<std::mt19937::result_type> dist(1,N-1); 


// struct
struct Data1
{
  uint64_t field1;
  uint64_t field2;
  uint64_t field3;
  uint64_t field4;
  uint64_t field5;
  uint64_t field6;
};

struct Data2
{
  vector<uint64_t> field1;
  vector<uint64_t> field2;
  vector<uint64_t> field3;

  vector<uint64_t> field4;
  vector<uint64_t> field5;
  vector<uint64_t> field6;
};

struct Sum
{
  uint64_t field1;
  uint64_t field2;
  uint64_t field3;
  Sum(): field1(), field2(), field3() {}
};

Sum sumAOS(vector<Data1> &aos)
{
  TIME_IT;
  Sum ret;
  for(int i = 0; i < N; ++i)
  {
    ret.field1 += aos[i].field1;
    ret.field2 += aos[i].field2;
    ret.field3 += aos[i].field3;
  }
  return ret;
}


Sum sumSOA(Data2 &soa)
{
  TIME_IT;
  Sum ret;
  for(int i = 0; i < N; ++i) 
  {
    ret.field1 += soa.field1[i];
    ret.field2 += soa.field2[i];
    ret.field3 += soa.field3[i];
  }
  return ret;
}

int main()
{
   vector<Data1> arrOfStruct;
   Data2 structOfArr;
   
   // Reserve space
   structOfArr.field1.reserve(N);
   structOfArr.field2.reserve(N);
   structOfArr.field3.reserve(N);
   arrOfStruct.reserve(N);

   // Fill random values
   for(int i = 0; i < N; ++i)
   {
     Data1 temp;
     temp.field1 = dist(rng);
     temp.field2  = dist(rng);
     temp.field3 = dist(rng);
     
     arrOfStruct.push_back(temp);
     
     structOfArr.field1.push_back(temp.field1);
     structOfArr.field2.push_back(temp.field2);
     structOfArr.field3.push_back(temp.field3);
   }
  
  Sum s1 = sumAOS(arrOfStruct);
  Sum s2 = sumSOA(structOfArr);
  
  Timer::dump();
}

