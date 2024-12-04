



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


