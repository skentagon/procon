
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
  int n,q;cn(n)
  vector<vector<int>> d(n,vector<int>(n));
  vector<vector<int>> s(n+1,vector<int>(n+1));
  rpv(d){for(auto& v_:v){cn(v_)}}
  s[0][0]=0;
  for(int i=1;i<=n;++i){
    s[i][0] = 0;
    s[0][i] = 0;
    s[i][1] = d[i-1][0] + s[i-1][1];
    s[1][i] = d[0][i-1] + s[1][i-1];
  }
  for(int x=1;x<n;++x){
    for(int y=1;y<n;++y){
      s[x+1][y+1] = d[x][y] + s[x][y+1] + s[x+1][y] - s[x][y];
    }
  }
  /*rpv(s){
    rpv(v){cout << " " << v;}
    cout << endl;
  }//*/
  cn(q)
  rep(i,q){
    int p;cn(p)
    int ans = 0;
    for( int size_x=1; size_x<=n; ++size_x ){
      int size_y = p/size_x;
      if (!size_y)break;
      rep(xbgn,n){
        rep(ybgn,n){
          int x=xbgn+size_x;if (n<=x)x=n;
          int y=ybgn+size_y;if (n<=y)y=n;
          //cout << s[x][y]+s[xbgn][ybgn]-s[x][ybgn]-s[xbgn][y] << " " << x << " " << y << " " << xbgn << " " << ybgn << " " << size_x << " "  << size_y << endl;
          ans = max(ans, s[x][y]+s[xbgn][ybgn]-s[x][ybgn]-s[xbgn][y]);
        }
      }
    }
    co(ans)
  }
}