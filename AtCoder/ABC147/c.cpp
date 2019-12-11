
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
  vector<vector<int>> d(n,vector<int>(n,-1));
  rpv(d){
    int t;cn(t);
    rep(i,t){
      int x,y;cn(x,y)
      v[x-1]=y;
    }
  }
  int ans = 0;
  for( int i=1; i<(1<<n); ++i ){
    bool sw = true;
    int mn = 0;
    rep(j,n){
      if ( (i>>j)&0x01 ){
        ++mn;
        rep( k, n ){
          //if (j==k)continue;
          if ( (( ((i>>k)&0x01) == 0 )&&( d[j][k]==1 )) || ( ((i>>k)&0x01) )&&( d[j][k]==0 ) ){
            sw = false;
            break;
          }
        }
      }
      if(!sw)break;
    }
    if(sw){
      ans=max(ans,mn);
    }
  }
  co(ans)
}