#include "arbre_binaire.h"
#include "liste_chainee.h"

typedef arbre abr;

abr*
abr_vide();

int
est_abr_vide(abr *a);
  
int
abr_cherche(abr *a, int n);

abr*
abr_insere(abr *a, int n);

abr*
abr_retire(abr *a, int n);

