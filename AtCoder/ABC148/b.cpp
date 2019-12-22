
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  string s,t;
  int n;
  cin >> n >> s >> t;
  rep(i,n){
    cout << s[i] << t[i];
  }
  cout << endl;
}