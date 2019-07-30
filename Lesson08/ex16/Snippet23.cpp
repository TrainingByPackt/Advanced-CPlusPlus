#include <string>

#include <immintrin.h>

#include "Timer.h"

int wordCount(const std::string &s)
{
  const char *p = &s[0];
  int n = s.size() / 32;
  
  __m256i rspace = _mm256_set1_epi8(' ');
  uint64_t x, sum = 0;
  
  for(int i = 0; i < n; ++i)
  {
    __m256i r1 = _mm256_lddqu_si256((__m256i*)p);
    __m256i r2 = _mm256_lddqu_si256((__m256i*)(p+1));
    __m256i r3 = _mm256_cmpgt_epi8(r1, rspace);
    __m256i r4 = _mm256_cmpgt_epi8(r2, rspace);
    __m256i r6 = _mm256_andnot_si256(r4, r3);

    for(int i = 0; i < 4; ++i)
    {
      x = _mm256_extract_epi64(r6, i);
      sum += _mm_popcnt_u64(x);
    }
    
    p += 32;
  }

  return sum / 8;
}


