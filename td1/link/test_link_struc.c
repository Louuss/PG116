#include "set_link.h"
#include <stdio.h>


int compare(int a, int b, char* message)
{
  if(a != b)
  {
    printf("\033[31m%s\033[0m"  ,message );
    return 0;
  }
  return 1;
}

int test(int r)
{
  if (r)
    printf(" PASSE \n");
  else
    printf(" PASSE PAS \n");

  return r;
}

int test_lnk__empty()
{
  printf("Test empty : ");
  struct link l = lnk__empty();

  return test(compare(
    (long)l.head->next,
    (long)l.head,
    " Tete pas sentinelle "));
}

int test_lnk__first()
{
  printf("Test first : ");
  struct lelement e = {12, NULL};
  struct link l = { &e};

  return test(compare(
    (long)&e,
    (long)lnk__first(&l),
    " Premier element pas le bon "));
}

int test_llm__is_end_mark()
{
  printf("Test is_end_mark : ");
  struct lelement e = {12, &e};
  struct lelement e2 = {12, &e};

  int r1 = compare(1,
    llm__is_end_mark(&e),
    " Reconnait pas la sentinelle");

  int r2 = compare(
    0,
    llm__is_end_mark(&e2),
    " Indique sentinelle sur non sentinelle");

  return test (r1 && r2);
}

int test_lnk__add_head()
{
  printf("Test add_head : ");
  struct lelement e1 = {12, &e1};
  struct lelement e2 = {51, &e1};
  struct link l ={&e1};
  lnk__add_head(&l,&e2);
  return test(compare(
    e2.data,
    l.head->data,
    " Le premier n'est pas le bon"));
}

int test_lnk__remove_head()
{
  printf("Test remove__head : ");
  struct lelement e1 = {12, &e1};
  struct lelement e2 = {51, &e1};
  struct link l ={&e2};

  lnk__remove_head(&l);
  return test(
    compare((long)&e1,
    (long)l.head,
    " La tête n'est pas la bonne"));
}

int test_llm__next()
{
  printf("Test llm__next : ");
  struct lelement e1 = {12, &e1};
  struct lelement e2 = {51, &e1};

  return test(compare(
    (long)&e1,
    (long)e2.next,
    " Le suivant n'est pas le bon"));
}

int test_lnk__add_after()
{
  printf("Test add_after : ");
  struct lelement e1 = {12, &e1};
  struct lelement e2 = {51, &e1};
  struct lelement e3 = {55, NULL};
  struct link l = {&e2};
  lnk__add_after(&l,&e2, &e3);

  return test(compare(
    (long)e2.next,
    (long)&e3,
    " Le suivant n'est pas le bon"));
}

int test_lnk__remove_after()
{
  printf("Test remove_after : ");
  struct lelement e1 = {12, &e1};
  struct lelement e3 = {55, &e1}; // e2->e3->e1
  struct lelement e2 = {51, &e3};
  struct link l = {&e3};
  struct lelement* e4 = lnk__remove_after(&l, &e2);

  int res = compare(
    (long)e4,
    (long)&e3,
    " Retourne le mauvais element");

  return test(res && compare(
    (long)e2.next,
    (long)&e1,
    " Le suivant n'est pas le bon"));
}


int main()
{
  printf("\n________________________________________\n\n\033[34m          Test structurel link          \033[0m\n________________________________________\n\n" );
  int r1 = test_lnk__empty();
  int r2 = test_lnk__first();
  int r3 = test_llm__is_end_mark();
  int r4 = test_lnk__add_head();
  int r5 = test_lnk__remove_head();
  int r6 = test_llm__next();
  int r7 = test_lnk__remove_after();
  if (r1&&r2&&r3&&r4&&r5&&r6&&r7)
    printf(VERT"TOUT PASSE\n"NORMAL);
  else
    printf(ROUGE"Passe pas\n"NORMAL);
  return 0;
}
