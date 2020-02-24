
#ifndef SKENTAGON_UTILITY_POW_HEADER_INCLUDED
#define SKENTAGON_UTILITY_POW_HEADER_INCLUDED

#include <initializer_list>
#include <memory>
#include <cstddef>

namespace skentagon::util {
  
  int getDiget(long long p, int base = 10){
    long long t = p;
    int ans = 1;
    while(t/=base)++ans;
    return ans;
  }

  template<size_t base>
  class powt {
    public:
      powt( size_t m );
    private:
      std::vector<long long>
  }

}

#endif