
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

struct d_ {
  ll x;
  ll v;
  ll d;
};

double f(int x, double t,int n, vector<d_>& d){
  if (x==n)return t;
  double ans = DBL_MAX;
  for( int i=x+1; i<n+1; ++i ){
    if (d[x].x+d[x].d<d[i].x)break;
    ans = min( f(i,static_cast<double>(d[i].x-d[x].x)/d[x].v+t, n, d ), ans);
  }
  return ans;
}

int main(){
  int n;cn(n)
  ll l;cn(l)
  vector<d_> d(n+1);
  d[0].x=0;cin >> d[0].v >> d[0].d;
  rep(i,n){
    cin >> d[i+1].x >> d[i+1].v >> d[i+1].d;
  }
  sort(d.begin(),d.end(),[](const d_& a, const d_& b){return a.x<b.x;});
  cout << setprecision(6) << f(0,0,n,d) << endl;
}