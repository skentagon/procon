/*

Novermber Challenge 2019 Division 2
  A Simple Game

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  struct type {
    string s;
    int d[26];
    type(){
      rep(i,26){d[i]=0;}
    }
    bool alice;
  };
  int test_case;
  cin >> test_case;
  rep( test_case_cnt, test_case ){
    int n; cin >> n;
    vector<type> d;
    rpv(d){cn(v.s)}
    int asum[26] = {};
    int bsum[26] = {};
    int acnt=0,bcnt=0;
    rpv(d){
      rep(i,v.s.size()){
        //e[v.s[i]-'a']++;
      }
    }
  }
}