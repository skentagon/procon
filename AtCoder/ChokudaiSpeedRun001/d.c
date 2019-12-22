
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void mergei( int* lbgn, int lsz, int* rbgn, int rsz, int* tmp ){
  int ldx = 0, rdx = 0, wdx = 0;
  do {
    if ( ( lsz <= ldx ) && ( rsz <= rdx ) )break;
    if ( rdx<rsz ? ( ldx<lsz ? *(lbgn+ldx) < *(rbgn+rdx) : false ) : true ){
      *(tmp+wdx) = *(lbgn+ldx);
      ++ldx;
    } else {
      *(tmp+wdx) = *(rbgn+rdx);
      ++rdx;
    }
  } while( ++wdx );
  for( int i=0; i<lsz+rsz; ++i ){
    *( i<lsz ? lbgn+i : rbgn+(i-lsz) ) = tmp[i];
  }
  return;
}

void merge_sorti_internal( int* begin, int size, int* tmp ){
  if ( size < 2 )return;
  merge_sorti_internal( begin, size/2, tmp );
  merge_sorti_internal( begin + size/2, size - size/2, tmp );
  mergei( begin, size/2, begin + size/2, size - size/2, tmp );
}

void merge_sorti( int* begin, int size ){
  int* tmp = (int*)malloc( sizeof(int)*size );
  merge_sorti_internal( begin, size, tmp );
  free(tmp);
}

int main(void){

  //入力を受け取る
  int n;
  scanf( "%d", &n );
  int* d = (int*)malloc( sizeof(int)*n );
  for( int i=0; i<n; ++i ){
    scanf( "%d", d+i );
  }

  //sort
  merge_sorti( d, n );

  //出力
  for( int i=0; i<n; ++i ){
    printf( "%d ", d[i] );
  }
  printf("\n");

  free(d);
}