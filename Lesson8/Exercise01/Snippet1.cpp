#include <random>
#include <iostream>

int sumVector(std::vector<int> &v)
{
  int ret = 0;
  for(int i: v)
  {
    ret += i;
  }
  
  return ret;
}

int main()
{
  // Initialize a random number generator
  std::random_device dev;
  std::mt19937 rng(dev());
  
  // Create a distribution range from 0 to 1000
  std::uniform_int_distribution<std::mt19937::result_type> dist(0,1000); 

  // Fill 10000 numbers in a vector
  std::vector<int> v;
  v.reserve(10000);
  for(int i = 0; i < 10000; ++i)
  {
    v.push_back(dist(rng));
  }
  
  // Call out function 1000 times, accumulating to a total sum
  double total = 0.0;
  for(int i = 0; i < 100000; ++i)
  {
    total += sumVector(v);
  }
  
  std::cout << "Total: " << total << std::endl;
}

