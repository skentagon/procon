/*

Novermber Challenge 2019 Division 2
  Physical Exercise

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define all(x) (x).begin(), (x).end()

int main(){
  int test_case;
  cin >> test_case;
  rep( test_case_cnt, test_case ){
    int n,m,k;
    ll mx,my;
    cin >> mx>>my>>n>>m>>k;
    vector<pair<ll,ll>> N(n);
    vector<pair<ll,ll>> M(m);
    vector<double> Ng(n);
    vector<double> Mg(m);
    vector<pair<ll,ll>> K(k);
    rep(i,n){ cin>>N[i].first>>N[i].second;}
    rep(i,m){ cin>>M[i].first>>M[i].second;}
    rep(i,k){ cin>>K[i].first>>K[i].second;}
    rep(i,n){ auto t = min_element(K.begin(),K.end(),
      [&](pair<ll,ll>& a,pair<ll,ll>& b){
        return ((a.first-N[i].first)*(a.first-N[i].first)+(a.second-N[i].second)*(a.second-N[i].second))<((b.first-N[i].first)*(b.first-N[i].first)+(b.second-N[i].second)*(b.second-N[i].second));
      });
      Ng[i] = sqrt( (t->first-N[i].first)*(t->first-N[i].first) + (t->second-N[i].second)*(t->second-N[i].second) );
    }
    rep(i,m){ auto t = min_element(K.begin(),K.end(),
      [&](pair<ll,ll>& a,pair<ll,ll>& b){
        return ((a.first-M[i].first)*(a.first-M[i].first)+(a.second-M[i].second)*(a.second-M[i].second))<((b.first-M[i].first)*(b.first-M[i].first)+(b.second-M[i].second)*(b.second-M[i].second));
      });
      Mg[i] = sqrt( (t->first-M[i].first)*(t->first-M[i].first) + (t->second-M[i].second)*(t->second-M[i].second) );
    }
    double ans = std::numeric_limits<double>::max();
    rep(i,n){
      rep(j,m){
        double t = sqrt( (N[i].first-M[j].first)*(N[i].first-M[j].first) + (N[i].second-M[j].second)*(N[i].second-M[j].second) );
        ans = min<double>( min<double>(
          sqrt( (N[i].first-mx)*(N[i].first-mx) + (N[i].second-my)*(N[i].second-my) )
          + t + Mg[j],
          sqrt( (M[j].first-mx)*(M[j].first-mx) + (M[j].second-my)*(M[j].second-my) )
          + t + Ng[i]), ans );
      }
    }
    cout << setprecision(10);
    co(ans);
  }
}