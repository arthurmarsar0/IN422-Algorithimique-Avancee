#include "fonctions_arbres_implicites.h"
#include "arbre.h"
#include "arbre_implicite.h"


#include <stdio.h>

arbre* abi_vers_arbre_aux(abi* a, int index){
    if(index > abi_index_dernier(a)){ 
        return arbre_vide();
    }
    int value = abi_acces(a, index); // 
 
    arbre* sub_left = abi_vers_arbre_aux(a, abi_fils_gauche(index)); //
    arbre* sub_right = abi_vers_arbre_aux(a, abi_fils_droit(index));

    return arbre_constructeur(value, sub_left, sub_right);
 } 

arbre* abi_vers_arbre(abi* a){ 
    int index_root = abi_racine(); 
    return abi_vers_arbre_aux(a, index_root); 
} 