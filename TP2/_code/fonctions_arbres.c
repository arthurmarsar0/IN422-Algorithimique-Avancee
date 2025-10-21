#include <stdio.h>
#include "arbre_binaire.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"

void
arbre_affiche_aux(arbre *a, int p)
{
  if (arbre_est_vide(a))
    return;

  for (int j=0; j<p; j++)
    printf(" ");
  printf("%d\n", arbre_valeur(a));
  arbre_affiche_aux(arbre_gauche(a), p+2);
  arbre_affiche_aux(arbre_droit(a), p+2);
}

void
arbre_affiche(arbre* a)
{
  arbre_affiche_aux(a, 0);
}

void
arbre_structure_interne_aux(arbre *a)
{
  if (arbre_est_vide(a))
    printf("Arbre vide");
  else
  {
    printf("Cons(");
    arbre_structure_interne_aux(arbre_gauche(a));
    printf(", ");
    arbre_structure_interne_aux(arbre_droit(a));
    printf(", %d)", arbre_valeur(a));
  }
}

void
arbre_structure_interne(arbre *a)
{
  arbre_structure_interne_aux(a);
  printf("\n");
}

