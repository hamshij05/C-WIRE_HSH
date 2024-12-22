#include "biblio.h"
#include "fonction.c"

int main(int argc, char* argv[]) {
    const char *input_file = argv[1];
    const char *fichier_resultat = argv[2];

    // Liste des fichiers à traiter dans le répertoire tmp
    const char *fichiers[] = {
        "tmp/hvb_comp.csv", "tmp/hva_comp.csv", "tmp/lv_comp.csv", 
        "tmp/lv_indiv.csv", "tmp/lv_all.csv"
    };

    // Traiter chaque fichier
    for (int i = 0; i < 5; ++i) {
        char nomFichierTmp[50]; // Correction : ne pas utiliser const ici
        snprintf(nomFichierTmp, sizeof(nomFichierTmp), "tmp/tmp_%d.csv", i);

        // Appel de la fonction traiterFichier avec le chemin complet vers le fichier source et destination
        traiterFichier(fichiers[i], nomFichierTmp);
    }

    return 0;
}
