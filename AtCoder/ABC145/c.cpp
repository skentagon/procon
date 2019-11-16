
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n;cn(n)
  vector<pair<int,int>> d(n);
  rep(i,n){
    cin >> d[i].first >> d[i].second;
  }
  double ans = 0;
  rep(i,n){
    rep(j,n){
      ans += sqrt( ( d[i].first - d[j].first )*( d[i].first - d[j].first ) + ( d[i].second - d[j].second )*( d[i].second - d[j].second ) );
    }
  }
  cout << setw(10) << ans*2/(n*(n-1)) << endl;
}