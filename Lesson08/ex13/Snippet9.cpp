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

// Size of the vector
const int SIZE = 100'000'000;

// Number of times we will access it
const int N = 100'000'000;


// Initialize a random number generator
std::random_device dev;
std::mt19937 rng(dev());

// Create a distribution range from 0 to N-1
std::uniform_int_distribution<std::mt19937::result_type> dist(0,SIZE-1); 


// Gets a pseudo random index between 0 and SIZE-1
// We multiply the given parameter by a large prime number and apply a modulus to keep it within range
// This method is often used in hash tables
uint64_t getPRIndex(uint64_t i)
{
  return (15485863 * i) % SIZE;
}

uint64_t sum1(vector<int> &v)
{
  TIME_IT;
  uint64_t sum = 0;
  for(int i = 0; i < N; ++i)
  {
    sum += v[getPRIndex(i)];
  }
  
  return sum;
}

uint64_t sum2()
{
  TIME_IT;
  uint64_t sum = 0;
  for(int i = 0; i < N; ++i)
  {
    sum += getPRIndex(i);
  }
  
  return sum;
}


int main()
{
  // Allocate SIZE integers
  std::vector<int> v(SIZE, 0);
  
  // Fill 0 to SIZE-1 values into the vector
  for(int i = 0; i < v.size(); ++i)
  {
    v[i] = i;
  }
  
  volatile uint64_t asum1 = sum1(v);
  volatile uint64_t asum2 = sum2();
  

  Timer::dump();
}

