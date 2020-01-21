#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int value;
  int num;
} pair;

typedef struct stack_item_tag {
  pair p;
  struct stack_item_tag* front;
  struct stack_item_tag* back;
} stack_item;

typedef struct {
  long long cnt;
  stack_item* last;
} stack;

void init( stack* st ){
  st->cnt = 0;
  st->last = NULL;
}

_Bool empty( stack* st ){ return !st->cnt; }
pair* top( stack* st ){ return &st->last->p; }
void push( stack* st, int value, int num ){
  stack_item* it = (stack_item*)malloc( sizeof(stack_item) );
  it->p.value = value;
  it->p.num = num;
  it->front = st->last;
  it->back = NULL; 
  ++(st->cnt);
  st->last = it;
}
void pop( stack* st ){
  if (empty(st))return;
  if ( st->cnt == 1 ){
    free(st->last);
    st->cnt = 0;
    st->last = NULL;
  } else {
    --(st->cnt);
    st->last = st->last->front;
    free(st->last->back);
    st->last->back = NULL;
  }
}

int main(int argc, char const *argv[]){
  int q, l;
  scanf("%d %d", &q, &l );

  stack st;
  long long st_index = 0;
  init(&st);

  for( int i=0; i<q; ++i ){

    char s[5];
    scanf("%s", s );

    if (!strcmp( s, "Push" )){
      int n,m;
      scanf("%d %d", &n, &m );
      push( &st, m, n );
      st_index += n;
      if ( st_index > l ){
        puts("FULL");
        exit(EXIT_SUCCESS);
      }
    } else if (!strcmp( s, "Pop" )){
      int n;
      scanf("%d", &n );
      st_index -= n;
      if ( st_index < 0 ){
        puts("EMPTY");
        exit(EXIT_SUCCESS);
      }
      while(n){
        if ( top(&st)->num <= n ){
          n -= top(&st)->num;
          pop(&st);
        } else {
          top(&st)->num -= n;
          n = 0;
        }
      }
    } else if (!strcmp( s, "Top" )){
      if ( st_index ){
        printf("%d\n", top(&st)->value );
      } else {
        puts("EMPTY");
        exit(EXIT_SUCCESS);
      }
    } else if (!strcmp( s, "Size" )){
      printf("%lld\n", st_index );
    }

  }

  puts("SAFE");
}