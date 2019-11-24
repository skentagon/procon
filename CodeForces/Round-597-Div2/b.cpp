
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
  cin >> test_num;
  rep(test_num_,test_num){
    int t,a,b,c;
    cin >> t >> a >> b >> c;
    vector<char> d(t);
    int r=0,p=0,s=0;
    rep(i,t){
      cin >> d[i];
      if (d[i]=='R')r++;
      if (d[i]=='P')p++;
      if (d[i]=='S')s++;
    }
    if ( min(r,b) + min(p,c) + min(s,a) >= (t+1)/2 ){
      puts("YES");
      r=min(r,b);b-=r;
      p=min(p,c);c-=p;
      s=min(s,a);a-=s;
      rep(i,t){
        if (d[i]=='R'&&r){printf("P");r--;continue;}
        if (d[i]=='P'&&p){printf("S");p--;continue;}
        if (d[i]=='S'&&s){printf("R");s--;continue;}
        if (a){printf("R");a--;continue;}
        if (b){printf("P");b--;continue;}
        if (c){printf("S");c--;continue;}
      }
      printf("\n");
    }else{puts("NO");}
  }
}