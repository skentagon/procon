
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

const ll mod = 1000000007ll;

ll inv(ll a){
  ll b = mod, u = 1, v = 0;
  while(b) {
    ll t = a / b % mod;
    a -= t * b; a %=mod; std::swap(a,b);
    u -= t * v; std::swap(u,v);
  }
  u %= mod;
  if(u<0)u+=mod;
  return u;
}

ll powll( ll a, ll b ){
  ll ans = 1;
  ll t = a;
  ll c = b;
  while(true){
    if (c&0x01){
      ans = (ans*t)%mod;
    }
    t = (t*t)%mod;
    c>>=1;
    if (!c)break;
  }
  return ans;
}

ll c(ll n,ll k){
  ll a =1, b=1, c=1;
  rep(i,n)a=(a*(n-i))%mod;
  rep(i,n-k)b=(b*(n-k-i))%mod;
  rep(i,k)c=(c*(k-i))%mod;
  //co(a," ",b," ",c)
  //co(a*powll(a,mod-2))
  return (a*powll(b*c,mod-2))%mod;
}

int main(){
  ll n,a,b;cn(n,a,b)
  ll ans = powll(2,n)-1-c(n,a)-c(n,b);
  co((ans+mod*2)%mod)
}