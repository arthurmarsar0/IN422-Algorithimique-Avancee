#include "fonctions_listes.h"
#include <stdio.h>


void
liste_affiche(liste *l)
{
  while (!liste_est_vide(l))
  {
    printf(" %d", premier(l));
    l = reste(l);
  }
  printf(".\n");
}

