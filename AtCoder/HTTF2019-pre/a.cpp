
#include <bits/stdc++.h>

const int n = 40;
const int m = 100;
const int b = 300;

class cell {
  public:
    enum Type {
      non,
      block,
      robot,
      goal
    };
    Type type;
    int x,y;
    cell* U;
    cell* D;
    cell* L;
    cell* R;
    void setpos(int x,int y){
      this->x=x; this->y=y;
      U = &map[(x-1+n)%n][y];
      D = &map[(x+1)%n][y];
      L = &map[x][(y-1+n)%n];
      R = &map[x][(y+1)%n];
    }
  private:
};

cell map[n][n];
cell* goal;

int main(){
  int t,x,y;
  for(int i=0; i<n; ++i ){
    for(int j=0;j<n;++j){
      map[i][j].setpos(i,j);
    }
  }
  std::cin >> t >> t >> t >> x >> y;
  map[x][y].type = cell::Type::goal;
  goal = &(map[x][y]);
}