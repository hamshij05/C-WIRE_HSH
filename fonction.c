#include biblio.h



//Structure d'Arbre AVL
typedef struct arbre{
   int elmt;
   struct arbre *fg;
   struct arbre *fd;
   int equilibre; //facteur d'équilibre
   int hauteur;
}Arbre;

//Structure pour représenter les données électriques
typedef struct electricite{
   int identifiant[50];
   long capacite; //capacité de la station
   long consommation;  //consommation totale
}Electricite;
  
//Création de noeud pour l'arbre AVL
Arbre *creationarbre(int a){
	Arbre*nouveau=malloc(sizeof(Arbre));
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

//Insertion de l'arbre AVL
Arbre *insertionAVL(Arbre *a, int e, int *h){
    if (a==NULL){
        *h=1;
        return creationArbre(e);
    }
    else if(e<a->elmt){
        a->fg=insertionAVL(a->fg,e,h);
        *h=-*h;
    }
    else if(e>a->elmt){
        a->fd=insertionAVL(a->fd,e,h);    
    }
    else{
        *h=0;
        return a;
    }
    if(*h!=0){
        a->equilibre=a->equilibre+*h;
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

/Fonction pour la lecture CSV et Insertion dans l’Arbre
Arbre *creationAVLFromCSV(const char *file) {
    FILE *file=fopen("c-wire_v00.csv", "r");
    if (file==NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    Arbre *a = NULL;
    int h = 0;
    char ligne[1024];
    while (fgets(ligne, sizeof(ligne), file)) {
        int e;
        if (sscanf(ligne, "%d", &e) == 1) {
            a = insertionAVL(a, e, &h);
        }
    }
    fclose(file);
    return a;
}

//Rotation gauche pour rééquilibrer l'arbre
Arbre *rotationGauche(Arbre *a){
  Arbre* pivot=a->fd;
  int eq_a=a->equilibre;
  int eq_p=pivot->equilibre;

  pivot->fg=a;
  a->equilibre=eq_a-max(eq_p,0)-1;
  pivot->equilibre=min(eq_a-2,eq_a+eq_p-2,eq_p-1);
  return pivot;
}

//Rotation droite pour rééquilibrer l'arbre
Arbre *rotationDroite(Arbre *a){
  Arbre* pivot=a->fg;
  int eq_a=a->equilibre;
  int eq_p=pivot->equilibre;

  pivot->fd=a;
  a-equilibre=eq_a-min(eq_p,0)+1;
  pivot->equilibre=max(eq_a+2, eq_a+eq_p+2,eq_p+1);
  return pivot;
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

//Insertion de la fonction equilibre si nécessaire
Arbre *equilibrageAVL(Arbre*a){
	if(a->equilibre>=2){
		if(a->fd->equilibre>=0){
			return rotationGauche(a);
		}
			else{
				return doubleRotationGauche(a);
    }
  }
	else(a->equilibre<=-2){
		if(a-fg-equilibre<=0){
			return rotationDroite(a);
		}
		else{
			return doubleRotationDroite(a);
		}
	}
	return a;
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

//La fonction pour le parcourt l'AVL en ordre croissant


//Fonction pour modifier l'élément d'un nœud
void modifierElement(Arbre a, int r) {
    if (a == NULL) {
        printf("Erreur : le nœud est NULL, modification impossible.\n");
        exit(EXIT_FAILURE); //Terminer le programme en cas de nœud NULL
    }
    a->elmt = r;  //Modifier l'élément du nœud
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
void afficherDonnees(Arbre *a, int e){
    Arbre *noeud = recherche(a, e);
    if (noeud != NULL){
        printf("Élément trouvé : %d, Équilibre : %d, Hauteur : %d\n", noeud->elmt, noeud->equilibre, hauteur(noeud));
    } 
    else{
        printf("Élément non trouvé dans l'arbre.\n");
    }
}

//Fonction suppression
Arbre *supprimerAVL(Arbre *a, int e, int *h) {
	if (a==NULL){
*h = 0;
        return a;
    }
    else if(e > a->elmt){
        a->fg = supprimerAVL(a->fg, e);
        *h = -*h;
    } 
    else if (e > a->elmt){
        a->fd = supprimerAVL(a->fd, e);
    }
else if(existeFilsDroite->a)
		    a->fd=suppMinAVL(a->fd, h, &(a->elmt))
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
        fprintf(fichier, "%d\n", a->elmt);
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


