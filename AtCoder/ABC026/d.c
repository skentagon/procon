
#include <stdio.h>
#include <math.h>
#include <float.h>

int main(void){

  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  double bgn = 0.0;
  double end = 2000.0;

  while(1){
    double t = 0.5 * (bgn+end);
    if ( 100.0 < a*t + b*sin(c*t*M_PI) ){
      end = t;
    }else{
      bgn = t;
    }
    if ( end-bgn < 0.000000000001 )break;
  }
  printf("%.10f\n",bgn);

}