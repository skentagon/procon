
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  ll n;cn(n)
  if (n%2){
    puts("0");
  }else{
    ll t = 0;
    ll m = n/2;
    while(m){
      t += m /= 5;
    }
    cout << t << endl;
  }
}