#include "../set/set.h"
#include "link.h"
#include <stdio.h>
#include <stdlib.h>

struct set{
  struct link* l;
};


struct set* set__empty()
{
  struct link * l = malloc(sizeof(link));

  *l = lnk__empty();
  struct set *s = malloc(sizeof(struct set));
  s->l = l;

  return s;
}

int set__is_empty(const struct set* s)
{
  if (llm__is_end_mark(s->l->head))
    return 1;
  else
    return 0;
}


int set__add(struct set* s, int n)
{
  struct lelement *courant = s->l->head;
  struct lelement * l = malloc(sizeof(lelement));
  l->data = n;
  if(llm__is_end_mark(s->l->head) || (n<(s->l->head->data)))
    return lnk__add_head(s->l, l);

  while((! llm__is_end_mark(courant->next)) && (n > courant->next->data))
  {
    courant = courant->next;
  }

  lnk__add_after(s->l, courant, l );
  return 0;
}

int set__remove(struct set* e, int n)
{
  struct lelement * courant = e->l->head;
  if (llm__is_end_mark(courant))
  {
    return 1;
  }
  if (courant->data == n)
  {
    lnk__remove_head(e->l);
    return 0;
  }


  while (!llm__is_end_mark(courant->next))
  {
      if (courant->next->data == n)
        {
          struct lelement* rm = lnk__remove_after(e->l,courant);
          free(rm);
          break;
          return 0;
        }
  }
  return 1;
}

int set__size(struct set * s)
{
    int acc = 0;
    struct lelement * l = s->l->head;
    while (!llm__is_end_mark(l)) {
      acc ++ ;
      l=l->next;
    }
    return acc;
}

int set__find (const struct set *e, int n)
{
  struct lelement * courant = e->l->head;
  while (!llm__is_end_mark(courant))
  {
      if(courant->data == n)
        return 1;
  }
  return 0;

}

void set__free(struct set* s)
{
  struct lelement* courant = s->l->head;
  while (!llm__is_end_mark(courant))
  {
    struct lelement* rm = courant;
    courant = courant->next;
    free (rm);
  }
  //  free(courant); // supprime la sentinelle
  free(s);
}
