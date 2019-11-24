
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int h,w;ll k,v;
  cin >> h >> w >> k >> v;
  vector<vector<ll>> a(w,vector<ll>(h));
  rep(i,w){
    rep(j,h){
      cin >> a[i][j];
    }
  }
  int ans = 0;
  rep(i,w+1){
    rep(j,h+1){
      if (i*j<=ans)continue;
      rep(x,w-i+1){
        rep(y,h-j+1){
          ll sum = 0;
          rep(y_,j){
            rep(x_,i){
              sum += a[x_+x][y_+y];
            }
          }
          if ( sum + i*j*k <= v ){
            ans = i*j;continue;
          }
        }
      }
    }
  }
  co(ans)
}