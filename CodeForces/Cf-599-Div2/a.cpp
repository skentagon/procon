/*

  A - Maximum Square

*/


#include <bits/stdc++.h>
using namespace std;
namespace skentagon::util{}
using namespace skentagon::util;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case; cn(test_case)
  rep( test_case_,test_case){
    int n;
    cn(n);
    vector<int> d(n);
    rpv(d){cn(v)}
    sort(all(d));
    rep(i,n){
      if (n-i<=d[i]){
        co(n-i)
        break;
      }
    }
  }
}