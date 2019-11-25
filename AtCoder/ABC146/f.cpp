
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n,m;
  cin >> n >> m;
  string s; cn(s)
  vector<int> ans;
  int pos = n;
  bool sw = true;
  while(true){
    bool sw = true;
    for( int i=m; 0<i; --i ){
      if (i<=n&&s[n-i]=='0'){
        ans.push_back(i);
        n -= i;
        sw = false;
        break;
      }
    }
    if (n==0)break;
    if (sw){
      puts("-1");
      return 0;
    }
  }
  rep(i,ans.size()){
    cout << ans[ans.size()-i-1] << " ";
  }
  cout << endl;
}