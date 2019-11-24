
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int func( vector<int>::iterator bgn, vector<int>::iterator end, int v ){
  auto itl = lower_bound(bgn,end,v);
  auto itu = upper_bound(bgn,end,v);
  if (itu == bgn)return 0;
  int cnt = itu - itl;
  for( auto i=itl-1; bgn<i; --i){
    cnt += func( bgn, i, v-*i );
  }
  return cnt;
}

int main(){
  int n,x;
  cn(n)cn(x)
  vector<int> w(n);
  rpv(w){cn(v)}
  sort(all(w));
  unsigned int bit = 0;
  for( ; bit <= 1<<(n/2); ++bit ){

  }
  co(func(all(w),x));
}