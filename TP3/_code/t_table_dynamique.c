#include "table_dynamique.h"
#include "tgc.h"
#include <stdio.h>

tgc_t gc;

void test(){

    //Calculeate with which Fibonnacci's index the value becomes greater then 1.000.000.000 (Un milliard)

    //Doing the base
    table_dynamique *Fib = table_dynamique_vide();

    printf("Base\n");
    table_dynamique_insere(Fib, 0, 0);
    table_dynamique_insere(Fib, 1, 1);

    //Checking if base is right
    table_dynamique_affiche(Fib);

    int i = 2;
    int compare = 1000000000; //easier to test
    while(1){
        int pred1 = table_dynamique_acces(Fib, i - 1);
        int pred2 = table_dynamique_acces(Fib, i - 2);
        table_dynamique_insere(Fib, i, pred1 + pred2);
        if(pred1 + pred2 > compare) break;
        else i++;
    }
    printf("a partir de indice %d les valeur de la suite de Fibonacci depassent %d\n", i, compare);
    // printf("%d\n", table_dynamique_acces(Fib, i));
    table_dynamique_affiche(Fib);
    table_dynamique_libere(Fib);
}

int
main(int argc, char **argv)
{
  tgc_start(&gc, &argc);

  test();
}
