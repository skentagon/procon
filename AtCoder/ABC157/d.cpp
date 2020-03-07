
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
  ll n,m,k;cn(n,m,k)
  vector<vector<int>> fr(n);
  vector<int> gr(n,-1);
  vector<int> frcnt(n,0);
  vector<int> grcnt(n,0);
  vector<int> blcnt(n,0);
  
  rep(i,m){
    ll a,b;cn(a,b)
    --a;--b;
    fr[a].push_back(b);
    fr[b].push_back(a);
    ++frcnt[a];
    ++frcnt[b];
  }
  int g = 0;
  rep(i,n){
    if (gr[i]<0){
      queue<int> q;q.push(i);
      while(!q.empty()){
        if (gr[q.front()] == g){
          q.pop();
          continue;
        }
        gr[q.front()] = g;
        rpv(fr[q.front()]){if (gr[v]!=g)q.push(v);}
        q.pop();
        ++grcnt[g];
      }
      ++g;
    }
  }
  rep(i,k){
    int a,b;cn(a,b)
    --a;--b;
    if (gr[a]==gr[b]){
      ++blcnt[a];
      ++blcnt[b];
    }
  }
  rep(i,n){
    //cout << "#" << i << " : " << gr[i] << " , " << grcnt[gr[i]] << " , " << blcnt[i] << endl;
    cout << grcnt[gr[i]]-frcnt[i]-blcnt[i]-1;
    if (i<n-1)cout << " ";
  }
  cout << endl;
}