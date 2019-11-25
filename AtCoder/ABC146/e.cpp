
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n;ll k;
  cin >> n >> k;
  vector<pair<ll,int>> d;
  ll ans = 0;
  rep(i,n){
    ll t;cn(t)
    bool sw=true;
    rpv(d){
      v.first = ( v.first + t - 1 ) %k;
      if (v.first == (t-1)%k ){++v.second;sw=false;};
      if (!v.first)ans+=v.second;
    }
    if (sw){
      d.push_back(pair<ll,int>{(t-1)%k,1});
      if ((t-1)%k==0)++ans;
    }
  }
  co(ans)
}