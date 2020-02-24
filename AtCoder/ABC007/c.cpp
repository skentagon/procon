
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
  int r,c,sx,sy,gx,gy;
  cn(r,c,sx,sy,gx,gy)
  vector<vector<char>> map(r,vector<char>(c));
  rpv(map){rep(i,c){cn(v[i])}}
  queue<tuple<int,int,int>> q;
  q.push(make_tuple(sx-1,sy-1,1));
  map[sx-1][sy-1] = '#';
  while(!q.empty()){
    int tx[] = { 1, 0, -1, 0 };
    int ty[] = { 0, 1, 0, -1 };
    rep(i,4){
      int x = get<0>(q.front()) + tx[i];
      int y = get<1>(q.front()) + ty[i];
      if ( x == gx-1 && y == gy-1 ){
        co(get<2>(q.front()))
        exit(EXIT_SUCCESS);
      }
      if (map[x][y]=='.'){
        q.push(make_tuple(x,y,get<2>(q.front())+1));
        map[x][y] = '#';
      }
    }
    q.pop();
  }
}