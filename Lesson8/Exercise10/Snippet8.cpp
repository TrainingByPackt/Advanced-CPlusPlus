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

const int N = 100000;


// Initialize a random number generator
std::random_device dev;
std::mt19937 rng(dev());

// Create a distribution range from 0 to 1000
std::uniform_int_distribution<std::mt19937::result_type> dist(0,N); 


// Insert elements 0 to N into a container at random positions
template<class C> void insertRandom(C &l)
{
  // insert one element to initialize
  l.insert(l.end(), 0);
   
  for(int i = 0; i < N; ++i)
  {
    int pos = dist(rng) % l.size();
    auto it = l.begin();
    advance(it, pos);
    l.insert(it, i);
  }
}


// Insert elements 0 to N into a container at the start
template<class C> void insertStart(C &l)
{
  for(int i = 0; i < N; ++i)
  {
    l.insert(l.begin(), i);
  }
}

// Insert elements 0 to N into a container at the start
template<class C> void insertEnd(C &l)
{
  for(int i = 0; i < N; ++i)
  {
    l.insert(l.end(), i);
  }
}


int main()
{
  std::list<int> l;
  std::vector<int> v;
  
  // list
  {
    Timer t("list random");
    insertRandom(l);
  }
  
  {
    Timer t("list end");
    insertEnd(l);    
  }
  
  {
    Timer t("list start");
    insertStart(l);
  }

  // vector
  {
    Timer t("vect random");
    insertRandom(v);
  }
  
  {
    Timer t("vect end");
    insertEnd(v);    
  }
  
  {
    Timer t("vect start");
    insertStart(v);
  }
  
  cerr << endl << l.size() << endl << v.size() << endl;

  Timer::dump();
}

