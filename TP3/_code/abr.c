#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "fonctions_arbres.h"

abr*
abr_vide()
{ return arbre_vide(); }

int
est_abr_vide(abr *a)
{ return arbre_est_vide(a); }

int abr_cherche(abr *a, int n){ //0 il n'y a pas, 1 il'y a
    if(arbre_valeur(a) == n) return 1;
    else if(arbre_valeur(a) < n){
        if(est_abr_vide(arbre_gauche(a))) return 0;
        return abr_cherche(arbre_gauche(a), n);
    }
    else if(abre_valeur(a) > n){
        if(est_abr_vide(arbre_droit(a))) return 0;
        return abr_cherche(arbre_droit(a), n);
    }
}
  
