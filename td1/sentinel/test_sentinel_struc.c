#include "set_sentinel.h"
#include <stdbool.h>
#include <stdio.h>

int t_find(const struct set* e, int n);
int set__find(const struct set*, int);
void set__shift_right(int s[], int begin, int end);
void set__shift_left(int s[], int begin, int end);


void test_set__is_empty()
{
  printf("Test is_empty: " );
  int result = 1;
  struct set *s1 = set__empty();
  if(!set__is_empty(s1)){
    result =0;
    printf("Passe pas\n");
    }

  set__add(s1, 10);

  if(set__is_empty(s1))
    {
      result =0;
      printf("passse pas \n");
    }

    if(result)
      printf(" passe\n");


    set__free(s1);
}

void test_set__find()
{
  printf("Test find:");
  struct set *s1 = set__empty();
  int resultat = 1;
  if (set__find(s1, 10) != 0)
    resultat = 0;

  set__add(s1, 10);
  set__add(s1, 15);


  if (set__find(s1, 10) != 0)
    resultat =0;

  if (set__find(s1, 16) != 2 )
    resultat =0;


    if (resultat)
    printf(" passe \n");

    set__free(s1);
}

void test_set__add() // depassement capacite, ajout negatif, ajout deja present
{
  struct set *s1 = set__empty();
  set__add(s1, 10);

  int resultat = 1;
  if (!(s1->s[set__find(s1, 10)] == 10))
    resultat = 1;
    printf("Test add: ");

    resultat?printf("passe\n"):printf("passe pas\n");
    set__free(s1);
}


void test_set__size()
{
  struct set *s1 = set__empty() ;
  int resultat = 1;
  if (set__size(s1) != 0)
    resultat =0;

  set__add(s1, 10);

  if (set__size(s1) != 1)
    resultat =0;
    printf("Test size: " );
    if(resultat)
    printf("passe\n");
    else
      printf("passe pas\n");

      set__free(s1);
}
void test_set__filter()
{
  printf("TEST FILTER : \n" );

  struct set *s = set__empty();

  for(int i =0; i<6; i++)
  {
    printf("%d\n",i );
    set__add(s, i);
  }
  printf("avant filter \n");
  struct set *s2 = set__filter(s, even);

  for (int i=0; i<set__size(s2); i++)
  {
    printf("i:%d tab:%d\n", i,s2->s[i] );
    if (s2->s[i]%2 != 0)
      printf(ROUGE"PASSE PAS\n" NORMAL );
  }
  set__free(s2);
    printf(VERT"PASSE PAS\n" NORMAL );
    set__free(s2);

}

// =====main====== //
int main() {
  printf("\n________________________________________\n\n\033[34m          Test structurel sentinel          \033[0m\n________________________________________\n\n" );


    test_set__is_empty();
    test_set__find();
    test_set__add();
    test_set__size();
    test_set__filter();


  return 0;
}
