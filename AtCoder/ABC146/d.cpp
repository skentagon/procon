
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n;cn(n);
  vector<int> ans(n,0);
  vector<pair<int,int>> d(n-1);
  rep(i,n-1){
    int t1,t2;cin>>t1>>t2;
    d[i]=pair<int,int>{t1-1,t2-1};
    ++ans[t1-1]; ++ans[t2-1];
  }
  int t = *max_element(all(ans));
  co(t)
  vector<vector<bool>> sw(n,vector<bool>(t,true));
  rpv(d){
    rep(j,t){
      if (sw[v.first][j]&&sw[v.second][j]){
        co(j+1)
        sw[v.first][j]=false;
        sw[v.second][j]=false;
        break;
      }
    }
  }
}