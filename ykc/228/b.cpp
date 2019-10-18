
#include <bits/stdc++.h>

#define rep(i,n) for( int i=0; i<n; ++i )
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> d(n,vector<int>(3));
  vector<int> res(n);
  rep(i,n){ cin >> d[i][0]; }
  rep(i,n){ cin >> d[i][1]; }
  rep(i,n){ d[i][2] = i; }
  sort( d.begin(), d.end(), [](const vector<int>& l, const vector<int>& r){
    return l[0]+l[1] < r[0]+r[1];
  });
  auto ml = (*(d.begin()))[0] + (*(d.begin()))[1];
  cout << ml << endl;
  puts("0");
  rep(i,n){
    res[d[i][2]] = min( d[i][0], ml );
  }
  rep(i,n){
    cout << res[i] << endl;
  }
  cout << ml << endl;
}