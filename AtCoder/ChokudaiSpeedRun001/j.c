
#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false 0;

void swapi_malloced( int* a, int* b, int* t ){
  *t = *a;
  *a = *b;
  *b = *t;
}

void bubble_sort_cnt( int* begin, int size, int* cnt ){
  int t;
  _Bool sw = true;
  while(sw){
    sw = false;
    for( int i=0; i<size-1; ++i ){
      if ( *(begin+i) > *(begin+i+1) ){
        swapi_malloced( begin+i, begin+i+1, &t );
        ++*cnt;
        sw = true;
      }
    }
  }
}

int main(void){

  //read input
  int n;
  scanf( "%d", &n );
  int *d = (int*)malloc( sizeof(int)*n );
  for( int i=0; i<n; ++i ){ scanf( "%d", d+i ); }

  //sort
  int ans = 0;
  bubble_sort_cnt( d, n, &ans );

  //output
  printf( "%d\n", ans );
}