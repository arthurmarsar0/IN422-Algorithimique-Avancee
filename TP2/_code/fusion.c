#include <stdio.h>
#include "fusion.h"
#include <stdbool.h> //make easier to manipulate booleans

liste *fusion(liste *l1, liste*l2){
    int length1 = liste_longueur(l1);
    int length2 = liste_longueur(l2);
    bool flag = false;

    liste *result = liste_vide();
    int premier1, premier2;

    for(int i = 0; i < length1 + length2; i++){ //TODO: Add a flag to se if is possible to make a control flag to just link both lists insted of going one by one.
        if(!liste_est_vide(l1)) premier1 = premier(l1);
        if(!liste_est_vide(l2)) premier2 = premier(l2);

        flag = false;
        if(!liste_est_vide(l1)){
            if(liste_est_vide(l2) || premier1 <= premier2) flag = true;
        }

        if(flag){
            result = ajoute(result, premier1);
            l1 = reste(l1);
        } else {
            result = ajoute(result, premier2);
            l2 = reste(l2);
        }
    }

    result = liste_retourne(result);

    return result;
}

liste *tri_fusion(liste *l){
    //Quebra da recursão
    if(liste_longueur(l) == 1) return l;

    //Criar cada lista pela metade
    int length = liste_longueur(l);
    liste *lfh, *lsh; //lfh - liste first half, lsh - liste second half
    lfh = liste_vide();
    lsh = liste_vide();
    int temp = 0;
    int i = 0;

    while(!liste_est_vide(l)){
        temp = premier(l);
        if(i < length / 2){
            lfh = ajoute(lfh, temp);
        } else {
            lsh = ajoute(lsh, temp);
        }
        i++;
        l = reste(l);
    }
    // liste_affiche(lfh);
    // liste_affiche(lsh);


    //recursão
    lfh = tri_fusion(lfh);
    lsh = tri_fusion(lsh);
    l = fusion(lfh, lsh);

    return l;
}