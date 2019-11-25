
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
  int n;cn(n)
  vector<pair<int,int>> d(n);
  rep(i,n){
    string s;cn(s)
    d[i]=make_pair(
      (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+((s[3]-'0')/5)*5,
      (s[5]-'0')*1000+(s[6]-'0')*100+( 60<=(s[7]-'0')*10+((s[8]-'0'+4)/5)*5 ? 100 : (s[7]-'0')*10+((s[8]-'0'+4)/5)*5 )
    );
  }
  sort(all(d),[](pair<int,int>& a, pair<int,int>& b){
    return a.first==b.first ? a.second < b.second : a.first < b.first;
  });
  int end = d[0].second;
  cout << setw(4) << setfill('0') << d[0].first;
  rpv(d){
    if (end < v.first ){
      co("-",setw(4),setfill('0'),end)
      cout << setw(4) << setfill('0') << v.first;
    }
    end = max( end, v.second );
  }
  co("-",setw(4),setfill('0'),end)
}