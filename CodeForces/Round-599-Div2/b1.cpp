
#include <bits/stdc++.h>
using namespace std;
namespace skentagon::util{}
using namespace skentagon::util;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;cn(test_case)
  rep(test_case_,test_case){
    ll n;cn(n)
    string s,t;
    cn(s)cn(t)
    ll c = -1;
    bool res = false;
    rep(i,n){
      if (s[i]==t[i])continue;
      if (res){
        res = false;
        break;
      }
      if (c<0ll){
        c = i;
      }else{
        if ( (s[i]==s[c])&&(t[i]==t[c]) ){
          res = true;
        }else{
          res = false;
          break;
        }
      }
    }
    if (res){
      co("Yes")
    }else{
      co("No")
    }
  }
}