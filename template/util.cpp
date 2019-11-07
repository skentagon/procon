
#include "template.cpp"

namespace skentagon::util {
  template<class T, std::size_t SIZE>
  inline std::size_t sizeOfArray( const T (&a)[SIZE] ){return SIZE;}
}