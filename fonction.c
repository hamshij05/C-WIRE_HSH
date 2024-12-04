


//Structure d'Arbre AVL
typedef struct arbre{
  int elmt;
  struct arbre *fg;
  struct arbre *fd;
  int equilibre;
}Arbre;

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
if(a==NULL){
  *h=1;
  return creationarbre(e);

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


//Fonction pour calculer la hauteur de l'arbre AVL

//

//La fonction pour mise à jour la hauteur d'un noeud apres modification
