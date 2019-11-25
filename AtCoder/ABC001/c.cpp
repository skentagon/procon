
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
  int g,s;cn(g,s)
  if(s<15){
    s=0;
  }else if(s<93){
    s=1;
  }else if(s<201){
    s=2;
  }else if(s<327){
    s=3;
  }else if(s<477){
    s=4;
  }else if(s<645){
    s=5;
  }else if(s<831){
    s=6;
  }else if(s<1029){
    s=7;
  }else if(s<1245){
    s=8;
  }else if(s<1467){
    s=9;
  }else if(s<1707){
    s=10;
  }else if(s<1959){
    s=11;
  }else{s=12;}
  if(!s){co("C 0");return 0;}
  switch(static_cast<int>((g+112)/225)-1){
    case 0:cout<<"NNE";break;
    case 1:cout<<"NE";break;
    case 2:cout<<"ENE";break;
    case 3:cout<<"E";break;
    case 4:cout<<"ESE";break;
    case 5:cout<<"SE";break;
    case 6:cout<<"SSE";break;
    case 7:cout<<"S";break;
    case 8:cout<<"SSW";break;
    case 9:cout<<"SW";break;
    case 10:cout<<"WSW";break;
    case 11:cout<<"W";break;
    case 12:cout<<"WNW";break;
    case 13:cout<<"NW";break;
    case 14:cout<<"NNW";break;
    default:cout<<"N";break;
  }
  co(" ",s)
}