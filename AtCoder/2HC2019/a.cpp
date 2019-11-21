
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for( ll (i)=0; (i)<(n); ++(i) )
#define rpv(d) for(auto& v:d)
#define co(n) cout << (n) << endl;
#define cn(n) cin >> n;
#define all(x) (x).begin(), (x).end()

#if 0
  std::ofstream lg("log.log");
#else
  std::ofstream lg;
#endif

int v_num, e_num, f_sum, t_max;

struct {
  vector<vector<int>> fx;
  void alloc(const int x){ fx.resize(x); rpv(fx){v.resize(x);} rep(i,x){rep(j,x){if (i!=j){fx[i][j]=0x7fff;}else{fx[i][j]=0;}}} }
  vector<int>& operator[](int n){ return fx[n]; }
} fx;

struct {
  vector<vector<int>> fd;
  void alloc(const int x){ fd.resize(x); rpv(fd){v.resize(x);} rep(i,x){rep(j,x){fd[i][j]=-1;}} }
  vector<int>& operator[](int n){ return fd[n]; }
} fd;

struct order{
  int dst;
  int t;
  bool sw = false;
  order(){}
  order( int dst, int t ) : dst(dst), t(t) {}
};

struct {
  int from = 0;
  int to = 1;
  int dst = 0;
  bool isOnNode(){ return (!dst); }
  bool isOn( int x ){ return isOnNode()&&(from==x); }
  void set( int x ){ from=x; to=(x+1)%v_num; dst=0; }
  void setTo( int x ){
    if (!isOnNode())throw;
    to=fd[from][x];
  }
  void move( bool sw = false ){ move( to, sw ); }
  void move( int x, bool sw = false ){
    if (isOnNode()){
      to=x;dst=1;
    }else if (to==x){
      ++dst;
    }else if (from==x){
      --dst;
    }
    if (sw)return;
    lg << "goto " << (x+1);
    cout << (x+1) << endl;
  }
  bool chkIsReached(){
    if (dst==fx[from][to]){
      from=to;dst=0;
      return true;
    }
    return false;
  }
} car;
array<order,9501> odr;

struct {
  vector<int> dst;
  int& front(){ return dst.front(); }
  bool empty(){ return dst.empty(); }
  void push_back( const int& x ){ int t(x); dst.push_back(std::move(t)); }
  size_t size(){ return dst.size(); }
  void reach( const int& x ){
    lg << "dst: reached to " << x << "\n";
    dst.erase(remove_if(all(dst),[&](int y){return x==y;}),dst.end());
  }
} dst;

struct order_cost_functional {
  int pow = 0;
  ll lnr = 0;
  ll cst = 0;
  ll getCost( const int t ){ return pow ? t_max*t_max - (pow * t*t + lnr * t + cst) : 0; }
  void reset(){pow=0;lnr=0;cst=0;}
  void add( const int x ){ ++pow; lnr -= 2*(odr[x].t); cst += (odr[x].t)*(odr[x].t); }
  void rm( const int x ){ --pow; lnr += 2*(odr[x].t); cst -= (odr[x].t)*(odr[x].t); }
};

struct {
  vector<int> v;
  vector<order_cost_functional> cost;
  void putAll(){ v.erase(all(v)); rpv(cost){v.reset();} }
  void alloc( const int x ){ cost.resize(x); }
  void push_back( const int& x ){
    v.push_back(x);
    cost[x].add(x);
  }
} waitingOrders;

struct {
  vector<int> v;
  vector<order_cost_functional> cost;
  void putAll(){ v.erase(all(v)); rpv(cost){v.reset();} }
  void alloc( const int x ){ cost.resize(x); }
  void push_back( const int& x ){
    v.push_back(x);
    cost[x].add(x);
  }
  void reach( const int x ){ cost[x].reset(); }
} stackingOrders;

void getInputGraph();
void calcGraph();
void getInputOrders( int t );
void getInputStacks();
bool getInputResult();
ll sumilate( int t, int cur, const vector<int>& d );

struct order_local{
  int t;
  vector<order> odr;
};
void getInputInfo( vector<order_local>& d ){
  rep(i,t_max){
    int n;cn(n)
    if (!n)continue;
    int id,dst;
    cin >> id >> dst;
    d[i].t = i;
    d[i].odr.push_back(order(dst,id));
  }
}
void getInputOrders( int t, vector<order_local>& d ){
  rep(i,d[t].odr.size()){
    odr[d[t].odr[i].t].dst = d[t].odr[i].dst - 1;
    odr[d[t].odr[i].t].t = t;
    waitingOrders.push_back(d[t].odr[i].t);
  }
}
void getInputStacks(){
  if (!car.isOn(0))return;
  rpv(waitingOrders.v){
    dst.push_back(odr[v].dst);
  }
  waitingOrders.putAll();
}

int main(){
  // Initialize
  cin >> v_num >> e_num;
  vector<int> f(v_num);
  vector<pair<int,int>> edge(e_num);
  fx.alloc(v_num);
  fd.alloc(v_num);
  waitingOrders.alloc(v_num);
  stackingOrders.alloc(v_num);
  getInputGraph();
  cin >> t_max;
  vector<order_local> order_lc(t_max);
  getInputInfo(order_lc);

  // Pre processing
  calcGraph();

  // Each Steps
  rep(t,t_max){
    getInputOrders(t,order_lc);
    getInputStacks();
    /*cout << "car:" << car.from << "," << car.to << "," << car.dst << endl;
    cout << "d ";
    rpv(dst){cout << v << " ";}
    cout << endl;//*/
    if (car.isOnNode())dst.reach(car.from);
    if (dst.empty()&&car.isOn(0)){
      puts("-1");
    }else{
      if (dst.empty())dst.push_back(0);
      car.chkIsReached();
      if (!car.isOnNode()){
        car.move();
      }else{
        vector<int> tv(2);
        int ans = -1;
        ll tmp = 0;
        if (dst.size()>1){
          rep(i,dst.size()){
            rep(j,dst.size()){
              if (i==j)continue;
              tv[0] = dst.dst[i]; tv[1] = dst.dst[j];
              auto tt = sumilate( t, car.from, tv );
              //cout << "res: " << dst.dst[i] << "," << dst.dst[j] << " : " << tt << endl;
              if (tt>tmp){
                tmp = tt;
                ans = i;
              }
            }
          }
        }
        if (ans>0){swap(dst.dst[ans],dst.dst[0]);}
        car.setTo(dst.front());
        car.move();
      }
    }
  }
}

ll sumilate( int t, int cur, const vector<int>& d ){
  int c = cur;
  int pass = t;
  ll ans = 0;
  rpv(d){
    pass += fx[c][v]; c = v;
    ans += stackingOrders.cost[v].getCost(pass);
  }
  return ans;
}

void calcGraph(){
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

void getInputGraph(){
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