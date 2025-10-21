typedef struct arbre arbre;

arbre*
arbre_vide();

int
arbre_est_vide(arbre *a);
  
arbre*
arbre_constructeur(arbre *g, arbre *d, int v);
  
arbre*
arbre_gauche(arbre *a);

arbre*
arbre_droit(arbre *a);

int
arbre_valeur(arbre *a);

