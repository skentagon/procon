
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpi(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#if __cplusplus < 201703L
  std::ostream& co_(){ return std::cout << std::endl; }
  std::istream& cn_(){ return std::cin; }
  template<class Head, class... Args>
  std::ostream& co_( Head&& head, Args&&... args ){ std::cout << head; return co_(std::forward<Args>(args)...); }
  template<class Head, class... Args>
  std::istream& cn_( Head&& head, Args&&... args ){ std::cin >> head; return cn_(std::forward<Args>(args)...); }
#else
  template<class... Args>
  std::ostream& co_( Args... args ){ return std::cout << ... << args << std::endl; }
  template<class... Args>
  std::istream& cn_( Args... args ){ return std::cin >> ... >> args; }
#endif
#define co(...) co_(__VA_ARGS__);
#define cn(...) cn_(__VA_ARGS__);
#define all(x) (x).begin(), (x).end()
#define rgt(x,i) (x).begin(), (x).begin()+(i)

const ll mod = 1000000007;

ll fact( ll p ){
  ll ans = 1;
  for( ll i=1; i<=p; ++i ){ ans *= i; ans %= mod; }
  return ans;
}

ll inv( ll p ){
  ll a = p, b = mod, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; std::swap(a,b);
    u -= t * v; std::swap(u,v);
  }
  u %= mod;
  if(u<0)u+=mod;
  return u;
}

int main(){
  int r,c,x,y,d,l;cn(r,c,x,y,d,l)
  ll ans = fact(x*y);
  ll t = fact(d) * fact(l) & mod;
  if ( x*y != d+l ){
    t = t * fact(x*y-d-l) % mod;
  }
  co(ans)
  ans = ans * inv(t) % mod;
  co(ans)
  ans = ans * (r-x+1) % mod;
  ans = ans * (c-y+1) % mod;
  co(ans)
}