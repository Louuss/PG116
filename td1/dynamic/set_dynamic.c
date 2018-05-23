
#include "../set/set.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct set {
  int * s;
  int capacity;
  int size;
};

int t_find(const struct set* e, int n)
{
  if (e->size == 0)
    return 0;

  int i =0;
  for (i=0; i< e->size; i++)
    {
      if (e->s[i]>= n)
        break;  // 2 4 8
    }

  return i;
}
int set__find(const struct set* e, int n)
{
  if (e->size == 0)
    return 0;

  int i =0;
    for (i=0; i< e->size; i++)
    {
      if (e->s[i]>= n)
        break;  // 2 4 8
    }
  return i;
}

void set__shift_right(int s[], int begin, int end)
{
  for(int i = end ; i>=begin; i--)
  {
    s[i+1] = s[i];
  }
}
void set__shift_left(int s[], int begin, int end)
{
  for(int i =begin ; i<=end; i++)
  {
    s[i-1] = s[i];
  }
}

struct set * set__empty()
{
  struct set *s =malloc(sizeof(s));
  s->capacity = SIZE_DYNAMIC;// capacity est le nobre max d'elements
  s->s = malloc(sizeof(s->s) * s->capacity);
  s->size =0; // size est le nombre d'element
  return s;
}

int set__is_empty(const struct set* s)
{
  if (s->size == 0)
    return 1;
  else
    return 0;
}

int set__add(struct set* s, int e)
{
  int pos= t_find(s, e);
  if((pos < s->size) && (0<=pos))
    return 1;
  if(s->s[pos] == e)
    return 1;

  if(s->size < s-> capacity){
    set__shift_right(s->s, pos, s->size-1);
    s->s[pos]=e;
    s->size++;
    return 0;
  }else{
    s->capacity*=2;

    s->s = realloc (s->s, s->capacity * sizeof(*s));
    set__shift_right(s->s, pos, s->size-1);
    s->s[pos]=e;
    s->size++;
    return 0;
  }
}

int set__remove(struct set* e, int n)
{
  if (n == -1)
    return -1;

  unsigned int pos = set__find(e,n);
  if(e->s[pos] == n){
  set__shift_left(e->s, pos+1, e->size-1);
  e->size --;

  }

  if (e->size *2 < e->capacity)
    {
      e->capacity/=2;
      e->s=realloc(e->s,e->capacity * sizeof(int));
    }
    return 0;

}

int set__size(struct set* s)
{
  return s->size;
}

void set__free(struct set* s)
{
  free(s->s);
  free(s);
}
