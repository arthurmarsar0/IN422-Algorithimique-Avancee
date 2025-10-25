#include "liste_chainee.h"
#include "liste_chainee_p.h"
#include "fonctions_listes.h"
#include <stdio.h>
#include <stdbool.h>

liste_p* parties_aux(liste_p* accumulateur, liste* partielle, liste* restants){
    void *newRestants = liste_vide_p(); // Vai criar uma instância do tipo liste_p para guardar cada parte da lista inicial.
    int headValeur; //Valor da cabeça para adicionar no partial e fazer a recursão

    //Si il n'y a pas d'élements restant -> rajoute le partielle courant à accumulateur
    if(restants == NULL) {
        accumulateur = ajoute_p(accumulateur, partielle);
        return accumulateur;
    } else{     //S'il reste des elements -> 2 appel récursifs: 1- prochain elemente de restante ajouté a partielle; 2- ajouté pas
        newRestants = reste(restants);
        accumulateur = parties_aux(accumulateur, partielle, restants); //TODO: Verify if that makes sense, or should I create 2 temporaries and merge together as did in merge sort
        headValeur = premier(restants);
        partielle = ajoute(partielle, headValeur);
        accumulateur = parties_aux(accumulateur, partielle, newRestants);
    }

    return accumulateur;
}

liste_p* parties(liste *l){ // TODO: Verificar se essa funcão faz sentido ou não
    liste_p *result = liste_vide_p();
    liste* partielle = liste_vide();
    result = parties_aux(result, partielle, l);
    return result;
}