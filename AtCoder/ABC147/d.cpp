
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
  int n;cn(n)
  ll ans = 0;
  vector<ll> d(60,0);
  rep(i,n){
    ll t;cn(t)
    rep(j,d.size()){
      //co(t&(0x01LL<<j))
      d[j] = d[j] ^ (t&(1ll<<j));
    }
  }
  rpv(d){ ans = ( ans + v ) % mod; }
  co(ans)
}