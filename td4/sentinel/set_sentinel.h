#ifndef SET_SENTINEL_H
#define SET_SENTINEL_H
#define SET__SIZE 10

struct set {
  void* s[SET__SIZE];
};
#define SENTINEL NULL
#endif
