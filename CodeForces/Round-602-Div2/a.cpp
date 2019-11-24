
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;
  cin >> test_case;
  rep(test_case_,test_case){
    ll n;cn(n)
    vector<ll> l(n);
    vector<ll> r(n);
    rep(i,n){
      cin >> l[i] >> r[i];
    }
    sort(all(l));
    sort(all(r));
    ll ans = l[n-1]-r[0];
    cout << (ans<0 ? 0 : ans) << endl;
  }
}