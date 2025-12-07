#include "arbre.h"
#include "fonctions_arbres.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"
#include "abr.h"
#include "tgc.h"
#include <stdio.h>

tgc_t gc;

void test(){
    arbre* a1 = arbre_constructeur(1, arbre_vide(), arbre_vide());
    arbre* a3 = arbre_constructeur(3, arbre_vide(), arbre_vide());
    arbre* a2 = arbre_constructeur(2, a1, a3);
    arbre* a5 = arbre_constructeur(5, arbre_vide(), arbre_vide());
    arbre* a4 = arbre_constructeur(4, a2, a5);

    arbre_affiche(a4);

    //Printing arbre_source_c
    arbre_source_c(a4);
    printf("\n");

    //Testing arbre_profondeur
    int prof = arbre_profondeur(a4);
    printf("Pronfondour de a4: %d\n", prof);

    //testing arbre_nombre_elements
    printf("Nombre de elements de a4: %d\n", arbre_nombre_elements(a4));

    liste *l = arbre_elements(a4);
    liste_affiche(l);

    //testing cherche function
    abr *a = a4;
    printf("\nEst-que un valeur etre sur cette arbre? (1 oui, 0 pas)\n");
    printf("3: %d\n", abr_cherche(a4, 3));
    printf("6: %d\n\n", abr_cherche(a4, 6));

    //Testing insere function
    abr *teste = abr_insere(a, 6);
    teste = abr_insere(teste, 4);
    teste = abr_insere(teste, 5);
    arbre_affiche(teste);
}

int
main(int argc, char **argv)
{
  tgc_start(&gc, &argc);

  test();
}
