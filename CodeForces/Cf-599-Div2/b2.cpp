
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
    ll l[26];rep(i,26){l[i]=0;}
    rep(i,n){
      if (s[i]==t[i])continue;
      l[s[i]-'a']++;
      l[t[i]-'a']++;
    }
    bool sw = false;
    rep(i,26){
      if (l[i]%2){
        co("No")
        sw = true;
        break;
      }
    }
    if (sw)continue;
    co("Yes")
    list<pair<ll,ll>> li;
    rep(i,s.size()){
      if (s[i]==t[i])continue;
      auto it = find(s.begin()+i+1,s.end(),s[i]);
      if (it==s.end()){
        it = find(t.begin()+i+1,t.end(),s[i]);
        iter_swap(s.begin()+i+1,it);
        iter_swap(s.begin()+i+1,t.begin()+i);
        li.push_back(pair<ll,ll>{i+1,it-t.begin()});
        li.push_back(pair<ll,ll>{i+1,i});
      }else{
        iter_swap(t.begin()+i,it);
        li.push_back(pair<ll,ll>{it-s.begin(),i});
      }
    }
    co(li.size())
    rpv(li){cout << v.first+1 << " " << v.second+1 << endl;}
  }
}