
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;
  cin >> test_case;
  rep(test_case_,test_case){
    int n;cn(n)
    vector<int> in(n);
    vector<int> ans(n,n+1);
    vector<bool> m(n,true);
    rpv(in){cn(v);}
    if (n<in[0]){
      puts("-1");continue;
    }
    ans[0] = in[0];
    m[in[0]-1]=false;
    bool sw = false;
    for( int i=1; i<n; ++i ){
      if (n<in[i]){sw = true;break;}
      if (in[i]<in[i-1]){sw=true;break;}
      if ( in[i] != in[i-1] ){
        ans[i] = in[i];
        m[in[i]-1] = false;
      }
    }
    if(sw){puts("-1");continue;}
    int m_index = 0;
    for( int i=1; i<n; ++i ){
      if ( ans[i] == n+1 ){
        int t=-1;
        for( int j=m_index; j<in[i]; ++j ){
          if (m[j]){
            if (t==-1){
              t=j+1;
              m_index = j+1;
              break;
            }
          }
        }
        if (t==-1){sw=true;break;}
        m[t-1]=false;
        ans[i]=t;
      }
    }
    if(sw){puts("-1");continue;}
    rpv(ans){
      cout << v << " ";
    }
    cout << endl;
  }
}