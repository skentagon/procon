
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;cn(test_case)
  rep(test_case_num,test_case){
    int n,h,y1,y2,l;
    cin>>n>>h>>y1>>y2>>l;
    rep(i,n){
      int t;cin>>t;
      if (t==1){
        cin>>t;
        if (h-y1>t)l--;
      }else{
        cin>>t;
        if (t>y2)l--;
      }
      if (l==0){
        co(i)l--;
      }
    }
    if (l>0)co(n);
  }
}