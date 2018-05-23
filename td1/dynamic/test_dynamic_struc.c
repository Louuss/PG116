#include "set_dynamic.h"
#include <stdlib.h>
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

int test_set__empty()
{
  printf("Test empty : " );
  int result=1;
  struct set *s = set__empty();
  result = result && compare(s->size, 0, "Le set n'est pas vide ");
  set__free(s);
  return test(result);


}

int test_set__is_empty()
{
  printf("Test is_empty :  " );

  struct set *s = set__empty();
  int result = compare(set__is_empty(s), 1, "Reconnait pas un set vide ");

  struct set *s2 =set__empty();
  set__add(s2, 10);
  int result2 = compare(set__is_empty(s2), 0, "Reconnait pas un set non vide ");

  set__free(s);
  set__free(s2);

  return test(result && result2);
}

int test_set__add()
{
  printf("Test add :  " );

  struct set *s1 = set__empty();
  set__add(s1, 10);
  int result = compare(s1->s[0], 10, "Premier element pas le bon ");
  int result1 = compare(s1->size, 1, "Taille pas bonne ");

  set__free(s1);

  return test(result && result1);
}

int test_set__remove()
{
  printf("Test remove : ");
  int result = 1;
  struct set *s = set__empty();
  set__add(s, 10);
  set__remove(s, 10);

  result = result && compare(s->size, 0, "Element mal enlevé ");
  set__free(s);

  return test(result);
}

int main() {
printf("\n___________________________________________\n\n\033[34m          Test structurel dynamic          \033[0m\n___________________________________________\n\n" );
    int r1 = test_set__empty();
    int r2 = test_set__is_empty();
    int r3 = test_set__add();
    int r4 = test_set__remove();

  if( r1 &&
      r2 &&
      r3 &&
      r4 )
      printf("\033[32mTOUT PASSE\033[0m\n" );

    else
    printf("\033[31mPASSE PAS\033[0m\n");

  return 0;
}
