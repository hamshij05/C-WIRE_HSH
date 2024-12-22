#include <biblio.h>

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
            racine2 = insertionAVL(racine2, identifiant, capacite, consommation);
        }
    }

    fclose(fichier);  // Fermer le fichier après lecture

  const char *nomFichier21 = "tmp.csv";  
  FILE *fichier21 = fopen(nomFichier21, "w");
  if (fichier == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier1, "ID station: Capacité: Consommation\n");
  infixe(racine2,fichier21);
  fclose(fichier1);
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
            racine2 = insertionAVL(racine2, identifiant, capacite, consommation);
        }
    }

    fclose(fichier);  // Fermer le fichier après lecture

  const char *nomFichier21 = "tmp.csv";  
  FILE *fichier21 = fopen(nomFichier21, "w");
  if (fichier == NULL) {
      printf("Erreur d'ouverture du fichier\n");
      return 0;
  }
  fprintf(fichier1, "ID station: Capacité: Consommation\n");
  infixe(racine2,fichier21);
  fclose(fichier1);
  remove(nomFichier2);
  rename(nomFichier21, nomFichier2);

  freeAVL(racine2); 



    // Afficher l'arbre (parcours infixe)

    return 0;
}
