
#include "template.cpp"

//mod
const ll MOD = 1e9+7;
//const ll MOD = 998244353;

namespace skentagon::util {
  template <class T>
  #if __cplusplus > 201709L
  concept bool class_mod = requires( T a, T b ){
    a+b;
    a-b;
    a*b;
    a/b;
    a%b;
    a>>1;
  }
  #endif
  class mod {
    public:
      mod( const T& t = 0, const T& mod = 1e9+7 ) value(t) mod(mod) : {}
      mod& operator+=( const mod& rhs ){ value = (value+rhs) % mod; return *this;}
      mod& operator-=( const mod& rhs ){ value = (value-rhs) % mod; if(value<0)value+=mod; return *this; }
      template <class T1>
      const mod& operator^( const T1& rhs ){
        T res = 1, a = lhs.value, n = rhs.value;
        while( 0 < n ){
          if ( n&1 ){ res = res * a % mod; }
          a = a * a % mod;
          n >>= 1;
        }
        return std::move( mod<T>(res,mod) );
      }
      const mod& inv(){
        T a = 1, b = mod, u = 1, v = 0;
        while(b) {
          mod t( a / b, mod );
          a -= t * b; std::swap(a,b);
          u -= t * v; std::swap(u,v);
        }
        u %= m;
        if(u<0)u+=m;
        return std::move( mod(u,mod) );
      }
      void setMod( const T& mod ){ this->mod = mod; }
    private:
      T value;
      static T mod = 1e9+7;
  };
  template <class T>
  const mod<T>& operator^( const mod<T>& lhs, const mod<T>& rhs ){
    T res = 1, a = lhs.value, n = rhs.value;
    while( 0 < n ){
      if ( n&1 ){ res = res * a % mod; }
      a = a * a % mod;
      n >>= 1;
    }
    return std::move( mod<T>(res,mod) );
  }
}