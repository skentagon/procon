
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

int main(){
  ll n,m;cn(n,m)
  vector<pair<ll,ll>> a(n);
  vector<pair<ll,ll>> l(m);
  vector<tuple<int,int,list<int>>> led(m);
  vector<bool> ans(m);
  rpv(a){cn(v.first,v.second)}
  sort(all(a),[](const pair<ll,ll>& a, const pair<ll,ll>& b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;
  });
  rep(i,m){
    cn(l[i].first,l[i].second)
    get<0>(led[i]) = lower_bound(all(a),make_pair(l[i].first,0ll),[](const pair<ll,ll>& a,const pair<ll,ll>& b){
      return a.first < b.first;
    }) - a.begin();
    get<1>(led[i]) = lower_bound(all(a),make_pair(l[i].second,0ll),[](const pair<ll,ll>& a,const pair<ll,ll>& b){
      return a.first < b.first;
    }) - a.begin();
  }
  sort(all(l),[](const pair<ll,ll>& a, const pair<ll,ll>& b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;
  });
  rep(i,m){
    for( ll j=i+1; j<m; ++j ){
      if (get<0>(led[j])==get<0>(led[i])){
        if (get<1>(led[j])==get<1>(led[i])){
          get<1>(led[j]) = n + 1;
          get<0>(led[j]) = n + 1;
        } else {
          get<1>(led[j]) = get<0>(led[i])+1;
          get<2>(led[j]).push_back(i);
          auto t = lower_bound(led.begin()+j+1,led.end(),led[j],[](auto& a,auto& b){
            return get<0>(a) == get<0>(b) ? get<0>(a) < get<0>(b) : get<1>(a) < get<1>(b)
          });
          led.insert(t,led[j]);
          led.erase(led.begin()+j);
        }
      }
    }
  }
  ll m_index = 0;
  while(true){
    if (get<0>(led[m_index])==i){
      ans[m_index] = a[i].second;
      ++i
    } else if (get<0>(led[m_index])>i) {
      if (a[i].second){
        co("-1")
        return 0;
      } else {
        ans[m_index] = a[i].second;
      }
    }
  }
}