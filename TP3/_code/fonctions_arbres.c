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

//arbre* arbre_constructeur(int v, arbre *g, arbre *d)
void arbre_source_c(arbre *a){
  if(arbre_est_vide(a)) printf("arbre_vide()");
  else{
    printf("arbre_constructeur(%d, ",arbre_valeur(a));
    arbre_source_c(arbre_gauche(a));
    printf(", ");
    arbre_source_c(arbre_droit(a));
    printf(")");
  }
}


int max(int a, int b){
  if(a > b) return a;
  else return b;
}

int arbre_profondeur(arbre *a){
  if(arbre_est_vide(a)) return 0;

  int prof = max(arbre_profondeur(arbre_gauche(a)), arbre_profondeur(arbre_droit(a)));

  return prof + 1;
}

int arbre_nombre_elements(arbre *a){
  if(arbre_est_vide(a)) return 0;
  return 1 + arbre_nombre_elements(arbre_gauche(a)) + arbre_nombre_elements(arbre_droit(a));
}

liste* arbre_elements(arbre *a) {
  if(arbre_est_vide(a)) return liste_vide();

  liste *l_gauche = liste_vide();
  l_gauche = arbre_elements(arbre_gauche(a));

  liste *l_droit = liste_vide();
  l_droit = arbre_elements(arbre_droit(a));

  liste *result = liste_vide();
  result = ajoute(result, arbre_valeur(a));
  result = liste_concatene(l_gauche, result);
  result = liste_concatene(result, l_droit);

  return result;
}

