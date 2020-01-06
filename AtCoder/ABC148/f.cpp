
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n,u,v;
  cin >> n >> u >> v;
  --u; --v;
  vector<list<int>> node(n);
  vector<pair<int,int>> c(n,pair<int,int>(make_pair(-1,-1)));
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    --a; --b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  stack<int> stk;
  stk.push(u);
  c[u].first = 0;
  while(!stk.empty()){
    int t = stk.top(); stk.pop();
    rpv(node[t]){
      if (c[v].first == -1 ){
        stk.push(v);
        c[v].first = c[t].first + 1;
      }
    }
  }
  stk.push(v);
  c[v].second = 0;
  while(!stk.empty()){
    int t = stk.top(); stk.pop();
    rpv(node[t]){
      if (c[v].second == -1 ){
        stk.push(v);
        c[v].second = c[t].second + 1;
      }
    }
  }
  ll ans = 0;
  rpv(c){
    if (v.first < v.second){
      if (ans < v.second)ans=v.second;
    }
  }
  cout << ans-1 << endl;
}