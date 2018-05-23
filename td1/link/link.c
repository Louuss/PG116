#include "link.h"
#include <stddef.h>

// le cast sert a dire que le pointeur ne sera pas const pour fit la structure
// ici on definit une sentinelle unique pour toutes ls listes
static const struct lelement sentinel = {5, (struct lelement*) &sentinel};
#define SENTINEL ((struct lelement* ) &sentinel)

struct link empty = {SENTINEL};

struct link lnk__empty()
{
  struct link s = {SENTINEL};
  return s ;
}

struct lelement* lnk__first(struct link* l)
{
  return l->head;
}

int llm__is_end_mark(struct lelement* e)
{
  if (e == SENTINEL)
    return 1;


  if (e->next == e)
    return 1;

return 0;

}


int lnk__add_head(struct link * l,struct lelement*  e)
{
  e->next = l->head;
  l->head = e;
  return 0;
}

struct lelement*  lnk__remove_head(struct link * l)
{
  struct lelement* l2 = l->head;
  l->head = l->head->next; // le deuxieme passe en tete
  return l2;
}

struct lelement*  llm__next(struct lelement*  e)
{
  return e->next;
}

// if return 1 ==> error ajout pas fait
int lnk__add_after(struct link *l, struct lelement *ref, struct lelement *add)
{
  if (ref == SENTINEL)
    return 1;

  add->next= ref->next;
  ref->next = add;
  l->head = l->head; // evite un warning
  return 0;
}

struct lelement*  lnk__remove_after(struct link *l, struct lelement*  ref)
{
  if (ref ==SENTINEL)
    return NULL;

  struct lelement* e = ref->next;
  ref->next = ref->next->next;
  l->head = l->head;
  return e;
}
