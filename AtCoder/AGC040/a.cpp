
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  string s; cin >> s;
  ll increase = 0;
  ll decrease = 0;
  ll ans = 0;
  rep(i,s.length()){
    if (s[i]=='<'){
      if (decrease){
        ans += decrease*(decrease-1)/2 + increase*(increase-1)/2 + max(increase,decrease);
        increase = 0;
        decrease = 0;
      }
      increase++;
    }else{decrease++;}
  }
  if (decrease){
    ans += decrease*(decrease-1)/2 + increase*(increase-1)/2 + max(increase,decrease);
  }else{
    ans += increase*(increase+1)/2;
  }
  co(ans);
}