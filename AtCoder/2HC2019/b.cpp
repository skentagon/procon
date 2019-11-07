
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

int v_num, e_num, f_sum;
struct order{
  int dst;
  int t;
  bool sw = false;
};
struct {
  int from = 0;
  int to = 1;
  int dst = 0;
  bool isOnNode(){ return (!dst); }
  bool isOn( int x ){ return isOnNode()&&(from==x); }
  void move( int x ){
    if (to==x)++dst;
    if (from==x)--dst;
    if (isOnNode()){to=x;dst=1;}
  }
  bool chkIsReached( vector<vector<int>>& fx ){
    if (dst==fx[from][to]){
      from=to;dst=0;
      return true;
    }
    return false;
  }
} car;
array<order,9501> odr;
list<int> dst;
vector<int> waitingOrders;
vector<int> stackingOrders;

void getInputGraph( vector<vector<int>>& fx, vector<vector<int>>& fd );
void initializeBuffer( vector<vector<int>>& fx, vector<vector<int>>& fd );
void calcGraph( vector<vector<int>>& fx, vector<vector<int>>& fd );
void getInputOrders( int t );
void getInputStacks();
bool getInputResult();

int main(){
  // Initialize
  cin >> v_num >> e_num;
  vector<int> f(v_num);
  vector<vector<int>> fx(v_num,vector<int>(v_num));
  vector<vector<int>> fd(v_num,vector<int>(v_num));
  initializeBuffer( fx, fd );
  getInputGraph( fx, fd );
  rpv(f){cn(v)} //f_sum = accumulate(all(f),0);
  int t_max; cin >> t_max;

  // Pre processing
  calcGraph( fx, fd );

  // Each Steps
  rep(t,t_max){
    getInputOrders(t);
    getInputStacks();
    /*cout << "car:" << car.from << "," << car.to << "," << car.dst << endl;
    cout << "d ";
    rpv(dst){cout << v << " ";}
    cout << endl;//*/
    if (dst.empty()&&car.isOn(0)){
      puts("-1");
    }else{
      if (dst.empty())dst.push_back(0);
      car.chkIsReached(fx);
      if (car.dst){
        if ( fx[dst.front()][car.from] < fx[dst.front()][car.to] ){
          co(car.from+1)
          --car.dst;
        }else{
          co(car.to+1)
          ++car.dst;
        }
      }else{
        dst.remove_if([&](int x){return x==car.from;});
        co(fd[car.from][dst.front()]+1)
        car.to=fd[car.from][dst.front()];
        ++car.dst;
      }
    }
    if(getInputResult())break;
    //puts("end");
  }
}

bool getInputResult(){
  string s;cn(s)
  if (s=="NG")return true;
  int n;cn(n)rep(i,n){
    int id;cn(id)
    odr[id].t=false;
  }
  return false;
}

void getInputStacks(){
  int n;cn(n)
  if (n){car.from=0; car.dst=0;}
  rep(i,n){
    int id;cn(id)
    dst.push_back(odr[id].dst);
  }
}

void getInputOrders( int t ){
  int n;cn(n)
  rep(i,n){
    int id,dst; cn(id)
    cn(odr[id].dst)
    --(odr[id].dst);
    odr[id].t=t;
  }
}

void calcGraph( vector<vector<int>>& fx, vector<vector<int>>& fd ){
  rep(k,v_num){
    rep(i,v_num){
      rep(j,v_num){
        if ( fx[i][k] + fx[k][j] < fx[i][j] ){
          fx[i][j] = fx[i][k] + fx[k][j];
          fd[i][j] = fd[i][k]; 
        }
      }
    }
  }
  /*rep(i,v){
    rep(j,v){
      cout << "[" << i << "," << j << "] : " << fx[i][j] << " to " << fd[i][j] << endl;
    }
  }//*/
}

void getInputGraph( vector<vector<int>>& fx, vector<vector<int>>& fd ){
  rep(i,e_num){
    int v1,v2,d;
    cin >> v1 >> v2 >> d;
    --v1; --v2;
    fx[v1][v2] = d;
    fx[v2][v1] = d;
    fd[v1][v2] = v2;
    fd[v2][v1] = v1;
  }
  /*rpv(edge){
    cout << get<0>(v) << "," << get<1>(v) << endl;
  }//*/
}

void initializeBuffer( vector<vector<int>>& fx, vector<vector<int>>& fd ){
  rep(i,v_num){rep(j,v_num){if (i!=j){fx[i][j]=0x7fff;}else{fx[i][j]=0;}}}
  rep(i,v_num){rep(j,v_num){fd[i][j]=-1;}}
}