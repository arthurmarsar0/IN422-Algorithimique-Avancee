#include <stdio.h>
#include "arbre.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"

void
arbre_affiche_aux(arbre *a, int p)
{
  for (int j=0; j<p; j++)
    printf(" ");
  if (arbre_est_vide(a))
  {
    printf("Arbre vide\n");
    return;
  }

  printf("%d\n", arbre_valeur(a));
  if (!(arbre_est_vide(arbre_gauche(a)) && arbre_est_vide(arbre_droit(a))))
  {
    arbre_affiche_aux(arbre_gauche(a), p+2);
    arbre_affiche_aux(arbre_droit(a), p+2);
  }
}

void
arbre_affiche(arbre* a)
{
  arbre_affiche_aux(a, 0);
}

// void
// arbre_source_c_aux(arbre *a)
// {
//   if (arbre_est_vide(a))
//     printf("arbre_vide()");
//   else
//   {
//     printf("arbre_constructeur(");
//     printf("%d, ", arbre_valeur(a));
//     arbre_source_c_aux(arbre_gauche(a));
//     printf(", ");
//     arbre_source_c_aux(arbre_droit(a));
//     printf(")");
//   }
// }

int arbre_profondeur(arbre *a){



  return 1;
}

