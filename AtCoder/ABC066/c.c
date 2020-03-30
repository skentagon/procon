
#ifndef C_LIST_ll_GENERATOR_HEADER_INCLUDED
#define C_LIST_ll_GENERATOR_HEADER_INCLUDED

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>


struct list_item_ll_internal__ {
  long long value;
  struct list_item_ll_internal__* prev;
  struct list_item_ll_internal__* next;
};
typedef struct list_item_ll_internal__ list_item_ll;

typedef struct {
  list_item_ll* front;
  list_item_ll* back;
  size_t size;
} list_ll;

typedef struct list_item_ll_internal__* list_item_ptr_ll;

void swap_list_ll( list_ll* l, list_ll* r ){ list_ll t = *l; *l = *r; *r = t; }
void swap_list_item_ll( list_item_ll* l, list_item_ll* r ){ list_item_ll t = *l; *l = *r; *r = t; }

list_ll* list_constructor_ll( list_ll* l ){ l->front = l->back = NULL; l->size = 0; return l; };
void list_deconstructor_ll( list_ll* l );
bool list_empty_ll( list_ll* l ){ return l->front == NULL; };
size_t list_size_ll( list_ll* l ){ return l->size; };
//size_t list_max_size_ll( list_ll* l );
list_ll* list_resize_ll( list_ll* l, size_t sz );
list_ll* list_resize_default_ll( list_ll* l, size_t sz, long long* p );
list_item_ll* list_front_ll( list_ll* l ){ return l->front; };
list_item_ll* list_back_ll( list_ll* l ){ return l->back; };
list_item_ll* list_push_front_ll( list_ll* l, long long* p );
list_item_ll* list_push_back_ll( list_ll* l, long long* p );
list_item_ll* list_push_front_empty_ll( list_ll* l );
list_item_ll* list_push_back_empty_ll( list_ll* l );
list_item_ll* list_insert_ll( list_ll* l, list_item_ll* itm, long long* p );
list_item_ll* list_insert_va_ll( list_ll* l, list_item_ll* itm, int num, ... );
list_item_ll* list_insert_multiple_ll( list_ll* l, list_item_ll* itm, int num, long long* p );
list_item_ll* list_pop_front_ll( list_ll* l );
list_item_ll* list_pop_back_ll( list_ll* l );
list_item_ll* list_erase_ll( list_ll* l, list_item_ll* itm );
list_item_ll* list_erase_range_ll( list_ll* l, list_item_ll* bgn, list_item_ll* end );
list_item_ll* list_erase_if_ll( list_ll* l, bool(*f)(list_item_ll*,list_item_ll*) );
list_ll* list_clear_ll( list_ll* l );
void list_swap_ll( list_ll* l, list_ll* r ){ swap_list_ll(l,r); }
void list_swap_item_ll( list_item_ll* l, list_item_ll* r ){ swap_list_item_ll(l,r); }
list_ll* list_splice_ll( list_ll* l, list_item_ll* pos, list_ll* r );
list_ll* list_splice_item_ll( list_ll* l, list_item_ll* pos, list_ll* r, list_item_ll* itm );
//list_ll* list_splice_range_ll( list_ll* l, list_item_ll* pos, list_ll* r, list_item_ll* bgn, list_item_ll* end );
size_t list_remove_ll( list_ll* l, list_item_ll* itm ){ list_erase_ll(l,itm); }
//size_t list_remove_if_ll( list_ll* l, bool(*f)(list_item_ll*) );
//list_ll* list_unique_ll( list_ll* l );
//list_ll* list_unique_if_ll( list_ll* l, bool(*f)(list_item_ll*,list_item_ll*) );
//list_ll* list_merge_ll( list_ll* l, list_ll* r );
//list_ll* list_merge_if_ll( list_ll* l, list_ll* r, bool(*f)(list_int_item*,list_int_item*) );
//list_ll* list_sort_ll( list_ll* l );
//list_ll* list_sort_if_ll( list_ll* l, bool(*f)(list_item_ll*,list_item_ll*) );
//list_ll* list_reverse_ll( list_ll* l );

void list_deconstructor_ll( list_ll* l ){ list_clear_ll(l); }
list_ll* list_resize_ll( list_ll* l, size_t sz ){
  while( list_size_ll(l) > sz ){ list_erase_ll(l,list_back_ll(l)); }
  while( list_size_ll(l) < sz ){ list_push_back_empty_ll(l); }
  return l;
};
list_ll* list_resize_default_ll( list_ll* l, size_t sz, long long* p ){
  while( list_size_ll(l) > sz ){ list_erase_ll(l,list_back_ll(l)); }
  while( list_size_ll(l) < sz ){ list_push_back_ll(l,p); }
  return l;
};
list_item_ll* list_push_front_ll( list_ll* l, long long* p ){
  list_item_ll* t = list_push_front_empty_ll(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_ll* list_push_back_ll( list_ll* l, long long* p ){
  list_item_ll* t = list_push_back_empty_ll(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_ll* list_push_front_empty_ll( list_ll* l ){
  list_item_ll* t = (list_item_ll*)malloc(sizeof(list_item_ll));
  if (!t)return NULL;
  if (list_empty_ll(l)){
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
list_item_ll* list_push_back_empty_ll( list_ll* l ){
  list_item_ll* t = (list_item_ll*)malloc(sizeof(list_item_ll));
  if (!t)return NULL;
  if (list_empty_ll(l)){
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
list_item_ll* list_insert_ll( list_ll* l, list_item_ll* itm, long long* p ){
  list_item_ll* t = (list_item_ll*)malloc(sizeof(list_item_ll));
  if ( t == NULL )return NULL;
  if ( l->back == itm )l->back = t;
  t->next = itm->next;
  t->prev = itm;
  itm->next = t;
  if ( t->next != NULL )t->next->prev = t;
  return t;
};
list_item_ll* list_insert_va_ll( list_ll* l, list_item_ll* itm, int num, ... ){
  va_list args; va_start( args, num );
  list_item_ll* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_ll( l, itr, va_arg(args,long long*) );
  va_end(args);
  return itr;
};
list_item_ll* list_insert_multiple_ll( list_ll* l, list_item_ll* itm, int num, long long* p ){
  list_item_ll* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_ll( l, itr, p );
  return itr;
}
list_item_ll* list_pop_front_ll( list_ll* l ){ list_erase_ll(l,l->front); }
list_item_ll* list_pop_back_ll( list_ll* l ){ list_erase_ll(l,l->back); }
list_item_ll* list_erase_ll( list_ll* l, list_item_ll* itm ){
  list_item_ll* t;
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
list_item_ll* list_erase_range_ll( list_ll* l, list_item_ll* bgn, list_item_ll* end ){
  list_item_ll* t = bgn;
  end->prev = bgn->prev;
  if ( !bgn->prev ){ l->front = end; }
  while( t != end ){
    t = t->next;
    free(t->prev);
    --l->size;
  }
  return end;
};
list_ll* list_clear_ll( list_ll* l ){
  list_item_ll* t = l->front;
  while(t->next){t=t->next;free(t->prev);}
  free(l->back);
  l->front = l->back = NULL;
  l->size = 0;
};
list_ll* list_splice_ll( list_ll* l, list_item_ll* pos, list_ll* r ){
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

// コード本体
#include <stdio.h>

int main(){

  // listの宣言
  list_ll l;
  // listの初期化
  list_constructor_ll(&l);

  int n;
  scanf("%d\n",&n);
  for( int i=0; i<n; ++i ){
    long long a;
    scanf("%lld",&a);
    if (i&0x01){
      list_push_back_ll(&l,&a);
    } else {
      list_push_front_ll(&l,&a);
    }
  }

  puts("hoge");

  if (n&0x01){
    while(!list_empty_ll(&l)){
      printf("%lld ",list_front_ll(&l)->value);
      list_pop_front_ll(&l);
    }
  }else{
    while(!list_empty_ll(&l)){
      printf("%lld ",list_back_ll(&l)->value);
      list_pop_back_ll(&l);
    }
  }
  list_deconstructor_ll(&l);
}