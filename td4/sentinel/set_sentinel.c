#include "set.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct set {
  int s[SET__SIZE];
};

int set__is_empty(const struct set* s)
{

    return (s->s[0] == BUTEE);
}

struct set *set__empty()
{
  struct set *s = malloc (sizeof(struct set));
  s->s[0] = BUTEE;
  return s;
}


//retourne la position ou devrait se trouver n dans le set e
int t_find(const struct set* e, int n)
{
  int i = 0 ;
  while (e->s[i] < n) {
    if (e->s[i] < 0 )
      break;

    i++;
  }
  return i;
}

int set__find(const struct set* e, void* n)
{
  int pos = t_find(e,n);
  return e->s[pos]==n?1:0;

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
  for(int i = begin ; i <= end; i++)
  {
    s[i-1] = s[i];
  }
}

int set__size(struct set* s)
{
  int i = 0;
  while (s->s[i] != -1) {
  i++;
  }
  return i;
}

int set__remove(struct set* e, void* n)
{
  if( set__is_empty(e))
    return 1;

  int pos = t_find(e,n);

  int fin = set__size(e);

  set__shift_left(e->s,pos+1,fin);
  return 0;
}

int set__add(struct set* e, void* n) // ajoute int au set
{
  int pos = t_find(e, n); // on cherche ou placer n
  int fin = set__size(e);
  if (e->s[pos] == n)
    return pos;

  //decaller le tableau
  set__shift_right(e->s, pos ,fin);
  // placer l'element si il n'y est pas deja
  e->s[pos]=n;
  // retourner sa position
  return pos;
}

int is_even(void* p)
{
  int* x = p;
  return (*x %2 == 0);
}

void set__free(struct set * s)
{
    free(s);
}
