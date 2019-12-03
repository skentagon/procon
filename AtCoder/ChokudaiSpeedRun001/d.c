
#include <stdio.h>

void swapi_alloced( int* a, int* b, int* t ){
  *t = *a;
  *a = *b;
  *b = t;
}

void swapi( int* a, int* b ){
  int t;
  swapi_alloced( a, b, &t );
}

void mergei( int* lbgn, int lsz, int* rbgn, int rsz, int* ans ){
  int ldx = 0, rdx = 0, wdx = 0;
  int* t = (int*)malloc( sizeof(int) * lsz );
  while(1){
    if ( *(lbgn+ldx) > *(rbgn+rdx) ){
      *(ans+wdx) = *(rbgn+rdx);
      ++rdx;
    } else {
      
    }
  }
  free(t);
}

void merge_sorti( int* begin, int size, int* ans ){
  if ( size <= 1 ){ return; }
  if ( size == 2 ){
    if ( *begin > *(begin+1) ){ swapi( begin, begin+1 ); }
    return;
  }
  merge_sorti( begin, size/2, ans );
  merge_sorti( begin + size/2, size - size/2, ans + size/2 );
  int t;
  int dx1 = 0, dx2 = 0;
  while(1){

  }
}

int main(void){

  //入力を受け取る
  int n;
  scanf( "&d", &n );
  int* d = (int*)malloc( sizeof(int)*n );
  int* ans = (int*)malloc( sizeof(int)*n );
  for( int i=0; i<n; ++i ){
    scanf( "%d", d[i] );
  }

  //sort

  //出力
  for( int i=0; i<n; ++i ){
    printf( "%d ", d[i] );
  }
  puts("");
}