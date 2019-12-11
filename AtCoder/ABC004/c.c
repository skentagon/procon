
#include <stdio.h>


int main(void){
  long long n;
  int d[] = { 1, 2, 3, 4, 5, 6 };
  int tmp;
  scanf( "%lld", &n );
  for( int i=0; i<n%30; ++i ){
    tmp = d[i%5];
    d[i%5] = d[i%5+1];
    d[i%5+1] = tmp;
  }
  for( int i=0; i < 6; ++i ){
    printf("%d",d[i]);
  }
  printf("\n");
}