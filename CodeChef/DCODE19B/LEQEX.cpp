
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

bool count(unsigned int x){
  int t=0;
  while(x){
    x&=x-1;
    ++t;
    if (t>1)return false;
  }
  if (t)return true;
  return false;
}

int count_(unsigned int x){
  int t=0;
  while(x){
    x&=x-1;
    ++t;
  }
  return t;
}

int main(){
  int test_case;cn(test_case)
  rep(test_case_num,test_case){
    int n;
    cin >>n;
    //vector<unsigned int> d(n+1);
    unsigned int d[100001];
    d[0]=0U;
    rep(i,n){
      unsigned int t;
      cin>>t;
      d[i+1]=d[i]^(1U<<(t-1));
    }
    int ans = 1;
    rep(i,n-2){
      for(int j=i+3;j<n+1;j+=2){
        //if (j-i<ans)continue;
        if (count(d[i]^d[j])){ans=max(j-i,ans);}
      }
    }
    co((ans-1)/2)
  }
}