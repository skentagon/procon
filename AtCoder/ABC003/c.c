
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

  int n,k;
  scanf( "%d %d\n", &n, &k );
  int d[100];
  for( int i=0; i<n; ++i ){
    scanf( "%d", &d[i] );
  }

  merge_sorti( d, n );

  double ans = 0;
  for( int i=n-k; i<n; ++i ){
    ans = 0.5 * ( ans + d[i] );
  }

  printf( "%f\n", ans );
}