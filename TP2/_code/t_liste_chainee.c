#include "liste_chainee.h"
#include "fonctions_listes.h"
#include "tgc.h"
#include "fusion.h"
#include "liste_chainee_p.h"
#include "parties.h"
#include "subset_sum.h"
#include <stdio.h>

tgc_t gc;


void
test()
{
  liste *l1, *l2;

  l1 = liste_vide();

  l1 = ajoute(l1, 3);
  l1 = ajoute(l1, 2);
  printf("l1: ");
  liste_affiche(l1);

  l2 = liste_vide();
  l2 = ajoute(l2, 6);
  l2 = ajoute(l2, 1);
  l2 = ajoute(l2, 4);

  //Testing the liste_longueur
  int lenght = liste_longueur(l2);
  int lenght2 = liste_longueur(l1);
  printf("l2: ");
  liste_affiche(l2);
  printf("Length of l1 = %d\n", lenght2);
  printf("Length of l2 = %d\n", lenght);

  //Testing the liste_retourne
  liste *l5 = liste_vide();
  l5 = liste_retourne(l1);
  liste *l3 = liste_vide();
  l3 = liste_retourne(l2);
  printf("l1 retourne: ");
  liste_affiche(l5);
  printf("l2 retourne: ");
  liste_affiche(l3);

  //Testing concatenation
  liste *l4 = liste_vide();
  l4 = liste_concatene(l1, l2);
  printf("l1 + l2: ");
  liste_affiche(l4);

  // Testing the tri_fusion;
  l4 = tri_fusion(l4);
  printf("l1 + l2 ordenée: ");
  liste_affiche(l4);

  // Testing the liste_chainee_p
  liste_p *l6 = liste_vide_p();
  int variable1 = 5;
  char variable2 = 'A';
  void *p1 = &l4, *p2 = &variable1, *p3 = &variable2; // Testing if l6 can store multiple types
  
  l6 = ajoute_p(l6, p1);
  l6 = ajoute_p(l6, p2);
  l6 = ajoute_p(l6, p3);
  printf("Printing each pointer: %p %p %p\n", p3, p2, p1);
  liste_affiche_adresse(l6);

  //Étape 5
  //Testing parties.c with l2
  printf("\nÉtape 5:\n");
  liste_p *partiesl2 = parties(l2);
   int nombreDeParties = liste_longueur_p(partiesl2);
  printf("Nombre de parties de l2 = {4, 1, 6} -> %d\n", nombreDeParties);

  //Étape 6
  printf("\nÉtape 6:\n");
  liste_affiche_adresse(partiesl2);

  //Étape 7
  printf("\nÉtape 7:\n");
  //les funtions liste_somme et subset_sum sont sur le subset_sum.h

  //testing liste_somme
  int somme = liste_somme(l2);
  printf("Somme de l2: %d\n", somme);

  //Creation du set
  liste *set = liste_vide();
  set = ajoute(set, 3);
  set = ajoute(set, 6);
  set = ajoute(set, 7);
  set = ajoute(set, 21);
  set = ajoute(set, 43);
  set = ajoute(set, 51);
  set = ajoute(set, 126);

  // En calculant les valeurs comprises entre 100 et 150,
  //on peut les obtenir comme la somme des éléments d'un sous-ensemble de l'ensemble donné.
  int max = 150;
  int min = 100;
  for(int i = min; i < max; i++){
    liste *answer = subset_sum(set, i);
    if(!liste_est_vide(answer)) {
      printf("The number %d can be written as a sum of: ", i);
      liste_affiche(answer);
    }
  }


}


int
main(int argc, char **argv)
{
  tgc_start(&gc, &argc);

  test();
}


