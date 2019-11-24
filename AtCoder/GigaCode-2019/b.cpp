
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n,x,y,z;
  cin >> n >> x >> y >> z;
  int ans = 0;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    if( a>=x && b>=y && (a+b)>=z )ans++;
  }
  cout << ans << endl;
}