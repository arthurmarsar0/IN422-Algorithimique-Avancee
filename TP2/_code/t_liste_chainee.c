#include "liste_chainee.h"
#include "fonctions_listes.h"
#include "tgc.h"
#include "fusion.h"
#include "liste_chainee_p.h"
#include "parties.h"
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

  //Testing parties.c with l2
  printf("Étape 5:\n");
  liste_p *partiesl2 = liste_vide_p(); 
  partiesl2 = parties(l2);
  /*
  Está causando segFault em algum momento.
  TODO: Colocar a questão no tradutor para ver se eu to realmente entendendo oq a questão pede
  Ela quer q a gnt tire todos os subconjuntos de uma determinada lista?
  */
  liste_affiche_adresse(partiesl2);
}


int
main(int argc, char **argv)
{
  tgc_start(&gc, &argc);

  test();
}


