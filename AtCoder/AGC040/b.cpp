
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int main(){
  int n; cin >> n;
  vector<pair<ll,ll>> d(n);
  rep(i,n){ cin >> d[i].first >> d[i].second; }
  int ldx,rdx;
  sort(d.begin(),d.end(),[](pair<ll,ll>& a,pair<ll,ll>& b){return a.second>b.second;});
  ldx = n-1;//min_element(d.begin(),d.end(),[](pair<ll,ll>& a,pair<ll,ll>& b){return a.second<b.second;})-d.begin();
  rdx = max_element(d.begin(),d.end(),[](pair<ll,ll>& a,pair<ll,ll>& b){return a.first<b.first;})-d.begin();
  if (ldx==rdx){
    int t = max_element(d.begin(),d.end(),[](pair<ll,ll>& a,pair<ll,ll>& b){return a.second-a.first<b.second-b.first;})-d.begin();
    co(d[t].second-d[t].first+d[ldx].second-d[ldx].first+2)
  }else{
    ll lmin, rmin, mmin;
    bool lsw = false, rsw = false;
    bool msw = false;
    rep(i,n){
      if (i==ldx||i==rdx){continue;}
      bool tl = d[ldx].second<=d[i].first;
      bool tr = d[i].second<=d[rdx].first;
      if (tl&&tr){
        ll t = max_element(d.begin(),d.end(),[](pair<ll,ll>& a,pair<ll,ll>& b){return a.second-a.first<b.second-b.first;})-d.begin();
        co(d[t].second-d[t].first+1)
        return 0;
      }
        ll dl  = lsw ? max( 0ll, lmin - (d[ldx].second-d[i].first+1) ) : d[i].first -d[ldx].first - 1;
        ll dr  = rsw ? max( 0ll, rmin - (d[i].second-d[rdx].first+1) ) : d[rdx].second - d[i].second -1;
        if ( dr < dl ){
          rmin = min( rmin, d[i].second-d[rdx].first+1 );
          rsw = true;
        }else if ( dl < dr ){
          lmin = min( lmin, d[ldx].second-d[i].first+1 );
          lsw = true;
        }else{
          msw = true;
          mmin = min( mmin, d[ldx].second-d[i].first+1 );
        }
    }
    if (msw){
      if (lsw&&rsw){
        if (lmin<rmin){
          co(rmin+min(lmin,mmin))
        }else{
          co(lmin+min(rmin,mmin))
        }
      }else{
        if (lsw){
          co(lmin+mmin)
        }else{
          co(rmin+mmin)
        }
      }
    }else{
      if (lsw&rsw){
        co(lmin+rmin)
      }else{
        if (lsw){
          co(lmin+d[rdx].second-d[rdx].first+1)
        }else{
          co(rmin+d[ldx].second-d[ldx].first+1)
        }
      }
    }
  }
}