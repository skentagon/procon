
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int a,b;cn(a)cn(b)
  for( int i=1; i<4; ++i ){
    if (i!=a&&i!=b){
      cout << i << endl;
    }
  }
}