#ifndef SET_DYNAMIC_H
#define SET_DYNAMIC_H
#include "../set/set.h"
#include <stdlib.h>


struct set {
  int * s;
  int capacity;
  int size;
};

void set__free(struct set* s);
#endif
