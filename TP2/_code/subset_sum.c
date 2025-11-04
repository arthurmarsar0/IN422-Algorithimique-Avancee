#include "fonctions_listes.h"
#include "liste_chainee_p.h"
#include "parties.h"
#include <stdio.h>


int liste_somme(liste *l){
  int somme = 0;
  liste *next = l;

  while(!liste_est_vide(next)){
    // printf("%d ->", somme);
    somme += premier(next);
    // printf("%d\n", somme);
    next = reste(next);
  }

  return somme;
}

liste* subset_sum(liste *l, int n){
    liste *listeVide = liste_vide();
    liste_p *partiesL = parties(l);
    // int nombreDeParties = liste_longueur_p(partiesL);
    while(!liste_est_vide_p(partiesL)){
        liste *head = premier_p(partiesL);
        // liste_affiche(head);
        int partielleSomme = liste_somme(head);
        // printf("%d\n", partielleSomme);
        if(partielleSomme == n) return head;
        partiesL = reste_p(partiesL);
    }

    // return listeVide;
}