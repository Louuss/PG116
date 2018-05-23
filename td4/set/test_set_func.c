#include "set.h"
#include <stdio.h>
#if defined(SENTINEL)
#include "../sentinel/set_sentinel.h"
#elif defined(DYNAMIC)
#include "../dynamic/set_dynamic.h"
#elif defined(LINK)
#include "../link/set_link.h"
#endif

//variables definie par l'option -D de gcc exemple -DLINK

int test_empty()
{
  printf("Test empty :  " );
  struct set* s = set__empty();
  
  if (set__is_empty(s)){
    printf(VERT"PASSE \n"NORMAL);
    return 1;
  }

  printf(ROUGE" Is_empty probleme \n"NORMAL);
  return 0;
}

int test_add()
{
  printf("Test add : ");
  struct set *s = set__empty();
  set__add(s, 10);

  if (!set__is_empty(s)){
    printf(VERT"PASSE \n"NORMAL);
    return 1;
  }

  printf(ROUGE" ADD probleme \n"NORMAL);
  return 0;
}

int test_remove()
{
  printf("Test remove : ");
  struct set* s = set__empty();
  set__add(s, 10);
  set__remove(s, 10);
  if (set__is_empty(s)){
    printf(VERT"PASSE \n"NORMAL);
    return 1;
  }

  printf(ROUGE" Is_empty probleme \n"NORMAL);
  return 0;
}

int main()
{
  printf("\n________________________________________\n\n\033[34m          Test fonctionnel          \033[0m\n________________________________________\n\n" );

  int r1 = test_empty();
  int r2 = test_add();
  int r3 = test_remove();

  if (r1&&r2&&r3)
    printf(VERT"TOUT PASSE\n"NORMAL);
  else
    printf(ROUGE"PASSE PAS \n"NORMAL);
  return 0;
}
