
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  ll n,m;
  cin >> n >> m;
  vector<vector<ll>> d(n,vector<ll>(n));
  rep(i,n){
    rep(j,n){ d[i][j] = i==j ? 0 : n; }
  }
  rep(i,m){
    ll t1,t2;cin >> t1 >> t2;
    d[t1-1][t2-1]=1;
    d[t2-1][t1-1]=1;
  }
  rep(k,n){
    rep(i,n){
      rep(j,n){
        if ( d[i][k] + d[k][j] < d[i][j] ){
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  ll ans = 0;
  rpv(d){ for(auto& v_:v){ ans+=v_; }}
  co(ans/2)
}