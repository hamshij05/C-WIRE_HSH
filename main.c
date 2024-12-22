#include "biblio.h"

int main(int argc, char* argv[]){
    if(argc < 3){
        fprintf(stderr, "Traitement : %s <input_file> <fichier_resultat>\n", argv[0];
        return 1;
    }
    const char* input_file = argv[1];
    const char* fichier_resultat = argv[2];
    const char* identifiant = argv[3]; //Récuperation le type de station
    const char *nomFichier = "hvb_comp.csv"; 
    const char *nomFichier2 = "hva_comp.csv";
    const char *nomFichier3 = "lv_comp.csv";
    const char *nomFichier4 = "lv_indiv.csv";
    const char *nomFichier5 = "lv_all.csv";
  
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char ligne[1024];  // Tableau pour lire chaque ligne
    Arbre *racine = NULL;  // Pointeur vers la racine de l'AVL

    // Ignore l'entête
    fgets(ligne, sizeof(ligne), fichier);

    // Lire chaque ligne du fichier CSV
    while (fgets(ligne, sizeof(ligne), fichier)) {
        int identifiant;
        const char* capacite = malloc(sizeof(const char*));  
        const char* consommation = malloc(sizeof(const char*)); 

        // Enlever le saut de ligne à la fin de la ligne lue
        //ligne[strcspn(ligne, "\n")] = 0;

        // Séparer les colonnes de la ligne en utilisant strtok (séparateur ":")
        char *sep = strtok(ligne, ":");

        if (sep != NULL) {
            identifiant = atol(sep);

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                capacite = sep;
            }

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                consommation = sep;
            }

            // Insérer le nouveau noeud dans l'arbre AVL
            racine = insertionAVL(racine, identifiant, capacite, consommation);
            free(capacite);
            free(consommation);           
        }
    }

    fclose(fichier);  // Fermer le fichier après lecture

  const char *nomFichier1 = "tmp.csv";  
  FILE *fichier1 = fopen(nomFichier1, "w");
  if (fichier == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier1, "ID station: Capacité: Consommation\n");
  infixe(racine,fichier1);
  fclose(fichier1);
  remove(nomFichier);
  rename(nomFichier1, nomFichier);

  freeAVL(racine); 

  FILE *fichier2 = fopen(nomFichier2, "r");
    if (fichier2 == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char ligne2[1024];  // Tableau pour lire chaque ligne
    Arbre *racine2 = NULL;  // Pointeur vers la racine de l'AVL

    // Ignore l'entête
    fgets(ligne2, sizeof(ligne2), fichier2);

    // Lire chaque ligne du fichier CSV
    while (fgets(ligne2, sizeof(ligne2), fichier2)) {
        int identifiant;
        const char* capacite = malloc(sizeof(const char*));  
        const char* consommation = malloc(sizeof(const char*)); 

        // Enlever le saut de ligne à la fin de la ligne lue
        //ligne[strcspn(ligne, "\n")] = 0;

        // Séparer les colonnes de la ligne en utilisant strtok (séparateur ":")
        char *sep = strtok(ligne2, ":");

        if (sep != NULL) {
            identifiant = atol(sep);

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                capacite = sep;
            }

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                consommation = sep;
            }

            // Insérer le nouveau noeud dans l'arbre AVL
            racine2 = insertionAVL(racine2, identifiant, capacite, consommation);
            free(capacite);
            free(consommation);            
        }
    }

    fclose(fichier2);  // Fermer le fichier après lecture

  const char *nomFichier21 = "tmp.csv";  
  FILE *fichier21 = fopen(nomFichier21, "w");
  if (fichier == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier21, "ID station: Capacité: Consommation\n");
  infixe(racine2,fichier21);
  fclose(fichier21);
  remove(nomFichier2);
  rename(nomFichier21, nomFichier2);

  freeAVL(racine2); 

  FILE *fichier3= fopen(nomFichier3, "r");
    if (fichier3 == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char ligne3[1024];  // Tableau pour lire chaque ligne
    Arbre *racine3 = NULL;  // Pointeur vers la racine de l'AVL

    // Ignore l'entête
    fgets(ligne3, sizeof(ligne3), fichier3);

    // Lire chaque ligne du fichier CSV
    while (fgets(ligne3, sizeof(ligne3), fichier3)) {
        int identifiant;
        const char* capacite = malloc(sizeof(const char*));  
        const char* consommation = malloc(sizeof(const char*)); 

        // Enlever le saut de ligne à la fin de la ligne lue
        //ligne[strcspn(ligne, "\n")] = 0;

        // Séparer les colonnes de la ligne en utilisant strtok (séparateur ":")
        char *sep = strtok(ligne, ":");

        if (sep != NULL) {
            identifiant = atol(sep);

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                capacite = sep;
            }

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                consommation = sep;
            }

            // Insérer le nouveau noeud dans l'arbre AVL
            racine3 = insertionAVL(racine3, identifiant, capacite, consommation);
            free(capacite);
            free(consommation);
        }
    }

    fclose(fichier3);  // Fermer le fichier après lecture

  const char *nomFichier31 = "tmp.csv";  
  FILE *fichier31 = fopen(nomFichier31, "w");
  if (fichier == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier31, "ID station: Capacité: Consommation\n");
  infixe(racine3,fichier31);
  fclose(fichier31);
  remove(nomFichier3);
  rename(nomFichier31, nomFichier3);

  freeAVL(racine3); 

  FILE *fichier4= fopen(nomFichier4, "r");
    if (fichier4 == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char ligne4[1024];  // Tableau pour lire chaque ligne
    Arbre *racine4 = NULL;  // Pointeur vers la racine de l'AVL

    // Ignore l'entête
    fgets(ligne4, sizeof(ligne4), fichier4);

    // Lire chaque ligne du fichier CSV
    while (fgets(ligne4, sizeof(ligne4), fichier4)) {
        int identifiant;
        const char* capacite = malloc(sizeof(const char*));  
        const char* consommation = malloc(sizeof(const char*)); 

        // Enlever le saut de ligne à la fin de la ligne lue
        //ligne[strcspn(ligne, "\n")] = 0;

        // Séparer les colonnes de la ligne en utilisant strtok (séparateur ":")
        char *sep = strtok(ligne4, ":");

        if (sep != NULL) {
            identifiant = atol(sep);

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                capacite = sep;
            }

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                consommation = sep;
            }

            // Insérer le nouveau noeud dans l'arbre AVL
            racine4 = insertionAVL(racine4, identifiant, capacite, consommation);
            free(capacite);
            free(consommation);
        }
    }

    fclose(fichier4);  // Fermer le fichier après lecture

  const char *nomFichier41 = "tmp.csv";  
  FILE *fichier41 = fopen(nomFichier41, "w");
  if (fichier41 == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier41, "ID station: Capacité: Consommation\n");
  infixe(racine4,fichier41);
  fclose(fichier41);
  remove(nomFichier4);
  rename(nomFichier41, nomFichier4);

  freeAVL(racine4); 

  FILE *fichier5= fopen(nomFichier5, "r");
    if (fichier5 == NULL) {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    char ligne5[1024];  // Tableau pour lire chaque ligne
    Arbre *racine5 = NULL;  // Pointeur vers la racine de l'AVL

    // Ignore l'entête
    fgets(ligne5, sizeof(ligne5), fichier5);

    // Lire chaque ligne du fichier CSV
    while (fgets(ligne5, sizeof(ligne5), fichier5)) {
        int identifiant;
        const char* capacite = malloc(sizeof(const char*));  
        const char* consommation = malloc(sizeof(const char*)); 

        // Enlever le saut de ligne à la fin de la ligne lue
        //ligne[strcspn(ligne, "\n")] = 0;

        // Séparer les colonnes de la ligne en utilisant strtok (séparateur ":")
        char *sep = strtok(ligne5, ":");

        if (sep != NULL) {
            identifiant = atol(sep);

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                capacite = sep;
            }

            sep = strtok(NULL, ":");
            if (sep != NULL) {
                consommation = sep;
            }

            // Insérer le nouveau noeud dans l'arbre AVL
            racine5 = insertionAVL(racine5, identifiant, capacite, consommation);
            free(capacite);
            free(consommation);
        }
    }

    fclose(fichier5);  // Fermer le fichier après lecture

  const char *nomFichier51 = "tmp.csv";  
  FILE *fichier51 = fopen(nomFichier51, "w");
  if (fichier51 == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier51, "ID station: Capacité: Consommation\n");
  infixe(racine5,fichier51);
  fclose(fichier51);
  remove(nomFichier5);
  rename(nomFichier51, nomFichier5);

  freeAVL(racine5); 
  
return 0;
}
