typedef struct liste_p liste_p;

liste_p*
liste_vide_p();

int
liste_est_vide_p(liste_p *l);
  
liste_p*
ajoute_p(liste_p *l, void *p);
  
void*
premier_p(liste_p *l);

liste_p*
reste_p(liste_p *l);

void liste_affiche_adresse(liste_p *l);

int liste_longueur_p(liste_p *l);

