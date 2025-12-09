#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "abr.h"
#include "fonctions_arbres.h"
#include "liste_chainee.h"

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

    else if(n <= arbre_valeur(a)){
        return arbre_constructeur(arbre_valeur(a), abr_insere(arbre_gauche(a), n),arbre_droit(a));
    } else {
        return arbre_constructeur(arbre_valeur(a),arbre_gauche(a), abr_insere(arbre_droit(a), n));
    }

}

int abr_max(abr *a){
    if(est_abr_vide(a)) {
        exit(1);
    }

    if(est_abr_vide(arbre_droit(a))) return arbre_valeur(a);
    else return abr_max(arbre_droit(a));

    int result = abr_max(a);
    return result;
}

abr* abr_retire_aux(abr *a, int n){
    if(est_abr_vide(a)){
        printf("Abr vide\n");
        exit(1);
    } else if(abr_cherche(a, n) == 0){
        printf("Element %d est pas sur cet arbre\n", n);
        exit(1);
    }

    // printf("valeur: %d || n: %d\n", arbre_valeur(a), n);
    if(arbre_valeur(a) == n){
        // printf("achou\n");
        if(!est_abr_vide(arbre_gauche(a))) {
            abr* a_gauche = arbre_gauche(a);
            int max = abr_max(a_gauche);
            return arbre_constructeur(max, abr_retire_aux(a_gauche, max), arbre_droit(a));
        }
        else if (!est_abr_vide(arbre_droit(a))) return arbre_constructeur(arbre_valeur(arbre_droit(a)), arbre_gauche(arbre_droit(a)), arbre_droit(arbre_droit(a))); //If arbre_gauche is empty, just copy what is the rigth side.
        else return arbre_vide();
    } else if (n < arbre_valeur(a)){
        // printf("esquerda\n");
        return arbre_constructeur(arbre_valeur(a), abr_retire_aux(arbre_gauche(a), n), arbre_droit(a));
    } else {
        // printf("direita\n");
        return arbre_constructeur(arbre_valeur(a), arbre_gauche(a), abr_retire_aux(arbre_droit(a), n));
    }
}

abr* abr_retire(abr* a, int n){
    while(abr_cherche(a, n) == 1){
        a = abr_retire_aux(a, n);
    }
    return a;
}

int tentative(int n){

    abr* dates = arbre_vide();
    for(int i = 0; i < n; i++){
        int date = rand() % 365;
        dates = abr_insere(dates, date);
    }
    // arbre_affiche(dates);

    liste *l = arbre_elements(dates);
    // liste_affiche(l);

    while(!liste_est_vide(reste(l))){
        // printf("%d e %d \n", premier(l), premier(reste(l)));
        if(premier(l) == premier(reste(l))) return 1;
        l = reste(l);
    }
    return 0;
}
