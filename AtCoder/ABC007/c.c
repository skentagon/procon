
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int x;
  int y;
  int dist;
} pair;
 
typedef struct queue_item_tag {
  pair p;
  struct stack_item_tag *front;
  struct stack_item_tag *back;
} queue_item;
 
typedef struct {
  queue_item* first;
  queue_item* last;
} queue;
 
void init(queue* st){
  st->first = NULL;
  st->last = NULL;
}
 
_Bool empty(queue *st) { return (st->first)==NULL; }
pair* front(queue *st) { return &st->first->p; }
void push(queue *st, int x, int y, int dist){
  queue_item *it = (queue_item *)malloc(sizeof(queue_item));
  it->p.x = x;
  it->p.y = y;
  it->p.dist = dist;
  it->front = st->last;
  it->back = NULL;
  if (empty(st)){
    st->first = it;
  } else {
    st->last->back = it;
  }
  st->last = it;
}
void pop(queue *st) {
  if (empty(st))return;
  if (st->first->back == NULL) {
    free(st->first);
    st->first = NULL;
    st->last = NULL;
  } else {
    st->first = st->first->back;
    free(st->first->front);
    st->first->front = NULL;
  }
}

int main(){
  int r,c,sx,sy,gx,gy;
  char map[51][51];
  queue q;
  init(&q);
  scanf("%d%d\n%d%d%d%d",&r,&c,&sx,&sy,&gx,&gy);
  for( int i=0; i<r; ++i ){
    scanf(" %s",map[i]);
  }
  push(&q,sx,sy,1);
  map[sx-1][sy-1] = '#';
  while(!empty(&q)){
    int tx[] = { 0, 1, 0, -1 };
    int ty[] = { 1, 0, -1, 0 };
    for( int i=0; i<4; ++i ){
      int x = tx[i] + front(&q)->x;
      int y = ty[i] + front(&q)->y;
      if ( x==gx && y==gy ){
        printf("%d\n",front(&q)->dist);
        exit(EXIT_SUCCESS);
      }
      if ( map[x-1][y-1]=='.' ){
        push( &q, x, y, front(&q)->dist+1 );
        map[x-1][y-1] = '#';
      }
    }
    pop(&q);
  }
}