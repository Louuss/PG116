#ifndef SET_LINK_H
#define SET_LINK_H
#include "link.h"

#define VERT "\033[32m"
#define NORMAL "\033[0m"
#define ROUGE "\033[31m"

struct set{
  struct link* l;
};


void set__free(struct set*);

#endif
