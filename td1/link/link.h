#ifndef LINK_H
#define LINK_H


typedef struct lelement* lelement;
typedef struct link* link;

struct lelement{
  int data;
  lelement next;
};

struct link{
  lelement head;
};


struct link lnk__empty();
struct lelement* lnk__first(struct link *);

int llm__is_end_mark(struct lelement  *);

int lnk__add_head(struct link * l, struct lelement * e);

struct lelement* lnk__remove_head(struct link *);

int lnk__add_after(struct link *l, struct lelement *ref, struct lelement *add);

struct lelement* lnk__remove_after(struct link *l, struct lelement*  ref);

struct lelement* llm__next(struct lelement* );


#endif
