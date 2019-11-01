
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()


//mod
const ll MOD = 1e9+7;
//const ll MOD = 998244353;

int main(){
  string s;
  cin >> s;
  ll ans = 1;
  ll n1=0,n2=0,u1=0,u2=0;
  rep(i,s.length()){
    if (s[i]=='m'||s[i]=='w'){puts("0");return 0;}
    if (s[i]=='n'){
      if (n1){
        ll t=n1;
        n1+=n2;n1%=MOD;
        n2=t;
      }else{n1=1;n2=0;}
    }else if (n1){
      ans*=(n1+n2);
      ans %= MOD;
      n1=0;
    }
    if (s[i]=='u'){
      if (u1){
        ll t=u1;
        u1+=u2;u1%=MOD;
        u2=t;
      }else{u1=1;u2=0;}
    }else if (u1){
      ans*=(u1+u2);
      ans %= MOD;
      u1=0;
    }
  }
  if (n1){
    ans*=(n1+n2);
    ans %= MOD;
  }
  if (u1){
    ans*=(u1+u2);
    ans %= MOD;
  }
  co(ans);
}