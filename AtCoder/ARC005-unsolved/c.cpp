
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()


int main(){
  int h,w;cn(h)cn(w)
  vector<vector<char>> map(h,vector<char>(w));
  vector<vector<int>> m(h,vector<int>(w));
  vector<vector<bool>> sw(h,vector<bool>(w));
  rep(i,h){rep(j,w){m[i][j]=3;sw[i][j]=false;}}
  int sx,sy,gx,gy;
  rep(i,h){
    rep(j,w){
      cn(map[i][j])
      if(map[i][j]=='s'){sx=i,sy=j;}
      if(map[i][j]=='g'){gx=i,gy=j;}
    }
  }
  queue<tuple<int,int,int>> q;
  q.push(tuple<int,int,int>(sx,sy,0));
  while(!q.empty()){
    int x = get<0>(q.front());
    int y = get<1>(q.front());
    if (m[x][y]>get<2>(q.front())){
      m[x][y]=get<2>(q.front());
      if (x+1<h)q.push(tuple<int,int,int>(x+1,y,m[x][y]+(map[x+1][y]=='#')));
      if (x)q.push(tuple<int,int,int>(x-1,y,m[x][y]+(map[x-1][y]=='#')));
      if (y+1<w)q.push(tuple<int,int,int>(x,y+1,m[x][y]+(map[x][y+1]=='#')));
      if (y)q.push(tuple<int,int,int>(x,y-1,m[x][y]+(map[x][y-1]=='#')));
    }
    q.pop();
  }
  if (m[gx][gy]<3){
    puts("YES");
  }else{
    co("NO")
  }
}