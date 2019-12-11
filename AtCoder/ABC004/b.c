
#include <stdio.h>

int main(void){
  char d[16];
  for( int i=0; i<16; ++i ){ scanf( "%c ", &(d[15-i]) ); }
  for( int i=0; i<4; ++i ){
    printf( "%c %c %c %c\n", d[i*4], d[i*4+1], d[i*4+2], d[i*4+3] );
  }
}