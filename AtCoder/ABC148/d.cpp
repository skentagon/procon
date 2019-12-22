
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  ll n;
  cn(n)
  ll cnt = 1; //next
  rep(i,n){
    ll a;cn(a)
    if (cnt==a)++cnt;
  }
  if (cnt==1){
    puts("-1");
  }else{
    cout << n-cnt+1 << endl;
  }
}