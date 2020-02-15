
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpi(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#if __cplusplus < 201703L
  std::ostream& co_(){ return std::cout << std::endl; }
  std::istream& cn_(){ return std::cin; }
  template<class Head, class... Args>
  std::ostream& co_( Head&& head, Args&&... args ){ std::cout << head; return co_(std::forward<Args>(args)...); }
  template<class Head, class... Args>
  std::istream& cn_( Head&& head, Args&&... args ){ std::cin >> head; return cn_(std::forward<Args>(args)...); }
#else
  template<class... Args>
  std::ostream& co_( Args... args ){ return std::cout << ... << args << std::endl; }
  template<class... Args>
  std::istream& cn_( Args... args ){ return std::cin >> ... >> args; }
#endif
#define co(...) co_(__VA_ARGS__);
#define cn(...) cn_(__VA_ARGS__);
#define all(x) (x).begin(), (x).end()
#define rgt(x,i) (x).begin(), (x).begin()+(i)

int main(){
  int n,w,k,v;
  cn(n,w,k,v);
  vector<pair<int,int>> c(n);
  vector<int> cnt(k,0);
  vector<int> sum(k,0);
  rpv(c){
    cn(v.first,v.second);
    sum[v.first] += v.second;
    ++cnt[v.first];
  }
  vector<vector<int>> map(w,vector<int>(n,-1));
  vector<int> wcnt(w,0);
  vector<int> hcnt(n,k);
  vector<vector<int>> hv(n,vector<int>(k,0));
  rep(i,n){
    int score = -10000;
    int col = 0;
    co("#",c[i].first,c[i].second)
    rep(j,8){
      {
        ll v = 0;
        { // 高さを抑える
          int t = *min_element(all(wcnt));
          v -= (1000 * (wcnt[j] - t )) / (n/w - t );
        }

        { // 価値計算
          auto t = max_element(all(hv[wcnt[j]]));
          //co(*t + ( cnt[t - hv[wcnt[j]].begin()] ? -sum[t - hv[wcnt[j]].begin()]/cnt[t - hv[wcnt[j]].begin()] : 0 ), hv[wcnt[j]][c[i].first] + c[i].second)
          v += max(
            *t,
            hv[wcnt[j]][c[i].first] + c[i].second
          );
          v -= cnt[t - hv[wcnt[j]].begin()] ? -sum[t - hv[wcnt[j]].begin()]/cnt[t - hv[wcnt[j]].begin()] : 0;
        }
      }
      co(" ",v," ",j)
      if (v>score){
        score = v;
        col = j;
      }
    }
    co(col)
    sum[c[i].first] -= c[i].second;
    --cnt[c[i].first];
    ++hcnt[wcnt[col]];
    hv[wcnt[col]][c[i].first] += c[i].second;
    ++wcnt[col];
    co(cnt[c[i].first])
  }
}