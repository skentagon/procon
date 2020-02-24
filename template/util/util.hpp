
#ifndef SKENTAGON_UTILITY_HEADER_INCLUDED
#define SKENTAGON_UTILITY_HEADER_INCLUDED

#include <initializer_list>
#include <memory>
#include <cstddef>

namespace skentagon {
  //sizeOfArray
  template<class T, std::size_t SIZE>
  inline std::size_t sizeOfArray( const T (&a)[SIZE] ){return SIZE;}

}

#endif