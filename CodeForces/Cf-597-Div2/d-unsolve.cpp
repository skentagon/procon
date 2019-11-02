
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

struct data {
  int id;
  ll x;
  ll y;
  ll c;
  ll k;
  int getfrom = -1;
};

ll cost(int a, int b, const vector<::data>& d){
  return (d[a].k+d[b].k)*(abs(d[a].x-d[b].x)+abs(d[a].y-d[b].y));
}

int main(){
  //
  int n;cin>>n;
  vector<::data> d(n);
  rep(i,n){
    d[i].id = i;
    cin >> d[i].x >>d[i].y;
    d[i].getfrom = i;
  }
  rep(i,n){cin>>d[i].c;}
  rep(i,n){cin>>d[i].k;}
  sort(d.begin(),d.end(),[](::data& a, ::data& b){
    return a.c < b.c;
  });
  bool keep = true;
  vector<pair<int,int>> road;
  ll cost_sum = 0;
  for( auto v:d){ cost_sum+=v.c;}
  while(keep){
    keep = false;
    for(int i=n-1; 0<=n; --i){
      auto it = max_element( d.begin(), d.begin()+i, [&](::data& a,::data& b){
        return d[i].c-a.c-cost(a.id,i,d) < d[i].c-b.c-cost(b.id,i,d); 
      });
      if ( d[i].c-(it->c)-cost(it->id,i,d) > 0 ){
        cost_sum-=d[i].c-(it->c)-cost(it->id,i,d);
        int sw = it-d.begin();
        for( auto& v:d){
          if ( v.getfrom == d[i].getfrom ){
            v.c = d[sw].c;
            v.getfrom = sw;
          }
        }
        road.push_back({i,sw});
        keep = true;
      }
    }
  }
  co(cost_sum)
  co(count_if(d.begin(),d.end(),[](::data& a){return a.id==a.getfrom;}))
  for(auto v:d){
    if (v.id==v.getfrom)cout<<v.id<<" ";
  }
  cout << endl;
  co(road.size())
  for(auto v:road){
    cout << v.first << v.second << endl;
  }
}