
#include <stdio.h>

int main(void){
  char s[31];
  scanf( "%s", s );
  for( int i=0; i<sizeof(s); ++i ){
    if (!s[i])break;
    switch( s[i] ){
      case 'a':
      case 'i':
      case 'u':
      case 'e':
      case 'o':
        continue;
      default:
        printf( "%c", s[i] );
    }
  }
  printf("\n");
}