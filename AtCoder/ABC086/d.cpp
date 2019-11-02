    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    #define rep(i,n) for( int (i)=0; (i)<(n); ++(i) )
    #define rpv(d) for(auto& v:d)
    #define co(n) cout << (n) << endl;
    #define cn(n) cin >> n;
    #define all(x) (x).begin(), (x).end()
     
    int main(){
      int n;cin>>n;
      int t_=0,x_=0,y_=0;
      rep(i,n){
        int t,x,y;
        cin>>t>>x>>y;
        if (abs(x-x_)+abs(y-y_)>t-t_||(x+x_+y+y_+t+t_)%2){
          puts("No");return 0;
        }
        t_=t;x_=x;y_=y;
      }
      puts("Yes");
    }