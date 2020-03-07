
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

const ll mod = 998244353;

int main(){
  ll n;cn(n)
  vector<pair<ll,ll>> x(n);
  vector<ll> ans(n+1,0);
  vector<ll> rng(n,0);
  rep(i,n){cn(x[i].first,x[i].second)}
  sort(all(x),[](pair<ll,ll>& a,pair<ll,ll>& b){return a.first<b.first;});
  rng[n-1] = n-1;
  for(ll i=n-2;i>=0;--i){
    const pair<ll,ll> p = make_pair<ll,ll>(x[i].first+x[i].second,0ll);
    auto t = lower_bound(x.begin()+(i),x.end(),p,[](const pair<ll,ll>& a,const pair<ll,ll>& b){return a.first<b.first;});
    rng[i] = min(static_cast<ll>(t-x.begin()),n-1);
    for(ll j=i;j<n;++j){
      if ( x[rng[i]].first+x[rng[i]].second < x[j].first )break;
      rng[i] = max(rng[i],rng[j]);
    }
    co(i," ",rng[i])
  }
  ans[n-1] = 2; ans[n] = 1;
  for(ll i=n-2;i>=0;--i){
    ans[i] = ( ans[i+1] + ans[rng[i]+1] ) % mod;
    co(i," ",ans[i])
  }
  co(ans[0])
}