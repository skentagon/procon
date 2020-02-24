
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

namespace skentagon::util {
  
  int getDiget(long long p, int base = 10){
    long long t = p;
    int ans = 1;
    while(t/=base)++ans;
    return ans;
  }

}


vector<ll> pow10(20);
vector<ll> pow8(18);

ll g(ll p){
  if (p%10<4){return 0;}
  if (p%10<9){return 1;}
  return 2;
}

ll f(ll p){
  ll ans = 0;
  rep(i,18){
    ans += g((p/pow10[i+1])%10) * pow10[i+1] + (p/pow10[i+1])%10*pow10[i];
    co(ans," ",pow10[i]," ",p, " ", (p/pow10[i])%10)
    p%=pow10[17-i];
  }
  return ans;
}

int main(){
  pow10.resize(20); pow10[0] = 0; pow10[1] = 1;
  rep(i,17){
    pow10[i+2] = 10 * pow10[i];
  }
  ll a,b;cn(a,b)
  co(f(b)-f(a));
}