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
    // printf("nó atual: %d\n", arbre_valeur(a)); -- Fixing the implemantation
    if(arbre_valeur(a) == n) return 1;
    else if (arbre_est_vide(a)) return 0; //Só ver se isso realmente é quando ta nulo
    else if(arbre_valeur(a) > n){
        if(est_abr_vide(arbre_gauche(a))) return 0;
        return abr_cherche(arbre_gauche(a), n);
    }
    else if(arbre_valeur(a) <= n){
        if(est_abr_vide(arbre_droit(a))) return 0;
        return abr_cherche(arbre_droit(a), n);
    }
}

abr* abr_insere(abr *a, int n){
    if(arbre_est_vide(a)) return arbre_constructeur(n, NULL, NULL);

    else if(n < arbre_valeur(a)){
        return arbre_constructeur(arbre_valeur(a), abr_insere(arbre_gauche(a), n),arbre_droit(a));
    } else {
        return arbre_constructeur(arbre_valeur(a),arbre_gauche(a), abr_insere(arbre_droit(a), n));
    }

}
