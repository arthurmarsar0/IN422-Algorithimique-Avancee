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

int liste_longueur(liste *l){
  int length = 0;
  liste *next = l;

  while(!liste_est_vide(next)){
    length++;
    next = reste(next);
  }

  return length;
}

liste *liste_retourne(liste *l){
  int length = liste_longueur(l);
  int temp[length];
  int cnt = 0;

  while(!liste_est_vide(l)){
    temp[cnt] = premier(l);
    cnt++;
    l = reste(l);
  }

  liste *l2 = liste_vide();
  for(int j = 0; j <length; j++){
    l2 = ajoute(l2, temp[j]);
  }

  return l2;
}

liste* liste_concatene(liste *l1, liste *l2) {
  int temp = 0;

  l1 = liste_retourne(l1);

  while(!liste_est_vide(l2)){
    temp = premier(l2);
    l2 = reste(l2);
    l1 = ajoute(l1, temp);
  }

  l1 = liste_retourne(l1);
  // liste_affiche(l1);
  return l1;
}