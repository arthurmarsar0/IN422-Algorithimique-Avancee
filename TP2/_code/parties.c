#include "liste_chainee.h"
#include "liste_chainee_p.h"
#include "fonctions_listes.h"
#include <stdio.h>
#include <stdbool.h>

liste_p* parties_aux(liste_p* accumulateur, liste* partielle, liste* restants){
    if(restants == NULL) {
        return ajoute_p(accumulateur, partielle);
    }

    void *newRestants = liste_vide_p(); 
    int headValeur; 

    newRestants = reste(restants);
    headValeur = premier(restants);
    accumulateur = parties_aux(accumulateur, partielle, newRestants);
    liste *newPartielle = ajoute(partielle, headValeur);
    accumulateur = parties_aux(accumulateur, newPartielle, newRestants);

    return accumulateur;
}

liste_p* parties(liste *l){ // TODO: Verificar se essa funcão faz sentido ou não
    liste_p *result = liste_vide_p();
    liste* partielle = liste_vide();
    result = parties_aux(result, partielle, l);
    return result;
}