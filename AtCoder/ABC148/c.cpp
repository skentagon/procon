
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  ll a,b;
  cin >> a >> b;
  if (a>b)swap(a,b);
  ll ans = a*b;
  while(true){
    if (a%b){
      ll t = a%b;
      a = b;
      b = t;
    }else{
      break;
    }
  }
  cout << ans/b << endl;
}