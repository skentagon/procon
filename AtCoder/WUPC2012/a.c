
#include <stdio.h>

int main(void){
  int month[] = {
    31, 29, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31
  };
  int ma,da,mb,db;
  scanf("%d %d %d %d", &ma, &da, &mb, &db );

  int ans = db - da;
  for( int i=ma; i<mb; ++i ){
    ans += month[i-1];
  }

  printf("%d\n", ans );
}