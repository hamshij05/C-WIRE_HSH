#include "biblio.h"

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

//Création de nouveau noeud pour l'arbre AVL
Arbre *creationArbre(long identifiant, long capacite, long consommation){
	Arbre*nouveau=malloc(sizeof(Arbre));
	if(nouveau==NULL){
		printf("Erreur d'allocation de mémoire\n");
		exit(1);
	}
	nouveau->identifiant=identifiant;
	nouveau->capacite=capacite;
	nouveau->consommation=consommation;
	nouveau->fg=NULL;
	nouveau->fd=NULL;
	nouveau->equilibre=0;
	nouveau->hauteur=1;
	return nouveau;
}

//Insertion de l'arbre AVL
Arbre *insertionAVL(Arbre *a, long identifiant, long capacite, long consommation){
	if (a==NULL){
		return creationArbre(identifiant, capacite, consommation);
	}
	if(identifiant < a->identifiant){
		a->fg=insertionAVL(a->fg,identifiant,capacite,consommation);
	}
	else if(identifiant > a->identifiant){
		a->fd=insertionAVL(a->fd,identifiant,capacite,consommation);
	}
	else{ //Mise à jour de la consommation et la capacité
		a->consommation+=consommation;
		a->capacite=max(a->capacite,capacite);
		return a;
	}
	//Mise à jour de la hauteur de l'arbre
	a->hauteur = 1 + max(hauteur(a->fg),hauteur(a->fd));
	//Mise à jour de l'équilibre de l'arbre
	long equilibre=facteur_equilibre(a);
	//Cas d'équilibre
	if(equilibre > 1 && identifiant < a->fg->identifiant){
		return rotationDroite(a);
	}
	if(equilibre < -1 && identifiant > a->fd->identifiant){
		return rotationGauche(a);
	}
	if(equilibre > 1 && identifiant > a->fg->identifiant){
		a->fg=rotationGauche(a->fg);
		return rotationDroite(a);
	}
	if(equilibre<-1 && identifiant<a->fd->identifiant){
		a->fd=rotationDroite(a->fd);
		return rotationGauche(a);
	}
	printf("Erreur : échec de l'insertion pour l'identifiant : %ld, capacité : %ld, Consommation : %ld\n", identifiant, capacite, consommation);
	return a;
}


//Prototypes des fonctions pour rotation de Gauche et rotation de Droite 
long max(long x, long y) {
	return (x > y) ? x : y;
}


//Fonction pour calculer la hauteur de l'arbre AVL
int hauteur(Arbre* a){
	if(a==NULL){
		return 0;
	}
	int hauteur_gauche=hauteur(a->fg);
	int hauteur_droite=hauteur(a->fd);
	return (hauteur_gauche > hauteur_droite ? hauteur_gauche : hauteur_droite)+1;
}

//La fonction pour mise à jour la hauteur d'un noeud après les modifications
void miseAjour_hauteur(Arbre *a) {
    if (a!= NULL) {
        a->hauteur = 1 + (hauteur(a->fg) > hauteur(a->fd) ? hauteur(a->fg) : hauteur(a->fd));
    }
}

//Rotation gauche pour rééquilibrer l'arbre
Arbre *rotationGauche(Arbre *pivot){
	Arbre *a = pivot->fd; //a devient le fils droit de pivot
	Arbre *tmp = a->fg; 
	
	a->fg = pivot;
	pivot->fd = tmp;

	//Mise à jour des hauteurs des noeuds
	pivot->hauteur = max(hauteur(pivot->fg),hauteur(pivot->fd))+1;
	a->hauteur = max(hauteur(a->fg),hauteur(pivot->fd))+1;   
	return a; //a devient la nouvelle racine
}

//Rotation droite pour rééquilibrer l'arbre
Arbre *rotationDroite(Arbre *a){
	Arbre* pivot = a->fg; //le fils gauche devient le pivot
	Arbre* tmp = pivot->fd; //le fils droit de pivot
	
	pivot->fd = a; //a devient le fils droit de pivot
	a->fg = tmp; 
	
	//Mise à jour des hauteurs des noeuds
	a->hauteur = max(hauteur(a->fg),(hauteur(a->fd))+ 1;
	pivot->hauteur = max(hauteur(pivot->fg),hauteur(pivot->fd))+ 1);
	return pivot; //le pivot devient la nouvelle racine
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
//Fonction pour la lecture CSV et Insertion dans l’Arbre
Arbre *creationAVLFromCSV(Arbre* a) {
    FILE *file = fopen("c-wire_csv", "r");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier %s\n");
        exit(EXIT_FAILURE);
    }
    int h = 0; //hauteur pour les insertions AVL
    char ligne[1024]; //buffer pour lire les lignes du fichier

    while (fgets(ligne, sizeof(ligne), file)) {
        int e; // Variable pour stocker l'entier lu
        if (sscanf(ligne, "%d", &e) == 1) {
            a = insertionAVL(a, e, &h);
        } 
	else {
            fprintf("Ligne mal formatée ignorée : %s", ligne);
        }
    }
    fclose(file);
    return a;
}



//La fonction qui vérifie si un nœud a un fils gauche
int existeFilsGauche(Arbre *a){
	if(a==NULL){
		return 0;
	}
	if(a->fg != NULL){
		return 1;
	}
	return 0;
}

//La fonction qui vérifie si un nœud a un fils droite
int existeFilsDroite(Arbre *a){
	if(a==NULL){
		return 0;
	}
	if(a->fd != NULL){
		return 1;
	}
	return 0;
}

//Fonction pour modifier l'élément d'un nœud
int modifierElement(Arbre *a, int r) {
	if (a == NULL) {
		printf("Erreur : le nœud est NULL, modification impossible.\n");
		return 0;
	}
	a->elmt = r; //modifier l'élément
	printf("Élément modifié avec succès : %d\n", r); //message de confirmation
	return 1;
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

//Fonction pour afficher les données
void afficherDonnees(Arbre *a, int e) {
	if (a == NULL) {
		printf("L'arbre est vide.\n");
		return;
	}
	Arbre *noeud = recherche(a, e);
	if (noeud != NULL) {
		printf("Élément trouvé : %d, Équilibre : %d, Hauteur : %d\n",noeud->elmt, noeud->equilibre, hauteur(noeud));
	} 
	else {
		printf("Élément non trouvé dans l'arbre.\n");
	}
}

//Fonction suppression
Arbre *suppressionAVL(Arbre *a, int e, int *h){
	Arbre *tmp;
	if (a==NULL){
		*h = 0;
		return a;
	}
	else if (e > a->elmt){ //recherche dans le sous-arbre droit
		a->fd = suppressionAVL(a->fd, e);
	}
	else if(e < a->elmt){ //recherche dans le sous-arbre gauche
		a->fg = suppressionAVL(a->fg, e);
		*h = -*h;
	}
	else if(a->fd!=NULL){ //si le noeud a un fils droit
		a->fd=suppMinAVL(a->fd, h, &(a->elmt));
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
	//Mise à jour et rééquilibrage après suppression
	if(*h!=0){
		a->equilibre+=*h;
		if(a->equilibre==0){
			*h=-1;
		}
		else{
			*h=0;
		}
	}
	return a;
}

//Fonction pour supprimer le plus petit élément dans un arbre AVL
Arbre *suppMinAVL(Arbre *a, int *h, int *pe){
    Arbre *tmp;
    if (a->fg == NULL){ //trouve le plus petit élément
        *pe=a->elmt; //sauvegarde la valeur
        *h=-1; //réduction de la hauteur
        tmp=a;
        a=a->fd; //le sous-arbre droit devient la racine
        free(tmp);
        return a;
    }
    else{
        a->fg=suppMinAVL(a->fg, h, pe); //appel recursif à gauche
        *h=-*h;
    }
    if(*h != 0){
		a->equilibre+=*h; //mise à jour du facteur d'équilibrage
		if(a->equilibre == 0){
		    *h=-1;
		}
		else{
		    *h=0;
		}
    }
    return a;
}

//Parcours infixe
void infixe(Arbre* a){ 
	if (a != NULL){
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


