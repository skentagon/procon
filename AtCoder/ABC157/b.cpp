
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
  vector<vector<int>> a(3,vector<int>(3,0));
  vector<vector<bool>> m(3,vector<bool>(3,false));
  rpv(a){
    rep(i,3){cn(v[i])}
  }
  int n;cn(n)
  rep(i,n){
    int t;cn(t)
    rep(x,3){
      rep(y,3){
        if (a[x][y]==t){
          m[x][y] =true;
        }
      }
    }
  }
  rep(x,3){
    if ( (m[x][0] && m[x][1] && m[x][2]) || (m[0][x] && m[1][x] && m[2][x])){
      co("Yes");
      return 0;
    }
  }
  if ( (m[0][0] && m[1][1] && m[2][2]) || (m[0][2] && m[1][1] && m[2][0] )){
    co("Yes")
  }else{
    co("No")
  }
}