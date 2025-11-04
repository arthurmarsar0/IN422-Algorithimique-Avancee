#include "fonctions_listes.h"
#include "liste_chainee_p.h"
#include "parties.h"
#include <stdio.h>


int liste_somme(liste *l){
  int somme = 0;
  liste *next = l;

  while(!liste_est_vide(next)){
    somme += premier(next);
    next = reste(next);
  }

  return somme;
}

liste* subset_sum(liste *l, int n){
    liste *listeVide = liste_vide();
    liste_p *partiesL = parties(l);

    while(!liste_est_vide_p(partiesL)){
        liste *head = premier_p(partiesL);
        int partielleSomme = liste_somme(head);
        if(partielleSomme == n) return head;
        partiesL = reste_p(partiesL);
    }
}