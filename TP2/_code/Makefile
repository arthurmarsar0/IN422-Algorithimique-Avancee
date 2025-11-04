CC=clang -Wall

all: t_liste_chainee

###
# Compilation
###

# Modules ressoures

tgc.o: tgc.h tgc.c

liste_chainee.o: liste_chainee.h liste_chainee.c tgc.h liste_chainee_p.h
fonctions_listes.o: liste_chainee.h fonctions_listes.h fonctions_listes.c tgc.h
fusion.o: liste_chainee.h fonctions_listes.h fusion.h fusion.c tgc.h 
liste_chainee_p.o: liste_chainee_p.h liste_chainee_p.c tgc.h
parties.o: parties.h parties.c liste_chainee.h liste_chainee_p.h tgc.h
subset_sum.o: fonctions_listes.h liste_chainee_p.h tgc.h subset_sum.h subset_sum.c


arbre_binaire.o: arbre_binaire.h arbre_binaire.c tgc.h
fonctions_arbres.o: arbre_binaire.h fonctions_arbres.h fonctions_arbres.c tgc.h

abr.o: abr.h abr.c tgc.h

# Modules pour executables

t_liste_chainee.o: t_liste_chainee.c liste_chainee.h tgc.h fonctions_listes.h fusion.h liste_chainee_p.h parties.h subset_sum.h




###
# Edition de liens
###

t_liste_chainee: t_liste_chainee.o tgc.o liste_chainee.o fonctions_listes.o fusion.o liste_chainee_p.o parties.o subset_sum.o

