#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "fonctions_arbres.h"

abr*
abr_vide()
{ return arbre_vide(); }

int
est_abr_vide(abr *a)
{ return arbre_est_vide(a); }
  
