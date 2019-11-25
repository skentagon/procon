
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

ll f(ll i,ll a, ll b){
  int d=1,t=i;
  while(t/10){
    ++d;t/=10;
  }
  return a*i + b*d;
}

int main(){
  ll a,b,x;
  cin >> a >> b >> x;
  ll bgn = 0;
  ll end = 1000000000;
  while(true){
    if (end-bgn<=1)break;
    if ( f((bgn+end)/2,a,b)<=x ){
      bgn=(bgn+end)/2;
    }else{
      end=(bgn+end)/2-1;
    }
  }
  if (f(end,a,b)<=x){
    co(end)
  }else{
    co(bgn)
  }
}