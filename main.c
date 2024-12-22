int main(int argc, char* argv[]) {
    const char *input_file = argv[1];
    const char *fichier_resultat = argv[2];

    // Liste des fichiers à traiter
    const char *fichiers[] = {
        "hvb_comp.csv", "hva_comp.csv", "lv_comp.csv", 
        "lv_indiv.csv", "lv_all.csv"
    };

    // Traiter chaque fichier
    for (int i = 0; i < 5; ++i) {
        char nomFichierTmp[50];
        snprintf(nomFichierTmp, sizeof(nomFichierTmp), "tmp_%d.csv", i);

        traiterFichier(fichiers[i], nomFichierTmp);
    }

    return 0;
}
