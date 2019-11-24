
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
    if (ans[k].empty()){
      ans[k].reserve(k+1);
      rep(i,k+1){
        ans[k].push_back(&(*(a.begin()+i)));
      }
      sort( all(ans[k]),[](const pair<ll,int>* a, const pair<ll,int>* b ){
        return a->second < b->second;
      });
    }
    co((*ans[k][pos]).first)
  }
}