
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
  int n;cn(n)
  vector<vector<pair<int,ll>>> d(n+1);
  rep(i,n-1){
    int a,b;ll c;
    cn(a,b,c)
    d[a].push_back(make_pair(b,c));
    d[b].push_back(make_pair(a,c));
  }
  vector<ll> dt(n+1,-1);
  int q,k;cn(q,k);
  dt[k]=0ll;
  stack<pair<int,ll>> st;
  st.push(make_pair(k,0ll));
  while(!st.empty()){
    auto v = st.top(); st.pop();
    for( auto w : d[v.first] ){
      if ( dt[w.first] < 0 ){
        dt[w.first] = v.second + w.second;
        st.push(make_pair(w.first,v.second + w.second));
      }
    }
  }
  rep(i,q){
    int x,y;cn(x,y)
    co(dt[x]+dt[y])
  }
}