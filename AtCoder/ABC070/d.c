

/*
======================================================
C template generator
	URL : https://github.com/skentagon/c-template-generator.git
======================================================
*/
/*
======================================================
C template generator
	class name : 'treelist'
	type : 'long long'
	mnemonic : 'long_long'
======================================================
*/

#ifndef C_TREELIST_long_long_GENERATOR_HEADER_INCLUDED
#define C_TREELIST_long_long_GENERATOR_HEADER_INCLUDED

/*

tree-list samples
  https://atcoder.jp/contests/abc066/submissions/12287482

*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

typedef struct {
  long long value;
  size_t node;
} treelist_item_long_long;
//typedef struct treelist_item_long_long_internal__ treelist_item_long_long;

/*
======================================================
C template generator
	class name : 'list'
	type : 'treelist_item_long_long'
	mnemonic : 'treelist_item_long_long'
======================================================
*/

#ifndef C_LIST_treelist_item_long_long_GENERATOR_HEADER_INCLUDED
#define C_LIST_treelist_item_long_long_GENERATOR_HEADER_INCLUDED

/*

list samples
  https://atcoder.jp/contests/abc066/submissions/12287482

*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

struct list_item_treelist_item_long_long_internal__ {
  treelist_item_long_long value;
  struct list_item_treelist_item_long_long_internal__* prev;
  struct list_item_treelist_item_long_long_internal__* next;
};
typedef struct list_item_treelist_item_long_long_internal__ list_item_treelist_item_long_long;

typedef struct {
  list_item_treelist_item_long_long* front;
  list_item_treelist_item_long_long* back;
  size_t size;
} list_treelist_item_long_long;

typedef struct list_item_treelist_item_long_long_internal__* list_item_ptr_treelist_item_long_long;


/*
======================================================
C template generator
	class name : 'list'
	type : 'list_item_ptr_treelist_item_long_long'
	mnemonic : 'list_item_ptr_treelist_item_long_long'
======================================================
*/

#ifndef C_UTILITY_list_item_ptr_treelist_item_long_long_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_list_item_ptr_treelist_item_long_long_GENERATOR_HEADER_INCLUDED

void swap_list_item_ptr_treelist_item_long_long( list_item_ptr_treelist_item_long_long* l, list_item_ptr_treelist_item_long_long* r ){ list_item_ptr_treelist_item_long_long t = *l; *l = *r; *r = t; }

#endif
/*
======================================================
C template generator
	class name : 'list'
	type : 'list_treelist_item_long_long'
	mnemonic : 'list_treelist_item_long_long'
======================================================
*/

#ifndef C_UTILITY_list_treelist_item_long_long_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_list_treelist_item_long_long_GENERATOR_HEADER_INCLUDED

void swap_list_treelist_item_long_long( list_treelist_item_long_long* l, list_treelist_item_long_long* r ){ list_treelist_item_long_long t = *l; *l = *r; *r = t; }

#endif
/*
======================================================
C template generator
	class name : 'list'
	type : 'list_item_treelist_item_long_long'
	mnemonic : 'list_item_treelist_item_long_long'
======================================================
*/

#ifndef C_UTILITY_list_item_treelist_item_long_long_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_list_item_treelist_item_long_long_GENERATOR_HEADER_INCLUDED

void swap_list_item_treelist_item_long_long( list_item_treelist_item_long_long* l, list_item_treelist_item_long_long* r ){ list_item_treelist_item_long_long t = *l; *l = *r; *r = t; }

#endif
void list_constructor_treelist_item_long_long( list_treelist_item_long_long* l ){ l->front = l->back = NULL; l->size = 0; };
//void list_constructor_n_treelist_item_long_long( list_treelist_item_long_long* l, size_t n, treelist_item_long_long* t = NULL );
void list_constructor_range_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* begin, list_item_treelist_item_long_long* end );
void list_deconstructor_treelist_item_long_long( list_treelist_item_long_long* l );
bool list_empty_treelist_item_long_long( list_treelist_item_long_long* l ){ return l->front == NULL; };
size_t list_size_treelist_item_long_long( list_treelist_item_long_long* l ){ return l->size; };
//size_t list_max_size_treelist_item_long_long( list_treelist_item_long_long* l );
list_treelist_item_long_long* list_resize_treelist_item_long_long( list_treelist_item_long_long* l, size_t sz );
list_treelist_item_long_long* list_resize_default_treelist_item_long_long( list_treelist_item_long_long* l, size_t sz, treelist_item_long_long* p );
list_item_treelist_item_long_long* list_front_treelist_item_long_long( list_treelist_item_long_long* l ){ return l->front; };
list_item_treelist_item_long_long* list_back_treelist_item_long_long( list_treelist_item_long_long* l ){ return l->back; };
list_item_treelist_item_long_long* list_push_front_treelist_item_long_long( list_treelist_item_long_long* l, treelist_item_long_long* p );
list_item_treelist_item_long_long* list_push_back_treelist_item_long_long( list_treelist_item_long_long* l, treelist_item_long_long* p );
list_item_treelist_item_long_long* list_push_front_empty_treelist_item_long_long( list_treelist_item_long_long* l );
list_item_treelist_item_long_long* list_push_back_empty_treelist_item_long_long( list_treelist_item_long_long* l );
list_item_treelist_item_long_long* list_insert_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm, treelist_item_long_long* p );
list_item_treelist_item_long_long* list_insert_va_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm, int num, ... );
list_item_treelist_item_long_long* list_insert_multiple_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm, int num, treelist_item_long_long* p );
list_item_treelist_item_long_long* list_pop_front_treelist_item_long_long( list_treelist_item_long_long* l );
list_item_treelist_item_long_long* list_pop_back_treelist_item_long_long( list_treelist_item_long_long* l );
list_item_treelist_item_long_long* list_erase_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm );
list_item_treelist_item_long_long* list_erase_range_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* bgn, list_item_treelist_item_long_long* end );
list_item_treelist_item_long_long* list_erase_if_treelist_item_long_long( list_treelist_item_long_long* l, bool(*f)(list_item_treelist_item_long_long*,list_item_treelist_item_long_long*) );
list_treelist_item_long_long* list_clear_treelist_item_long_long( list_treelist_item_long_long* l );
void list_swap_treelist_item_long_long( list_treelist_item_long_long* l, list_treelist_item_long_long* r ){ swap_list_treelist_item_long_long(l,r); }
void list_swap_item_treelist_item_long_long( list_item_treelist_item_long_long* l, list_item_treelist_item_long_long* r ){ swap_list_item_treelist_item_long_long(l,r); }
list_treelist_item_long_long* list_splice_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* pos, list_treelist_item_long_long* r );
list_treelist_item_long_long* list_splice_item_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* pos, list_treelist_item_long_long* r, list_item_treelist_item_long_long* itm );
//list_treelist_item_long_long* list_splice_range_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* pos, list_treelist_item_long_long* r, list_item_treelist_item_long_long* bgn, list_item_treelist_item_long_long* end );
size_t list_remove_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm ){ list_erase_treelist_item_long_long(l,itm); }
//size_t list_remove_if_treelist_item_long_long( list_treelist_item_long_long* l, bool(*f)(list_item_treelist_item_long_long*) );
//list_treelist_item_long_long* list_unique_treelist_item_long_long( list_treelist_item_long_long* l );
//list_treelist_item_long_long* list_unique_if_treelist_item_long_long( list_treelist_item_long_long* l, bool(*f)(list_item_treelist_item_long_long*,list_item_treelist_item_long_long*) );
list_treelist_item_long_long* list_merge_treelist_item_long_long( list_treelist_item_long_long* l, list_treelist_item_long_long* r );
//list_treelist_item_long_long* list_merge_if_treelist_item_long_long( list_treelist_item_long_long* l, list_treelist_item_long_long* r, bool(*f)(list_int_item*,list_int_item*) );
list_treelist_item_long_long* list_sort_treelist_item_long_long( list_treelist_item_long_long* l );
//list_treelist_item_long_long* list_sort_if_treelist_item_long_long( list_treelist_item_long_long* l, bool(*f)(list_item_treelist_item_long_long*,list_item_treelist_item_long_long*) );
//list_treelist_item_long_long* list_reverse_treelist_item_long_long( list_treelist_item_long_long* l );

void list_constructor_range_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* begin, list_item_treelist_item_long_long* end ){
  list_constructor_treelist_item_long_long(l);
  for( list_item_treelist_item_long_long* t=begin; t!=end; t=t->next ){
    list_push_back_treelist_item_long_long(l,&t->value);
  }
}
void list_destructor_treelist_item_long_long( list_treelist_item_long_long* l ){ list_clear_treelist_item_long_long(l); }
void list_deconstructor_treelist_item_long_long( list_treelist_item_long_long* l ){ list_clear_treelist_item_long_long(l); }
list_treelist_item_long_long* list_resize_treelist_item_long_long( list_treelist_item_long_long* l, size_t sz ){
  while( list_size_treelist_item_long_long(l) > sz ){ list_erase_treelist_item_long_long(l,list_back_treelist_item_long_long(l)); }
  while( list_size_treelist_item_long_long(l) < sz ){ list_push_back_empty_treelist_item_long_long(l); }
  return l;
};
list_treelist_item_long_long* list_resize_default_treelist_item_long_long( list_treelist_item_long_long* l, size_t sz, treelist_item_long_long* p ){
  while( list_size_treelist_item_long_long(l) > sz ){ list_erase_treelist_item_long_long(l,list_back_treelist_item_long_long(l)); }
  while( list_size_treelist_item_long_long(l) < sz ){ list_push_back_treelist_item_long_long(l,p); }
  return l;
};
list_item_treelist_item_long_long* list_push_front_treelist_item_long_long( list_treelist_item_long_long* l, treelist_item_long_long* p ){
  list_item_treelist_item_long_long* t = list_push_front_empty_treelist_item_long_long(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_treelist_item_long_long* list_push_back_treelist_item_long_long( list_treelist_item_long_long* l, treelist_item_long_long* p ){
  list_item_treelist_item_long_long* t = list_push_back_empty_treelist_item_long_long(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_treelist_item_long_long* list_push_front_empty_treelist_item_long_long( list_treelist_item_long_long* l ){
  list_item_treelist_item_long_long* t = (list_item_treelist_item_long_long*)malloc(sizeof(list_item_treelist_item_long_long));
  if (!t)return NULL;
  if (list_empty_treelist_item_long_long(l)){
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
list_item_treelist_item_long_long* list_push_back_empty_treelist_item_long_long( list_treelist_item_long_long* l ){
  list_item_treelist_item_long_long* t = (list_item_treelist_item_long_long*)malloc(sizeof(list_item_treelist_item_long_long));
  if (!t)return NULL;
  if (list_empty_treelist_item_long_long(l)){
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
list_item_treelist_item_long_long* list_insert_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm, treelist_item_long_long* p ){
  list_item_treelist_item_long_long* t = (list_item_treelist_item_long_long*)malloc(sizeof(list_item_treelist_item_long_long));
  if ( t == NULL )return NULL;
  if ( l->back == itm )l->back = t;
  t->next = itm->next;
  t->prev = itm;
  itm->next = t;
  if ( t->next != NULL )t->next->prev = t;
  return t;
};
list_item_treelist_item_long_long* list_insert_va_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm, int num, ... ){
  va_list args; va_start( args, num );
  list_item_treelist_item_long_long* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_treelist_item_long_long( l, itr, va_arg(args,treelist_item_long_long*) );
  va_end(args);
  return itr;
};
list_item_treelist_item_long_long* list_insert_multiple_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm, int num, treelist_item_long_long* p ){
  list_item_treelist_item_long_long* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_treelist_item_long_long( l, itr, p );
  return itr;
}
list_item_treelist_item_long_long* list_pop_front_treelist_item_long_long( list_treelist_item_long_long* l ){ list_erase_treelist_item_long_long(l,l->front); }
list_item_treelist_item_long_long* list_pop_back_treelist_item_long_long( list_treelist_item_long_long* l ){ list_erase_treelist_item_long_long(l,l->back); }
list_item_treelist_item_long_long* list_erase_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* itm ){
  list_item_treelist_item_long_long* t;
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
list_item_treelist_item_long_long* list_erase_range_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* bgn, list_item_treelist_item_long_long* end ){
  list_item_treelist_item_long_long* t = bgn;
  end->prev = bgn->prev;
  if ( !bgn->prev ){ l->front = end; }
  while( t != end ){
    t = t->next;
    free(t->prev);
    --l->size;
  }
  return end;
};
list_treelist_item_long_long* list_clear_treelist_item_long_long( list_treelist_item_long_long* l ){
  list_item_treelist_item_long_long* t = l->front;
  if (!t)return l;
  while(t->next){t=t->next;free(t->prev);}
  free(l->back);
  l->front = l->back = NULL;
  l->size = 0;
  return l;
};
list_treelist_item_long_long* list_splice_treelist_item_long_long( list_treelist_item_long_long* l, list_item_treelist_item_long_long* pos, list_treelist_item_long_long* r ){
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
list_treelist_item_long_long* list_sort_treelist_item_long_long( list_treelist_item_long_long* l ){}
list_treelist_item_long_long* list_merge_treelist_item_long_long( list_treelist_item_long_long* l, list_treelist_item_long_long* r ){}

#endif
typedef struct {
  list_treelist_item_long_long* nodes;
  size_t num;
} treelist_long_long;

void treelist_constructor_long_long( treelist_long_long* l, size_t n ){
  l->num = n;
  l->nodes = (list_treelist_item_long_long*)malloc( sizeof(list_treelist_item_long_long) * n );
}
//void treelist_constructor_move_long_long( treelist_long_long* l );
//void treelist_constructor_copy_long_long( treelist_long_long* l );
void treelist_destructor_long_long( treelist_long_long* l );
void treelist_addEdge_long_long( treelist_long_long* l, size_t a, size_t b, long long* t );
long long* treelist_edge_long_long( treelist_long_long* l, size_t a, size_t b );

void treelist_destructor_long_long( treelist_long_long* l ){
  for( size_t i=0; i<l->num; ++i ){
    list_destructor_treelist_item_long_long(&l->nodes[i]);
  }
  free(l->nodes);
}
void treelist_addEdge_long_long( treelist_long_long* l, size_t a, size_t b, long long* t ){
  treelist_item_long_long tmp;
  tmp.value = *t;
  tmp.node = b;
  list_push_back_treelist_item_long_long( &l->nodes[a], &tmp );
  tmp.node = a;
  list_push_back_treelist_item_long_long( &l->nodes[b], &tmp );
}
long long* treelist_edge_long_long( treelist_long_long* l, size_t a, size_t b ){
  for(
    list_item_treelist_item_long_long* v = list_front_treelist_item_long_long(&l->nodes[a]);
    v != list_back_treelist_item_long_long(&l->nodes[a]);
    v = v->next
  ){ if ( v->value.node == b ) return &v->value.value; }
  return NULL;
}

#endif



/*
======================================================
C template generator
	URL : https://github.com/skentagon/c-template-generator.git
======================================================
*/
/*
======================================================
C template generator
	class name : 'list'
	type : 'int'
	mnemonic : 'int'
======================================================
*/

#ifndef C_LIST_int_GENERATOR_HEADER_INCLUDED
#define C_LIST_int_GENERATOR_HEADER_INCLUDED

/*

list samples
  https://atcoder.jp/contests/abc066/submissions/12287482

*/

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

struct list_item_int_internal__ {
  int value;
  struct list_item_int_internal__* prev;
  struct list_item_int_internal__* next;
};
typedef struct list_item_int_internal__ list_item_int;

typedef struct {
  list_item_int* front;
  list_item_int* back;
  size_t size;
} list_int;

typedef struct list_item_int_internal__* list_item_ptr_int;


/*
======================================================
C template generator
	class name : 'list'
	type : 'list_item_ptr_int'
	mnemonic : 'list_item_ptr_int'
======================================================
*/

#ifndef C_UTILITY_list_item_ptr_int_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_list_item_ptr_int_GENERATOR_HEADER_INCLUDED

void swap_list_item_ptr_int( list_item_ptr_int* l, list_item_ptr_int* r ){ list_item_ptr_int t = *l; *l = *r; *r = t; }

#endif
/*
======================================================
C template generator
	class name : 'list'
	type : 'list_int'
	mnemonic : 'list_int'
======================================================
*/

#ifndef C_UTILITY_list_int_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_list_int_GENERATOR_HEADER_INCLUDED

void swap_list_int( list_int* l, list_int* r ){ list_int t = *l; *l = *r; *r = t; }

#endif
/*
======================================================
C template generator
	class name : 'list'
	type : 'list_item_int'
	mnemonic : 'list_item_int'
======================================================
*/

#ifndef C_UTILITY_list_item_int_GENERATOR_HEADER_INCLUDED
#define C_UTILITY_list_item_int_GENERATOR_HEADER_INCLUDED

void swap_list_item_int( list_item_int* l, list_item_int* r ){ list_item_int t = *l; *l = *r; *r = t; }

#endif
void list_constructor_int( list_int* l ){ l->front = l->back = NULL; l->size = 0; };
//void list_constructor_n_int( list_int* l, size_t n, int* t = NULL );
void list_constructor_range_int( list_int* l, list_item_int* begin, list_item_int* end );
void list_deconstructor_int( list_int* l );
bool list_empty_int( list_int* l ){ return l->front == NULL; };
size_t list_size_int( list_int* l ){ return l->size; };
//size_t list_max_size_int( list_int* l );
list_int* list_resize_int( list_int* l, size_t sz );
list_int* list_resize_default_int( list_int* l, size_t sz, int* p );
list_item_int* list_front_int( list_int* l ){ return l->front; };
list_item_int* list_back_int( list_int* l ){ return l->back; };
list_item_int* list_push_front_int( list_int* l, int* p );
list_item_int* list_push_back_int( list_int* l, int* p );
list_item_int* list_push_front_empty_int( list_int* l );
list_item_int* list_push_back_empty_int( list_int* l );
list_item_int* list_insert_int( list_int* l, list_item_int* itm, int* p );
list_item_int* list_insert_va_int( list_int* l, list_item_int* itm, int num, ... );
list_item_int* list_insert_multiple_int( list_int* l, list_item_int* itm, int num, int* p );
list_item_int* list_pop_front_int( list_int* l );
list_item_int* list_pop_back_int( list_int* l );
list_item_int* list_erase_int( list_int* l, list_item_int* itm );
list_item_int* list_erase_range_int( list_int* l, list_item_int* bgn, list_item_int* end );
list_item_int* list_erase_if_int( list_int* l, bool(*f)(list_item_int*,list_item_int*) );
list_int* list_clear_int( list_int* l );
void list_swap_int( list_int* l, list_int* r ){ swap_list_int(l,r); }
void list_swap_item_int( list_item_int* l, list_item_int* r ){ swap_list_item_int(l,r); }
list_int* list_splice_int( list_int* l, list_item_int* pos, list_int* r );
list_int* list_splice_item_int( list_int* l, list_item_int* pos, list_int* r, list_item_int* itm );
//list_int* list_splice_range_int( list_int* l, list_item_int* pos, list_int* r, list_item_int* bgn, list_item_int* end );
size_t list_remove_int( list_int* l, list_item_int* itm ){ list_erase_int(l,itm); }
//size_t list_remove_if_int( list_int* l, bool(*f)(list_item_int*) );
//list_int* list_unique_int( list_int* l );
//list_int* list_unique_if_int( list_int* l, bool(*f)(list_item_int*,list_item_int*) );
list_int* list_merge_int( list_int* l, list_int* r );
//list_int* list_merge_if_int( list_int* l, list_int* r, bool(*f)(list_int_item*,list_int_item*) );
list_int* list_sort_int( list_int* l );
//list_int* list_sort_if_int( list_int* l, bool(*f)(list_item_int*,list_item_int*) );
//list_int* list_reverse_int( list_int* l );

void list_constructor_range_int( list_int* l, list_item_int* begin, list_item_int* end ){
  list_constructor_int(l);
  for( list_item_int* t=begin; t!=end; t=t->next ){
    list_push_back_int(l,&t->value);
  }
}
void list_destructor_int( list_int* l ){ list_clear_int(l); }
void list_deconstructor_int( list_int* l ){ list_clear_int(l); }
list_int* list_resize_int( list_int* l, size_t sz ){
  while( list_size_int(l) > sz ){ list_erase_int(l,list_back_int(l)); }
  while( list_size_int(l) < sz ){ list_push_back_empty_int(l); }
  return l;
};
list_int* list_resize_default_int( list_int* l, size_t sz, int* p ){
  while( list_size_int(l) > sz ){ list_erase_int(l,list_back_int(l)); }
  while( list_size_int(l) < sz ){ list_push_back_int(l,p); }
  return l;
};
list_item_int* list_push_front_int( list_int* l, int* p ){
  list_item_int* t = list_push_front_empty_int(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_int* list_push_back_int( list_int* l, int* p ){
  list_item_int* t = list_push_back_empty_int(l);
  if (!t){ return NULL; }
  t->value = *p;
  return t;
};
list_item_int* list_push_front_empty_int( list_int* l ){
  list_item_int* t = (list_item_int*)malloc(sizeof(list_item_int));
  if (!t)return NULL;
  if (list_empty_int(l)){
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
list_item_int* list_push_back_empty_int( list_int* l ){
  list_item_int* t = (list_item_int*)malloc(sizeof(list_item_int));
  if (!t)return NULL;
  if (list_empty_int(l)){
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
list_item_int* list_insert_int( list_int* l, list_item_int* itm, int* p ){
  list_item_int* t = (list_item_int*)malloc(sizeof(list_item_int));
  if ( t == NULL )return NULL;
  if ( l->back == itm )l->back = t;
  t->next = itm->next;
  t->prev = itm;
  itm->next = t;
  if ( t->next != NULL )t->next->prev = t;
  return t;
};
list_item_int* list_insert_va_int( list_int* l, list_item_int* itm, int num, ... ){
  va_list args; va_start( args, num );
  list_item_int* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_int( l, itr, va_arg(args,int*) );
  va_end(args);
  return itr;
};
list_item_int* list_insert_multiple_int( list_int* l, list_item_int* itm, int num, int* p ){
  list_item_int* itr = itm;
  for( int i=0; i<num; ++i ) itr = list_insert_int( l, itr, p );
  return itr;
}
list_item_int* list_pop_front_int( list_int* l ){ list_erase_int(l,l->front); }
list_item_int* list_pop_back_int( list_int* l ){ list_erase_int(l,l->back); }
list_item_int* list_erase_int( list_int* l, list_item_int* itm ){
  list_item_int* t;
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
list_item_int* list_erase_range_int( list_int* l, list_item_int* bgn, list_item_int* end ){
  list_item_int* t = bgn;
  end->prev = bgn->prev;
  if ( !bgn->prev ){ l->front = end; }
  while( t != end ){
    t = t->next;
    free(t->prev);
    --l->size;
  }
  return end;
};
list_int* list_clear_int( list_int* l ){
  list_item_int* t = l->front;
  if (!t)return l;
  while(t->next){t=t->next;free(t->prev);}
  free(l->back);
  l->front = l->back = NULL;
  l->size = 0;
  return l;
};
list_int* list_splice_int( list_int* l, list_item_int* pos, list_int* r ){
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
list_int* list_sort_int( list_int* l ){}
list_int* list_merge_int( list_int* l, list_int* r ){}

#endif

#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  treelist_long_long tree;
  treelist_constructor_long_long(&tree,n+1);
  for( int i=0; i<n-1; ++i ){
    int a,b;
    long long c;
    scanf("%d%d%lld",&a,&b,&c);
    treelist_addEdge_long_long(&tree,a,b,&c);
  }
  int q,k;
  scanf("%d%d",&q,&k);
  long long dt[10001] = {-1};
  dt[k] = 0ll;
  list_int st;
  list_constructor_int(&st);
  list_push_back_int(&st,&k);
  while(!list_empty_int(&st)){
    list_item_int v = *list_back_int(&st);
    list_pop_back_int(&st);
    for(
      list_item_treelist_item_long_long* w = list_front_treelist_item_long_long(&tree.nodes[v.value]);
      w != list_back_treelist_item_long_long(&tree.nodes[v.value]);
      w = w->next
    ){
      if ( dt[w->value.node] < 0 ){
        dt[w->value.node] = w->value.value + dt[v.value];
        list_push_back_int(&st,&w->value.node);
      }
    }
  }
  for( int i=0; i<q; ++i ){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%lld\n",dt[x]+dt[y]);
  }
  list_deconstructor_int(&st);
  treelist_destructor_long_long(&tree);
}