#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Structure d'Arbre AVL
//Structure d'Arbre AVL
typedef struct arbre{
	char identifiant[50]; //identifiant de chaque station : Powerplant,HV-A, HV-B, LV stations
	long capacite; //capacité de la station
	long consommation; //consommation totale
	struct arbre *fg;
	struct arbre *fd;
	int equilibre; //facteur d'équilibre
	int hauteur;
}Arbre;


Arbre *creationarbre(int a); //Création de noeud pour l'arbre AVL
Arbre *equilibrageAVL(Arbre*a); //Insertion de la fonction equilibre si nécessaire
Arbre *insertionAVL(Arbre *a, int e, int *h); //Insertion de l'arbre AVL
Arbre *creationAVLfromCSV(FILE *fichier, int e, int *h); //Création de l'arbre AVL à partir des données de fichier CSV
Arbre *rotationGauche(Arbre *a); //Rotation gauche pour réequilibrer l'arbre
Arbre *rotationDroite(Arbre *a); //Rotation droite pour réequilibrer l'arbre
Arbre *doubleRotationGauche(Arbre *a); //Double Rotation Gauche
Arbre *doubleRotationDroite(Arbre *a); //Double Rotation Droite
int existeFilsGauche(Arbre *a); //Vérification le fils gauche existe
int existeFilsDroite(Arbre *a); //Vérification le fils droite existe
int hauteur(Arbre *a); //Calcul de l'hauteur de l'arbre AVL
void miseAjour_hauteur(Arbre *a); //La mise à jour la hauteur d'un noeud après les modifications

ligne 198



