
#include <bits/stdc++.h>

#define rep(i,n) for( int i=0; i<n; ++i )
typedef long long ll;
using namespace std;

int main(){
  string s;
  getline( cin, s );
  rep( i, s.length() ){
    //cout << s[i] << endl;
    if (i%2){
      if ( s[i] != ' ' ){ puts("No"); return 0; }
    } else {
      if ( (s[i]<'a') || ('z'<s[i]) ){ puts("No"); return 0; }
    }
  }
  puts("Yes");
}