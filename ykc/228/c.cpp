
#include <bits/stdc++.h>

#define rep(i,n) for( int i=0; i<n; ++i )
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int c[5];
  rep(i,5){c[i]=0;}
  int cnt19 = 0;
  int over9 = 0;
  int cnt991 = 0;
  vector<int> v;
  int dx1 = -1;
  rep(i,s.length()){
    c[(s[i]-'1')/2]++;
    if ( s[i] == '9' ){
      if ( 0 <= dx1 ){
        v.erase(v.begin()+dx1);
        cnt19++;
        auto t = find( v.begin()+dx1, v.end(), 1 );
        if ( t == v.end() ){
          dx1 = -1;
        } else {
          dx1 = t - v.begin();
        }
      } else { v.push_back(9); }
    }
    if ( s[i] == '1' ){
      if (dx1==-1)dx1 = v.size();
      v.push_back(1);
    }
  }
  rep(i,v.size()){
    if ( v[i] == 1 ){
      if(1<over9){
        over9 -= 2;
        cnt991++;
      }
    } else {
      over9++;
    }
  }
  cout << c[1]+c[2]+c[3] + cnt19 + cnt991 + (c[0]-cnt19-cnt991)/2 << endl;
}