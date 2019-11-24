
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n;cin>>n;
  vector<pair<ll,int>> a(n);
  vector<vector<pair<ll,int>*>> ans(n);
  vector<bool> sw(n,true);
  rep(i,n){
    cin>>a[i].first;
    a[i].second = i;
  }
  sort(all(a),[](const pair<ll,int>& a, const pair<ll,int>& b ){
    return a.first==b.first ? a.second < b.second : a.first > b.first;
  });
  int test_case;
  cin >> test_case;
  rep(test_case_,test_case){
    int k,pos;cin >> k >> pos;
    --k;--pos;
    if (sw[k]){
      ans[k].resize(k+1);
      rep(i,k+1){
        ans[k][i] = &(*(a.begin()+i));
      }
      sort( ans[k].begin(),ans[k].begin()+k+1,[](const pair<ll,int>* a, const pair<ll,int>* b ){
        return a->second < b->second;
      });
      sw[k]=false;
    }
    co((*ans[k][pos]).first)
  }
}