CC=clang -Wall
TARGETS=

all: $(TARGETS)

###
# Compilation
###

# Modules ressources

tgc.o: tgc.h tgc.c

liste_chainee.o: liste_chainee.h liste_chainee.c tgc.h
fonctions_listes.o: liste_chainee.h fonctions_listes.h fonctions_listes.c tgc.h

arbre.o: arbre.h arbre.c tgc.h
fonctions_arbres.o: arbre.h fonctions_arbres.h fonctions_arbres.c tgc.h

abr.o: abr.h abr.c tgc.h arbre.h fonctions_arbres.h

utilitaires.o: utilitaires.h utilitaires.c

table_dynamique.o: table_dynamique.h table_dynamique.c utilitaires.h

arbre_implicite.o: arbre_implicite.h arbre_implicite.c table_dynamique.h utilitaires.h

tas.o: tas.h tas.c arbre_implicite.h table_dynamique.h utilitaires.h

# Modules pour executables

t_table_dynamique.o: t_table_dynamique.c table_dynamique.h tgc.h utilitaires.h
t_arbre.o: t_arbre.c arbre.h fonctions_arbres.h tgc.h liste_chainee.h fonctions_listes.h

###
# Edition de liens
###

t_table_dynamique: t_table_dynamique.o table_dynamique.o tgc.o utilitaires.o
t_arbre: t_arbre.o arbre.o fonctions_arbres.o tgc.o liste_chainee.o fonctions_listes.o

clean:
	rm $(TARGETS) *.o
