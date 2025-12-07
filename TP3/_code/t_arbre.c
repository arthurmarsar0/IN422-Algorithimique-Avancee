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

    printf("Arbre a:\n");
    arbre_affiche(a4);

    //Printing arbre_source_c
    printf("\nc code for creating a:\n");
    arbre_source_c(a4);
    printf("\n");

    //Testing arbre_profondeur
    int prof = arbre_profondeur(a4);
    printf("Pronfondour de a: %d\n", prof);

    //testing arbre_nombre_elements
    printf("Nombre de elements de a: %d\n", arbre_nombre_elements(a4));

    printf("List containing the elements of a4:\n");
    liste *l = arbre_elements(a4);
    liste_affiche(l);

    //testing cherche function
    abr *a = a4;
    printf("\nEst-que un valeur etre sur l'arbre a? (1 oui, 0 pas)\n");
    printf("3: %d\n", abr_cherche(a4, 3));
    printf("6: %d\n\n", abr_cherche(a4, 6));

    //Testing insere function
    printf("Adding 6, 4 and 5 into a:\n");
    abr *teste = abr_insere(a, 6);
    teste = abr_insere(teste, 4);
    teste = abr_insere(teste, 5);
    arbre_affiche(teste);
    printf("\n");

    //Second abr for testing
    arbre* b1 = arbre_constructeur(1, arbre_vide(), arbre_vide());
    arbre* b3 = arbre_constructeur(3, arbre_vide(), arbre_vide());
    arbre* b2 = arbre_constructeur(2, b1, b3);

    arbre* b7 = arbre_constructeur(7, arbre_vide(), arbre_vide());
    arbre* b9 = arbre_constructeur(9, arbre_vide(), arbre_vide());
    arbre* b8 = arbre_constructeur(8, b7, b9);

    arbre* b5 = arbre_constructeur(5, b2, b8);

    arbre* b13 = arbre_constructeur(13, arbre_constructeur(12, arbre_vide(), arbre_vide()), arbre_constructeur(14, arbre_vide(), arbre_vide()));
    arbre* b15 = arbre_constructeur(15, b13, arbre_constructeur(18, arbre_vide(), arbre_vide()));
    arbre* b10 = arbre_constructeur(10, b5, b15);

    abr* b = b10;
    printf("\nArbre b:\n");
    arbre_affiche(b);
    printf("\n");

    //third abr for testing
    abr* c = arbre_constructeur(1, arbre_vide(), arbre_constructeur(2, arbre_vide(), arbre_constructeur(3, arbre_vide(), arbre_vide())));
    printf("\nArbre c:\n");
    arbre_affiche(c);
    printf("\n");


    //Testing abr_max()
    // printf("Max of b: %d\n", abr_max(b)); // OK
    // arbre* vide = arbre_vide();
    // abr* abr_vide = vide;
    // printf("teste2: %d", abr_max(abr_vide));

    //Testing abr_retire()
    printf("Removing 15 from b\n");
    abr* b_wo_15 = abr_retire(b, 15);
    arbre_affiche(b_wo_15);
    printf("\nRemoving 10 from b\n");
    abr* b_wo_10 = abr_retire(b, 10);
    arbre_affiche(b_wo_10);

    printf("\nRemoving 2 from c\n");
    abr* c_wo_3 = abr_retire(c, 2);
    arbre_affiche(c_wo_3);

    /* abr_retire() still doesn't work for trees with duplicates -- still working on that
    printf("\nCreating a tree with duplicates for testing\n");
    abr* dup = arbre_constructeur(10, arbre_constructeur(10, arbre_vide(), arbre_vide()), arbre_constructeur(11, arbre_vide(), arbre_vide()));
    arbre_affiche(dup);
   
    printf("\nRemoving 10 from tree that has duplicates\n");
    abr* dup_wo_10 = abr_retire(dup, 10);
    arbre_affiche(dup_wo_10);
    */
}

int
main(int argc, char **argv)
{
  tgc_start(&gc, &argc);

  test();
}
