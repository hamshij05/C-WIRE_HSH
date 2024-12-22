#include <biblio.h>

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

long max(long x, long y) {
    return (x > y) ? x : y;
}
int hauteur (Arbre* a){
  if(a!=NULL){
    return max(hauteur(a->fg),hauteur(a->fd))+1;
  } 
  return -1;
}
//Fonction pour calculer le facteur équilibre
int facteur_equilibre(Arbre* r){
  return r ? hauteur(r->fd) - hauteur(r->fg) : 0;
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
  a->hauteur = max(hauteur(a->fg),(hauteur(a->fd)))+ 1;
  pivot->hauteur = max(hauteur(pivot->fg),hauteur(pivot->fd))+ 1;
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
//Création de nouveau noeud pour l'arbre AVL
Arbre *creationArbre(long identifiant, const char* capacite, const char* consommation){
  Arbre*nouveau=malloc(sizeof(Arbre));
  if(nouveau==NULL){
    printf("Erreur d'allocation de mémoire\n");
    exit(1);
  }
  nouveau->identifiant=identifiant;
  //convertit les chaine de caractère en nombre, si il s'agit de nombre, et en 0 si il s'agit de "-"
  nouveau->capacite=atol(capacite);	
  nouveau->consommation=atol(consommation);
  nouveau->fg=NULL;
  nouveau->fd=NULL;
  nouveau->equilibre=0;
  nouveau->hauteur=1;
  return nouveau;
}

//Insertion de l'arbre AVL
Arbre *insertionAVL(Arbre *a, long identifiant, const char* capacite, const char* consommation){
  if (a==NULL){
    return creationArbre(identifiant, capacite, consommation);
  }
  if (identifiant < a->identifiant) {
     a->fg = insertionAVL(a->fg, identifiant, capacite, consommation);

  }
  else if(identifiant > a->identifiant){
    insertionAVL(a->fd,identifiant,capacite,consommation);
  }
  else{ //Mise à jour de la consommation et la capacité
    a->consommation += atol(consommation);
    a->capacite = max(a->capacite,atol(capacite));
    return a;
  }
  //Mise à jour de la hauteur de l'arbre
  a->hauteur = hauteur(a);
  //Mise à jour de l'équilibre de l'arbre
  int equilibre=facteur_equilibre(a);
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
  if(equilibre < -1 && identifiant < a->fd->identifiant){
    a->fd=rotationDroite(a->fd);
    return rotationGauche(a);
  }
  printf("Erreur : échec de l'insertion pour l'identifiant : %ld, capacité : %ld, Consommation : %ld\n", identifiant,atol(capacite), atol(consommation));
  return a;
}
//Parcours en ordre croissant (infixe = parcours en ordre) et écriture dans le fichier de sortie
void infixe(Arbre* a, FILE* fichier_resultat){ 
  if (a==NULL){
    return;
  } //Si a est NULL, la fonction retourne
  infixe(a->fg,fichier_resultat);
  fprintf(fichier_resultat, "%ld : %ld : %ld\n", a->identifiant, a->capacite, a->consommation);
  infixe(a->fd,fichier_resultat);
}

//Libère la mémoire de l'arbre AVL
void freeAVL(Arbre* a){
  if (!a) return; //Si a est NULL, la fonction retourne
    freeAVL(a->fg);
    freeAVL(a->fd);
    free(a);
}

void traiterFichier(const char *nomFichier, const char *nomFichierTmp) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return;
    }

    char ligne[1024];
    Arbre *racine = NULL;

    // Ignore l'entête
    fgets(ligne, sizeof(ligne), fichier);

    // Lire chaque ligne du fichier CSV
    while (fgets(ligne, sizeof(ligne), fichier)) {
        long identifiant;
        char *capacite = malloc(100 * sizeof(char));  
        char *consommation = malloc(100 * sizeof(char)); 

        // Séparer les colonnes de la ligne en utilisant strtok
        char *sep = strtok(ligne, ":");
        if (sep != NULL) {
            identifiant = atol(sep);

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                strncpy(capacite, sep, 100);
            }

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                strncpy(consommation, sep, 100);
            }

            // Insérer le nouveau noeud dans l'arbre AVL
            racine = insertionAVL(racine, identifiant, capacite, consommation);
        }

        free(capacite);
        free(consommation);
    }

    fclose(fichier);  // Fermer le fichier après lecture

    // Ecrire les résultats dans un fichier temporaire
    FILE *fichierTmp = fopen(nomFichierTmp, "w");
    if (fichierTmp == NULL) {
        printf("Erreur d'ouverture du fichier temporaire\n");
        return;
    }
    fprintf(fichierTmp, "ID station: Capacité: Consommation\n");
    infixe(racine, fichierTmp);
    fclose(fichierTmp);

    // Supprimer l'ancien fichier et renommer le fichier temporaire
    remove(nomFichier);
    rename(nomFichierTmp, nomFichier);

    freeAVL(racine);  // Libérer l'arbre AVL
}

