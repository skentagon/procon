
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  string s;
  cin >> s;
  if ( s=="SUN"){
    puts("7");
  }else if(s=="MON"){
    puts("6");
  }else if(s=="TUE"){
    puts("5");
  }else if (s=="WED"){
    puts("4");
  }else if (s=="THU"){
    puts("3");
  }else if(s=="FRI"){
    puts("2");
  }else if (s=="SAT"){
    puts("1");
  }
}