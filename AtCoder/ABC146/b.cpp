
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n;cn(n)
  string s;cn(s);
  rpv(s){
    cout << static_cast<char>( (v+n-'A')%26 + 'A' );
  }
  cout << endl;
}