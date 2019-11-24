
#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;cin>>a>>b;
  auto t=atoi(string{a+b}.c_str());
  if (sqrt(t)==floor(sqrt(t)))puts("Yes");else puts("No");
}