
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} pos;

typedef struct stack_item_tag {
  pos p;
  struct stack_item_tag* front;
  struct stack_item_tag* back;
} stack_item;

typedef struct {
  stack_item* last;
} stack;

void init( stack* st ){ st->last = NULL; }
void push( stack* st, int x, int y ){
  stack_item* it = (stack_item*)malloc(sizeof(stack_item));
}

int main(){
  int h,w,startx,starty;
  scanf("%d%d",&h,&w);
  char map[500][500];
  for( int i=0; i<h; ++i ){
    for( int j=0; j<w; ++j ){
      scanf("%d",&map[i][j]);
      if (map[i][j]=='s'){
        
      }
    }
  }
}