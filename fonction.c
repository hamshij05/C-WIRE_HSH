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
  int identifiant;
  int capacite; //capacité de la station
  int consommation;  //consommation totale
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

//Insertion de la fonction equilibre si nécessaire
Arbre *equilibrageAVL(Arbre*a){
  if(a->equilibre>=2){
    if(a->fd->equilibre>=0){
      return rotationGauche(a);
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

//Créer l'arbre AVL à partir de la fichier CSV
Arbre* creationAVLfromCSV(FILE *fichier, int e, int *h){ // Creation l'arbre AVL à partir des données de la fichier CSV
	if (e== NULL){
		printf("noeud est NULL dans creationAVLfromCSV.\n");
		exit(1);
	}


    while (fscanf(file, "%d;%*d;%*[^;];%*[^;];%f;%*[^\n]", &RouteID, &distance) == 2)
    {
        root = InsertInAVL(root, RouteID, distance, h);
    }

    return root;
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
  int eq_p=pivt->equilibre;

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

//Fonction pour calculer la hauteur de l'arbre AVL
int hauteur(Arbre* a){
  if(a==NULL){
    return 0;
  }
  int hauteur_gauche=hauteur(a->fg);
  int hauteur_droite=hauteur(a->fd);
  return (hauteur_gauche>hauteur_droite?hauteur_gauche:hauteur_droite)+1;
}

//

//La fonction pour mise à jour la hauteur d'un noeud après modification
void miseAjour_hauteur(Arbre *a){
if(a!=NULL){
int hauteur_gauche=hauteur(a->
//La fonction pour le parcourt l'AVL en ordre croissant


//Fonction pour modifier l'élément d'un nœud
void modifierElement(Arbre a, int r) {
    if (a == NULL) {
        printf("Erreur : le nœud est NULL, modification impossible.\n");
        exit(EXIT_FAILURE); //Terminer le programme en cas de nœud NULL
    }
    a->elmt = r;  //Modifier l'élément du nœud
}



//Vid
void freeAVL(pAVL root) 
{
	if (root != NULL) 
	{
		freeAVL(root->left);
		freeAVL(root->right);
		free(root);
	}
}


