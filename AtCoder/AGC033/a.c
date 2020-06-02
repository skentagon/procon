
typedef struct {
  int x;
  int y;
  int dis;
} pos;




#ifndef C_QUEUE_pos_GENERATOR_HEADER_INCLUDED
#define C_QUEUE_pos_GENERATOR_HEADER_INCLUDED

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>



#ifndef C_LIST_pos_GENERATOR_HEADER_INCLUDED
#define C_LIST_pos_GENERATOR_HEADER_INCLUDED

/*
list samples
  https://atcoder.jp/contests/abc066/submissions/11643502
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>



#ifndef C_UTILITY_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_GENERATOR_HEADER_INCLUDED

void swap_pos( pos* l, pos* r ){ pos t = *l; *l = *r; *r = t; }

#endif
struct list_item_pos_internal__ {
  pos value;
  struct list_item_pos_internal__* prev;
  struct list_item_pos_internal__* next;
};
typedef struct list_item_pos_internal__ list_item_pos;

typedef struct {
  list_item_pos* front;
  list_item_pos* back;
  size_t size;
} list_pos;

typedef struct list_item_pos_internal__* list_item_ptr_pos;

void swap_list_pos( list_pos* l, list_pos* r ){ list_pos t = *l; *l = *r; *r = t; }
void swap_list_item_pos( list_item_pos* l, list_item_pos* r ){ list_item_pos t = *l; *l = *r; *r = t; }

list_pos* list_constructor_pos( list_pos* l ){ l->front = l->back = NULL; l->size = 0; return l; };
void list_deconstructor_pos( list_pos* l );
bool list_empty_pos( list_pos* l ){ return l->front == NULL; };
size_t list_size_pos( list_pos* l ){ return l->size; };
//size_t list_max_size_pos( list_pos* l );
list_pos* list_resize_pos( list_pos* l, size_t sz );
list_pos* list_resize_default_pos( list_pos* l, size_t sz, pos* p );
list_item_pos* list_front_pos( list_pos* l ){ return l->front; };
list_item_pos* list_back_pos( list_pos* l ){ return l->back; };
list_item_pos* list_push_front_pos( list_pos* l, pos* p );
list_item_pos* list_push_back_pos( list_pos* l, pos* p );
list_item_pos* list_push_front_empty_pos( list_pos* l );
list_item_pos* list_push_back_empty_pos( list_pos* l );
list_item_pos* list_insert_pos( list_pos* l, list_item_pos* itm, pos* p );
list_item_pos* list_insert_va_pos( list_pos* l, list_item_pos* itm, int num, ... );
list_item_pos* list_insert_multiple_pos( list_pos* l, list_item_pos* itm, int num, pos* p );
list_item_pos* list_pop_front_pos( list_pos* l );
list_item_pos* list_pop_back_pos( list_pos* l );
list_item_pos* list_erase_pos( list_pos* l, list_item_pos* itm );
list_item_pos* list_erase_range_pos( list_pos* l, list_item_pos* bgn, list_item_pos* end );
list_item_pos* list_erase_if_pos( list_pos* l, bool(*f)(list_item_pos*,list_item_pos*) );
list_pos* list_clear_pos( list_pos* l );
void list_swap_pos( list_pos* l, list_pos* r ){ swap_list_pos(l,r); }
void list_swap_item_pos( list_item_pos* l, list_item_pos* r ){ swap_list_item_pos(l,r); }
list_pos* list_splice_pos( list_pos* l, list_item_pos* pos, list_pos* r );
list_pos* list_splice_item_pos( list_pos* l, list_item_pos* pos, list_pos* r, list_item_pos* itm );
//list_pos* list_splice_range_pos( list_pos* l, list_item_pos* pos, list_pos* r, list_item_pos* bgn, list_item_pos* end );
size_t list_remove_pos( list_pos* l, list_item_pos* itm ){ list_erase_pos(l,itm); }
//size_t list_remove_if_pos( list_pos* l, bool(*f)(list_item_pos*) );
//list_pos* list_unique_pos( list_pos* l );
//list_pos* list_unique_if_pos( list_pos* l, bool(*f)(list_item_pos*,list_item_pos*) );
//list_pos* list_merge_pos( list_pos* l, list_pos* r );
//list_pos* list_merge_if_pos( list_pos* l, list_pos* r, bool(*f)(list_int_item*,list_int_item*) );
//list_pos* list_sort_pos( list_pos* l );
//list_pos* list_sort_if_pos( list_pos* l, bool(*f)(list_item_pos*,list_item_pos*) );
//list_pos* list_reverse_pos( list_pos* l );

void list_deconstructor_pos( list_pos* l ){ list_clear_pos(l); }
list_pos* list_resize_pos( list_pos* l, size_t sz ){
  while( list_size_pos(l) > sz ){ list_erase_pos(l,list_back_pos(l)); }
  while( list_size_pos(l) < sz ){ list_push_back_empty_pos(l); }
  return l;
};
list_pos* list_resize_default_pos( list_pos* l, size_t sz, pos* p ){
  while( list_size_pos(l) > sz ){ list_erase_pos(l,list_back_pos(l)); }
  while( list_size_pos(l) < sz ){ list_push_back_pos(l,p); }
  return l;
};
list_item_pos* list_push_front_pos( list_pos* l, pos* p ){
  list_item_pos* t = list_push_front_empty_pos(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_pos* list_push_back_pos( list_pos* l, pos* p ){
  list_item_pos* t = list_push_back_empty_pos(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_pos* list_push_front_empty_pos( list_pos* l ){
  list_item_pos* t = (list_item_pos*)malloc(sizeof(list_item_pos));
  if (!t)return NULL;
  if (list_empty_pos(l)){
    l->front = l->back = t;
    l->front->prev = l->front->prev = NULL;
  } else {
    l->front->prev = t;
    l->front->prev->next = l->front;
    l->front = l->front->prev;
    l->front->prev = NULL;
  }
  return t;
};
list_item_pos* list_push_back_empty_pos( list_pos* l ){
  list_item_pos* t = (list_item_pos*)malloc(sizeof(list_item_pos));
  if (!t)return NULL;
  if (list_empty_pos(l)){
    l->front = l->back = t;
    l->front->prev = l->front->prev = NULL;
  } else {
    l->back->next = t;
    l->back->next->prev = l->back;
    l->back = l->back->next;
    l->back->next = NULL;
  }
  return t;
};
list_item_pos* list_insert_pos( list_pos* l, list_item_pos* itm, pos* p ){
  list_item_pos* t = (list_item_pos*)malloc(sizeof(list_item_pos));
  if ( t == NULL )return NULL;
  if ( l->back == itm )l->back = t;
  t->next = itm->next;
  t->prev = itm;
  itm->next = t;
  if ( t->next != NULL )t->next->prev = t;
  return t;
};
list_item_pos* list_insert_va_pos( list_pos* l, list_item_pos* itm, int num, ... ){
  va_list args; va_start( args, num );
  list_item_pos* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_pos( l, itr, va_arg(args,pos*) );
  va_end(args);
  return itr;
};
list_item_pos* list_insert_multiple_pos( list_pos* l, list_item_pos* itm, int num, pos* p ){
  list_item_pos* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_pos( l, itr, p );
  return itr;
}
list_item_pos* list_pop_front_pos( list_pos* l ){ list_erase_pos(l,l->front); }
list_item_pos* list_pop_back_pos( list_pos* l ){ list_erase_pos(l,l->back); }
list_item_pos* list_erase_pos( list_pos* l, list_item_pos* itm ){
  list_item_pos* t;
  if ( itm->prev ){
    if ( itm->next ){
      itm->prev->next = itm->next;
      t = itm->next;
    } else {
      itm->prev->next = NULL;
      l->back = itm->prev;
      t = itm->prev;
    }
  } else {
    if ( itm->next ){
      itm->next->prev = NULL;
      l->front = itm->next;
      t = itm->next;
    } else { l->front = l->back = t = NULL; }
  }
  free(itm); --l->size;
  return t;
};
list_item_pos* list_erase_range_pos( list_pos* l, list_item_pos* bgn, list_item_pos* end ){
  list_item_pos* t = bgn;
  end->prev = bgn->prev;
  if ( !bgn->prev ){ l->front = end; }
  while( t != end ){
    t = t->next;
    free(t->prev);
    --l->size;
  }
  return end;
};
list_pos* list_clear_pos( list_pos* l ){
  list_item_pos* t = l->front;
  if (!t)return l;
  while(t->next){t=t->next;free(t->prev);}
  free(l->back);
  l->front = l->back = NULL;
  l->size = 0;
  return l;
};
list_pos* list_splice_pos( list_pos* l, list_item_pos* pos, list_pos* r ){
  if (r->size){
    l->size +=  r->size;
    r->front->prev = pos;
    r->back->next = pos->next;
    pos->next->prev = r->back;
    pos->next = r->front;
    r->front = r->back = NULL;
    r->size = 0;
  }
  return l;
};

#endif
typedef list_item_pos queue_item_pos;
typedef list_pos queue_pos;

queue_pos* queue_constructor_pos( queue_pos* l ){ return list_constructor_pos(l); }
void queue_deconstructor_pos( queue_pos* l ){ list_deconstructor_pos(l); }

bool queue_empty_pos( queue_pos* l ){ return list_empty_pos(l); }
size_t queue_size_pos( queue_pos* l ){ return list_size_pos(l); }
//size_t queue_max_size_pos( queue_pos* l ){ return list_size_pos(l); }
queue_item_pos* queue_front_pos( queue_pos* l ){ return list_front_pos(l); }
queue_item_pos* queue_back_pos( queue_pos* l ){ return list_back_pos(l); };
queue_item_pos* queue_push_pos( queue_pos* l, pos* p ){ return list_push_back_pos(l,p); }
queue_item_pos* queue_pop_pos( queue_pos* l ){ return list_pop_front_pos(l); }
queue_pos* queue_clear_pos( queue_pos* l ){ return list_clear_pos(l); }
//void queue_swap_pos( queue_pos* l, queue_pos* r ){ swap_queue_pos(l,r); }
//void queue_swap_item_pos( queue_item_pos* l, queue_item_pos* r ){ swap_queue_item_pos(l,r); }

#endif

#include <stdio.h>

char a[1000][1001];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(){
  int h,w;
  queue_pos q;
  queue_constructor_pos(&q);
  scanf("%d %d\n",&h,&w);
  for( int x=0; x<h; ++x ){
    scanf( "%s", a[x] );
    for( int y=0; y<w; ++y ){
      if ( a[x][y] == '#' ){
        pos p;
        p.x = x; p.y = y; p.dis = 0;
        queue_push_pos(&q,&p);
      }
    }
  }
  int ans = 0;
  while(!queue_empty_pos(&q)){
    pos p = queue_front_pos(&q)->value;
    pos d = p;
    for( int i=0; i<4; ++i ){
      d.x = p.x + dx[i];
      d.y = p.y + dy[i];
      d.dis = p.dis + 1;
      if ( 0 <= d.x && d.x < h && 0 <= d.y && d.y < w && a[d.x][d.y] != '#' ){
        a[d.x][d.y] = '#';
        queue_push_pos(&q,&d);
        ans = d.dis;
      }
    }
    queue_pop_pos(&q);
  }
  printf("%d\n",ans);
  queue_deconstructor_pos(&q);
}