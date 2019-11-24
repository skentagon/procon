
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int d;cn(d)
  vector<ll> a(d);
  vector<ll> b(d);
  rpv(a){cn(v)}
  rpv(b){cn(v)}
  bool sw = true;
  ll ans = LONG_LONG_MAX;
  ll m = 0;
  rep(i,d){
    m += a[i];
    if (b[i]<=m){
      sw = false;
      ans = min( ans, b[i] );
    }
  }
  if(sw){
    puts("-1");
  }else{
    co(ans)
  }
}