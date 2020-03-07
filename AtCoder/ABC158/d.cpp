
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
  string s;cn(s)
  string h,b;
  bool sw = false;
  ll q;cn(q)
  rep(i,q){
    int t;cn(t)
    if (t==1){
      sw = !sw;
    }else{
      int f;char c;cn(f,c)
      if ((f==1&&sw)||(f==2&&(!sw))){
        h.push_back(c);
      }else{
        b.push_back(c);
      }
    }
  }
  if (!sw){
    for(auto v=b.rbegin(),e=b.rend();v!=e;++v){
      cout << *v;
    }
    co(s,h)
  }else{
    for(auto v=h.rbegin(),e=h.rend();v!=e;++v){
      cout << *v;
    }
    for(auto v=s.rbegin(),e=s.rend();v!=e;++v){ cout << *v; }
    co(b)
  }
}