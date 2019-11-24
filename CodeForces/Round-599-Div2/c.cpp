
#include <bits/stdc++.h>
using namespace std;
namespace skentagon::util{}
using namespace skentagon::util;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  ll n;
  cn(n);
  bool map[1000001];
  ll t = 0;
  rep(i,1000001){map[i]=true;}
  for( ll i=2; i*i<=n; i++){
    if (map[i]){
      for( ll j=2; j*i<1000001; ++j ){map[j*i]=false;}
      if (!(n%i)){
        if (t){
          co("1");
          return 0;
        }
        t = i;
        while(!(n%i)){n/=i;}
      }
    }
  }
  if (t){
    if (n==1){
      co(t)
    }else{
      co("1")
    }
  }else{
    co(n)
  }
}