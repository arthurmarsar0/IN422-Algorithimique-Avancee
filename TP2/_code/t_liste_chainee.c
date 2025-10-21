#include "liste_chainee.h"
#include "fonctions_listes.h"
#include "tgc.h"
#include <stdio.h>

tgc_t gc;

void
test()
{
  liste *l1, *l2;

  l1 = liste_vide();

  l1 = ajoute(l1, 3);
  l1 = ajoute(l1, 2);
  liste_affiche(l1);

  l2 = liste_vide();
  l2 = ajoute(l2, 6);
  l2 = ajoute(l2, 1);
  l2 = ajoute(l2, 4);
  liste_affiche(l2);
}

int
main(int argc, char **argv)
{
  tgc_start(&gc, &argc);

  test();
}


