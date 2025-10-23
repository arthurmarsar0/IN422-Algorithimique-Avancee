#include <stdio.h>
#include "liste_chainee_p.h"
#include "tgc.h"

extern  tgc_t gc;

struct liste_p {
  void *pointer;
  liste_p *suivante;
};
  
liste_p* liste_vide_p()
{ return NULL; }

int liste_est_vide_p(liste_p *l)
{ return (l == NULL); }

liste_p* alloue_p()
{
  liste_p *r = tgc_alloc(&gc, sizeof(liste_p));
  if (r == NULL) {
    fprintf(stderr, "alloue(): impossible"
      " d'allouer de la memoire!\n");
    exit(1);
  }
  return r;
}

void non_vide_p(liste_p *l, char *str)
{
  if (l == NULL) {
    fprintf(stderr, "%s(): la liste_p "
               "est vide!\n", str);
    exit(1);
  }
}

void *premier_p(liste_p *l)
{
  non_vide_p(l, "premier");
  return l->pointer;
}

liste_p* reste_p(liste_p *l)
{
  non_vide_p(l, "reste");
  return l->suivante;
}

liste_p* ajoute_p(liste_p *l, void *n)
{
  liste_p *r = alloue_p();
  r->pointer = n;
  r->suivante = l;
  return r;
}

void liste_affiche_adresse(liste_p *l) //Created for printing to see if the functions is working
{
  while (!liste_est_vide_p(l))
  {
    printf(" %p", premier_p(l));
    l = reste_p(l);
  }
  printf(".\n");
}
