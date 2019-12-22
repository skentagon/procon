
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

typedef struct {
  int x;
  int y;
  int w;
} edge;
struct {
  edge e[1000];
  bool table[1000][1000] = { { false } };
  vector<pair<int,int>> list;
} G;
typedef struct {
  bool table[20][20] = { { false } };
} type_T;
type_T T[1000];

int createGraph();

int main(){
  int n,s,k;cn(n,s,k)
  rpv(G.e){ cin >> v.x >> v.y >> v.w; }
  rpv(T){
    rep(i,19){
      int t;cn(t)
      v.table[i+1][t-1] = true;
      v.table[t-1][i+1] = true;
    }
  }
  //t = 100000;
  //printf("%d\n",createGraph());
  createGraph();
  int t = G.list.size()/2+5603;
  printf("%d\n",t);
  //printf("%d %d\n", G.list[0].first+1, G.list[0].second+1 );
  for( int i=0; i<t; ++i ){
    printf("%d %d\n", G.list[i].first+1, G.list[i].second+1 );
  }
  rpi( i, 1000 ){
    rpi( j, 20 ){
      printf("%d ",j+1);
    }
    printf("\n");
  }  
}

int createGraph(){
  int cnt = 0;
  rep(i,1000){
    for( int j=i+1; j<1000; ++j ){
      if ( (G.e[i].x-G.e[j].x)*(G.e[i].x-G.e[j].x) + (G.e[i].y-G.e[j].y)*(G.e[i].y-G.e[j].y) <= ( G.e[i].w + G.e[j].w )*( G.e[i].w + G.e[j].w ) ){
        G.table[i][j] = true;
        G.table[j][i] = true;
        G.list.push_back( make_pair(i,j) );
        ++cnt;
      }
    }
  }
  return cnt;
}