#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

#include <cstdint> 

using std::cerr;
using std::endl;



int main()
{
  // Fill 100,000,000 1s in a vector
  std::vector<int> v( 100'000'000, 1);

  // Call accumulate 100 times, accumulating to a total sum
  uint64_t total = 0;
  for(int i = 0; i < 100; ++i)
  {
    total += std::accumulate(v.begin(), v.end(), 0);
  }
  
  std::cout << "Total: " << total << std::endl;
}

