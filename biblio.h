#ifndef BIBLIO_H
#define BIBLIO_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Structure d'Arbre AVL
typedef struct arbre{
	long identifiant; //identifiant de chaque station : Powerplant,HV-A, HV-B, LV stations
	long capacite; //capacité de la station
	long consommation; //consommation totale
	struct arbre *fg;
	struct arbre *fd;
	int equilibre; //facteur d'équilibre pour l'arbre AVL
	int hauteur;
}Arbre;


Arbre *creationArbre(long identifiant, const char* capacite, const char* consommation); //Création de noeud pour l'arbre AVL
Arbre *insertionAVL(Arbre *a, long identifiant, long capacite, long consommation); //Insertion de l'arbre AVL
long max(long x, long y); //Fonction pour obtenir la valeur maximale
Arbre *rotationGauche(Arbre *pivot); //Rotation gauche pour réequilibrer l'arbre
Arbre *rotationDroite(Arbre *a); //Rotation droite pour réequilibrer l'arbre
Arbre *doubleRotationGauche(Arbre* a); //Double Rotation Gauche
Arbre *doubleRotationDroite(Arbre* a); //Double Rotation Droite
int hauteur(Arbre* a); //Calcul de l'hauteur de l'arbre AVL
long facteur_equilibre(Arbre* r); //Calcul du facteur d'équilibre
void infixe(Arbre* a, FILE* fichier_resultat); //Parcours en ordre croissant (infixe = parcours en ordre) et écriture dans le fichier de sortie
void freeAVL(Arbre* a); //Libère la mémoire de l'arbre AVL

#endif //BIBLIO_H



