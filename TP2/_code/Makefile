CC=clang -Wall

all: t_liste_chainee

###
# Compilation
###

# Modules ressoures

tgc.o: tgc.h tgc.c

liste_chainee.o: liste_chainee.h liste_chainee.c tgc.h
fonctions_listes.o: liste_chainee.h fonctions_listes.h fonctions_listes.c tgc.h
fusion.o: liste_chainee.h fonctions_listes.h fusion.h fusion.c tgc.h 
liste_chainee_p: liste_chainee_p.h liste_chainee_p.c tgc.h


arbre_binaire.o: arbre_binaire.h arbre_binaire.c tgc.h
fonctions_arbres.o: arbre_binaire.h fonctions_arbres.h fonctions_arbres.c tgc.h

abr.o: abr.h abr.c tgc.h

# Modules pour executables

t_liste_chainee.o: t_liste_chainee.c liste_chainee.h tgc.h fonctions_listes.h fusion.h liste_chainee_p.h




###
# Edition de liens
###

t_liste_chainee: t_liste_chainee.o tgc.o liste_chainee.o fonctions_listes.o fusion.o liste_chainee_p.o

