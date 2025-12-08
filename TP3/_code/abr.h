#include "arbre.h"
// #include "liste_chainee.h"

typedef arbre abr;

abr* abr_vide();

int abr_cherche(abr *a, int n);

abr* abr_insere(abr *a, int n);

// int abr_max(abr* a); //included only to be possible to call at t_arbre for testing

abr* abr_retire(abr *a, int n);

int tentative(int n);

