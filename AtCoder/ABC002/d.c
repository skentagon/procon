
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

unsigned int func( int dx, int n, _Bool* bits, _Bool* table ){
  if ( dx >= n ){
    unsigned int num = 0;
    for( int i=0; i<n; ++i ){
      if (!bits[i])continue;
      ++num;
      for( int j=i+1; j<n; ++j ){
        if (!bits[j])continue;
        if ( !table[i*n+j] )return 1;
      }
    }
    return num;
  }
  bits[dx] = true;
  unsigned int lhs = func( dx+1, n, bits, table );
  bits[dx] = false;
  unsigned int rhs = func( dx+1, n, bits, table );
  if ( lhs < rhs ){
    return rhs;
  } else {
    return lhs;
  }
}

int main(void){
  int n,m;
  char s[6];

  // get input
  fgets( s, sizeof(s), stdin );
  sscanf( s, "%d %d\n", &n, &m );
  _Bool* table = (_Bool*)malloc( sizeof(_Bool)*n*n );
  for( size_t i=0; i<n*n; ++i ) table[i] = false;
  for( size_t i=0; i<m; ++i ){
    int x,y;
    fgets( s, sizeof(s), stdin );
    sscanf( s, "%d %d\n", &x, &y );
    --x; --y;
    table[ x*n+y ] = true;
    table[ y*n+x ] = true;
  }

  _Bool* bits = (_Bool*)malloc( sizeof(_Bool)*n );
  printf( "%u\n", func( 0, n, bits, table ) );

  // free
  free(table);
  free(bits);
}