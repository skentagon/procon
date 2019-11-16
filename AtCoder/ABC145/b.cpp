
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n;string s;cn(n)cn(s)
  if (n%2){
    puts("No");
  }else{
    if (s.substr(0,n/2)==s.substr(n/2,n/2)){
      puts("Yes");
    }else{
      puts("No");
    }
  }
}