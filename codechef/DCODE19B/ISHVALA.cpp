
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;cn(test_case)
  rep(test_case_num,test_case){
    int n,m,x,y,s;
    cin>>n>>m>>x>>y>>s;
    int xs=0,ys=0;
    int xd=1,yd=1;
    rep(i,x){
      int t; cin >> t;
      xs+=(t-xd)/s; xd=t+1;
    }
    xs+=(n-xd+1)/s;
    rep(i,y){
      int t; cin >> t;
      ys+=(t-yd)/s; yd=t+1;
    }
    ys+=(m-yd+1)/s;
    co(xs*ys)
  }
}