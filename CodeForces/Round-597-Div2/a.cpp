
#include <bits/stdc++.h>
using namespace std;
namespace skentagon::util{};
using namespace skentagon::util;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_num;
  cn(test_num);
  rep(test_num_,test_num){
    int a,b;
    cin >> a >> b;
    if ( a<b ){swap(a,b);}
    while(true){
      if (b==1){co("Finite");break;}
      if (!b){co("Infinite");break;}
      int t=b;b=a%b;a=t;
    }
  }
}