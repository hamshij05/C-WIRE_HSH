#include "biblio.h"


//Structure d'Arbre AVL
typedef struct Arbre{
   int elmt;
   struct arbre *fg;
   struct arbre *fd;
   int equilibre; //facteur d'équilibre
   int hauteur;
}Arbre;

//Structure pour représenter les données électriques
typedef struct electricite{
   char identifiant[50];
   long capacite; //capacité de la station
   long consommation;  //consommation totale
}Electricite;
  
//Création de noeud pour l'arbre AVL
Arbre *creationArbre(int a){
	Arbre*nouveau=(arbre*)malloc(sizeof(Arbre));
	if(nouveau==NULL){
		exit(1);
	}
	nouveau->elmt=a;
	nouveau->fg=NULL;
	nouveau->fd=NULL;
	nouveau->equilibre=0;
	nouveau->hauteur=1;
	return nouveau;
}

//Insertion de la fonction equilibre
Arbre *equilibrageAVL(Arbre*a){
	if(a->equilibre>=2){
		if(a->fd->equilibre>=0){
			return rotationGauche(a);
		}
		else{
			return doubleRotationGauche(a);
		}
	}
	else if(a->equilibre<=-2){
		if(a->fg->equilibre<=0){
			return rotationDroite(a);
		}
		else{
			return doubleRotationDroite(a);
		}
	}
	return a;
}

//Insertion de l'arbre AVL
Arbre *insertionAVL(Arbre *a, element e, int *h){
    if (a==NULL){
        *h=1;
        return creationArbre(e);
    }
    else if(e < a->elmt){
        a->fg=insertionAVL(a->fg,e,h);
        *h=-*h;
    }
    else if(e > a->elmt){
        a->fd=insertionAVL(a->fd,e,h);    
    }
    else{
        *h=0;
        return a;
    }
    if(*h!=0){
        a->equilibre+=*h;
        a=equilibrageAVL(a);
        if(a->equilibre==0){
            *h=0;
        }
        else{
            *h=1;
        }
    }
    return a;
}

//Fonction pour la lecture CSV et Insertion dans l’Arbre
Arbre *creationAVLFromCSV(const char *file) {
    FILE *fichier = fopen(file, "r");
    if (fich == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", file);
        exit(EXIT_FAILURE);
    }

    Arbre *a = NULL;
    int h = 0; // Hauteur pour les insertions AVL
    char ligne[1024]; // Buffer pour lire les lignes du fichier

    while (fgets(ligne, sizeof(ligne), f)) {
        int e; // Variable pour stocker l'entier lu
        if (sscanf(ligne, "%d", &e) == 1) {
            a = insertionAVL(a, e, &h);
        } else {
            fprintf(stderr, "Ligne mal formatée ignorée : %s", ligne);
        }
    }

    fclose(f);
    return a;
}

//Prototypes des fonctions pour rotation de Gauche et rotation de Droite 
int min(int a, int b) {
    return (a < b) ? a : b;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}

//Rotation gauche pour rééquilibrer l'arbre
Arbre *rotationGauche(Arbre *a){
	Arbre*pivot;
	int eq_a, eq_p;
	
	pivot = a->fd;
	a->fd = pivot->fg;
	pivot->fg = a;
	eq_a = a->equilibre;
	eq_p = pivot->equilibre;
	a->equilibre = eq_a - max(eq_p, 0) - 1;
	pivot->equilibre = min(eq_a - 2, eq_a + eq_p - 2, eq_p - 1);
	a = pivot;
	return a;
}

//Rotation droite pour rééquilibrer l'arbre
Arbre *rotationDroite(Arbre *a){
	Arbre *pivot;
	int eq_a, eq_p;
	
	pivot = a->fg;
	a->fg = pivot->fd;
	pivot->fd = a;
	eq_a = a->equilibre;
	eq_p = pivot->equilibre;
	a->equilibre = eq_a - min(eq_p, 0) + 1;
	pivot->equilibre = max(eq_a + 2, eq_a + eq_p + 2, eq_p + 1);
	a = pivot;
	return a;
}

//Double rotation gauche
Arbre* doubleRotationGauche(Arbre* a){
    a->fd=rotationDroite(a->fd);
    return rotationGauche(a);
}

//Double rotation droite
Arbre* doubleRotationDroite(Arbre* a){
    a->fg=rotationGauche(a->fg);
    return rotationDroite(a);
}

//Fonction pour calculer la hauteur de l'arbre AVL
int hauteur(Arbre* a){
  if(a==NULL){
    return 0;
  }
  int hauteur_gauche=hauteur(a->fg);
  int hauteur_droite=hauteur(a->fd);
  return (hauteur_gauche>hauteur_droite?hauteur_gauche:hauteur_droite)+1;
}

//La fonction pour mise à jour la hauteur d'un noeud après modification
void miseAjour_hauteur(Arbre *a) {
    if (a!= NULL) {
        a->hauteur = 1 + (hauteur(a->fg) > hauteur(a->fd) ? hauteur(a->fg) : hauteur(a->fd));
    }
}

//Fonction pour modifier l'élément d'un nœud (elle peut etre plus ameliorer)
int modifierElement(Arbre *a, int r) {
    if (a == NULL) {
        fprintf(stderr, "Erreur : le nœud est NULL, modification impossible.\n");
        return 0; // Échec
    }
    a->elmt = r; // Modifier l'élément
    return 1; // Succès
}->elmt = r;  //Modifier l'élément du nœud
}

//Fonction recherche
int recherche(Arbre *a, int e){
	if(a==NULL){
		return NULL;
	}
	if(a->elmt == e){
		return a;
	}
	else if (e < a->elmt){
		return recherche(a->fg,e);
	}
	else {
		return recherche(a->fd,e);
	}
}

//Fonction pour afficher les données (elle verifie tout)
void afficherDonnees(Arbre *a, int e) {
    if (a == NULL) {
        printf("L'arbre est vide.\n");
        return;
    }

    Arbre *noeud = recherche(a, e);
    if (noeud != NULL) {
        printf("Élément trouvé : %d, Équilibre : %d, Hauteur : %d\n",
               noeud->elmt, noeud->equilibre, hauteur(noeud));
    } else {
        printf("Élément non trouvé dans l'arbre.\n");
    }
}

//Il faut finir suppressionAVL, suppressionMin, Existe fils droite et gauche

//Fonction suppression
Arbre *suppressionAVL(Arbre *a, int e, int *h) {
    if (a==NULL){
        *h = 0;
        return a;
    }
    else if (e > a->elmt){
        a->fd = suppressionAVL(a->fd, e);
    }
    else if(e < a->elmt){
        a->fg = suppressionAVL(a->fg, e);
        *h = -*h;
    }
    else if(existeFilsDroite->a){
        a->fd=suppMinAVL(a->fd, h, &(a->elmt))
    }
    else{
        tmp=a;
        a=a->fg;
        free(tmp);
        *h=-1;
        return(a);
    }
    if(a==NULL){
        return a;
    }
    if(*h!=0){
        a->equilibre=a->equilibre+*h;
        if(a->equilibre==0){
            *h=-1;
        }
        else{
            *h=0;
        }
    }
    return a;
}

    else{
        if (a->fg == NULL) {
            Arbre *temp = a->fd;
            free(a);
            *h = -1;
            return temp;
        } else if (a->fd == NULL) {
            Arbre *temp = a->fg;
            free(a);
            *h = -1;
            return temp;
        } else { // Deux enfants
            Arbre *temp = a->fd;
            while (temp->fg != NULL) {
                temp = temp->fg;
            }
            a->elmt = temp->elmt;
            a->fd = supprimerAVL(a->fd, temp->elmt, h);
        }
    }

    if (*h != 0) {
        a->equilibre += *h;
        a = equilibrageAVL(a);
        if (a->equilibre == 0) {
            *h = -1;
        } else {
            *h = 1;
        }
    }
    return a;
}

//Parcours infixe
void infixe(Arbre* a) { 
    if (a != NULL) {
        infixe(a->fg);
        printf("Élément : %d, Équilibre : %d\n", a->elmt, a->equilibre);
        infixe(a->fd);
    }
}

//Fonction pour exporter les données dans un fichier
void exportaCSV(Arbre *a, FILE *fichier) {
    if (a != NULL) {
        exportaCSV(a->fg, fichier);
        fprintf(fichier, "%d;%ld;%ld\n", a->elmt, a->capacite, a->consommation);
        exportaCSV(a->fd, fichier);
    }
}

//Vider l'arbre AVL
void freeAVL(Arbre a){
	if (a != NULL){
		freeAVL(a->fg);
		freeAVL(a->fd);
		free(a);
	}
}

//Vérification l'équilibre 
int verifierEquilibre(Arbre *a) {
    if (a == NULL) {
        return 1;
    }
    int hauteurGauche = hauteur(a->fg);
    int hauteurDroite = hauteur(a->fd);
    int equilibre = hauteurGauche - hauteurDroite;

    if (equilibre < -1 || equilibre > 1) {
        printf("Déséquilibre détecté au nœud %d\n", a->elmt);
        return 0;
    }
    return verifierEquilibre(a->fg) && verifierEquilibre(a->fd);
}

//Fonction pour calculer la somme 
// Fonction pour calculer la somme des consommations totales associées 
long sommeConsommation(Arbre *a, Electricite *data, int taille) {
    if (a == NULL) {
        return 0;
    }

    long somme = 0;

    // Trouver l'identifiant correspondant dans le tableau de structures Electricite
    for (int i = 0; i < taille; i++) {
        if (data[i].identifiant[0] == a->elmt) { // On suppose que identifiant[0] est utilisé comme clé unique
            somme += data[i].consommation;
            break;
        }
    }

    // Parcours infixe pour visiter tous les nœuds
    somme += sommeConsommation(a->fg, data, taille);
    somme += sommeConsommation(a->fd, data, taille);

    return somme;
}

// Fonction pour calculer la somme des consommations totales associées 

long sommeConsommation(Arbre *a, Electricite *data, int taille) {
    if (a == NULL) {
        return 0;
    }

    long somme = 0;

    // Trouver l'identifiant correspondant dans le tableau de structures Electricite
    for (int i = 0; i < taille; i++) {
        if (data[i].identifiant[0] == a->elmt) { // On suppose que identifiant[0] est utilisé comme clé unique
            somme += data[i].consommation;
            break;
        }
    }

    // Parcours infixe pour visiter tous les nœuds
    somme += sommeConsommation(a->fg, data, taille);
    somme += sommeConsommation(a->fd, data, taille);

    return somme;
}



//Fonction pour vérifier la surproduction
// Fonction pour calculer la somme des consommations totales associées 
long sommeConsommation(Arbre *a, Electricite *data, int taille) {
    if (a == NULL) {
        return 0;
    }

    long somme = 0;

    // Trouver l'identifiant correspondant dans le tableau de structures Electricite
    for (int i = 0; i < taille; i++) {
        if (data[i].identifiant[0] == a->elmt) { // On suppose que identifiant[0] est utilisé comme clé unique
            somme += data[i].consommation;
            break;
        }
    }

    // Parcours infixe pour visiter tous les nœuds
    somme += sommeConsommation(a->fg, data, taille);
    somme += sommeConsommation(a->fd, data, taille);

    return somme;
}

// Fonction pour vérifier la surproduction
typedef struct surproduction {
    int identifiant;
    long difference; // Différence entre la capacité et la consommation
} Surproduction;

void verifierSurproduction(Arbre *a, Electricite *data, int taille) {
    if (a == NULL) {
        return;
    }

    // Trouver l'identifiant correspondant dans le tableau de structures Electricite
    for (int i = 0; i < taille; i++) {
        if (data[i].identifiant[0] == a->elmt) {
            long difference = data[i].capacite - data[i].consommation;
            if (difference < 0) {
                printf("Surproduction détectée pour l'identifiant %d : excès de %ld\n", data[i].identifiant[0], -difference);
            }
            break;
        }
    }

    // Vérifier la surproduction pour les sous-arbres
    verifierSurproduction(a->fg, data, taille);
    verifierSurproduction(a->fd, data, taille);
}


