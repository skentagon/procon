/*

Novermber Challenge 2019 Division 2
  Hard Sequence

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
#define co(n) cout << (n) << endl;
#define all(x) (x).begin(), (x).end()

int main(){
  vector<int> d(128);
  d[0]=0;
  rep(i,127){
    decltype(d)::iterator it = find_end( d.begin(), d.begin()+i, d.begin()+i, d.begin()+i+1 );
    if ( it == d.begin()+i ){
      d[i+1]=0;
    }else{
      d[i+1]=i-distance(d.begin(),it);
    }
  }
  int test_case;
  cin >> test_case;
  rep( test_case_cnt, test_case ){
    int i;cin>>i;
    co(count(d.begin(),d.begin()+i,d[i-1]));
  }
}