
#include <stdio.h>

int main(void){
  int a,b,c,n;
  scanf("%d %d %d %d",&a,&b,&c,&n);
  printf("%d %d %d\n",
    n-a<0 ? 0 : n-a,
    n*2-b<0 ? 0 : n*2-b,
    n*3-c<0 ? 0 : n*3-c
  );
}