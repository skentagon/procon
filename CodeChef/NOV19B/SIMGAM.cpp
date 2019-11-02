/*

Novermber Challenge 2019 Division 2
  A Simple Game

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;
  cin >> test_case;
  rep( test_case_cnt, test_case ){
    int n; cin >> n;
    vector<vector<int>> c(n);
    vector<int> mids;
    ll ans = 0;
    rep(i,n){
      int t; cin>>t;
      vector<int> d(t);
      for(auto& v:d){cn(v)}
      ans += accumulate( d.begin(),d.begin()+t/2, 0);
      if (t%2){mids.push_back(d[t/2]);}
    }
    sort(mids.begin(),mids.end(),[](int& a, int& b){return a>b;});
    rep(i,mids.size()){if ((i+1)%2)ans+=mids[i];}
    co(ans);
  }
}