
#include <stdio.h>

unsigned long long buffer[4][61] = { 0 };

unsigned long long ack( int m, int n ){
  if ( buffer[m][n] ){ return buffer[m][n]; }
  if ( !m ){ return buffer[m][n] = (unsigned long long)n+1; }
  if ( !n ){ return buffer[m][n] = ack( m-1, 1 ); }
  return buffer[m][n] = ack( m-1, ack( m, n-1 ) );
}

int main(void){
  int m, n;
  scanf( "%d", &m );
  scanf( "%d", &n );
  printf( "%llu\n", ack( m, n ) );
}