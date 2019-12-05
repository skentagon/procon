
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
  int n,m;cn(n,m)
  vector<vector<bool>> d(n,vector<bool>(n,true));
  rep(i,m){
    int x,y;cn(x,y)
    d[x-1][y-1]=false;
  }
  int t = pow(2,n)-1;
  int ans = 1;
  for( int i=t; 2<i; --i ){
    bool sw = true;
    for( int x=0; x<n; ++x ){
      if ( !( (i>>x)&0x01 ) )continue;
      for( int y=x+1; y<n; ++y ){
        if ( !( (i>>y)&0x01 ) )continue;
        if ( d[x][y] ){
          sw = false;
          break;
        }
      }
      if (!sw)break;
    }
    if(sw){
      int bits = i;
      bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
      bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
      bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
      bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
      bits = (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
      ans = max( ans, bits );
      //co(i)
    }
  }
  co(ans)
}