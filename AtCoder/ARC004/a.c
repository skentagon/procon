
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  int n;
  scanf("%d",&n);
  int x[100];
  int y[100];
  for( int i=0; i<n; ++i ){
    scanf("%d %d",&x[i],&y[i]);
  }
  long long ans = 0;
  for( int i=0; i<n; ++i ){
    for( int j=i+1; j<n; ++j ){
      long long t = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
      if ( ans < t ){ ans = t; }
    }
  }
  printf( "%f\n", sqrt((double)ans) );
}