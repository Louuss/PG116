#ifndef SET_H
#define SET_H
#define BUTEE -1
#define SET__SIZE 10
#define SIZE_DYNAMIC 8

#define VERT "\033[32m"
#define NORMAL "\033[0m"
#define ROUGE "\033[31m"

struct set;

struct set * set__empty(); // constructeur
int set__is_empty(const struct set*);// verifie si vide
int set__add(struct set*, void*); // ajoute int au set retourne 0 si ok
int set__size(struct set* s); // retourne la taille
int set__find(const struct set* e, void* n);
int set__remove(struct set* e, void* n);
void set__free(struct set*);
int is_even(void* p);
#endif
