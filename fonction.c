



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

//Insertion de 
