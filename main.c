#include <biblio.h>

int main(int argc, char* argv[]){
if(argc < 3){
    fprintf(stderr, "Traitement : %s <input_file> <fichier_resultat>\n", argv[0];
    return 1;
}
const char* input_file = argv[1];
const char* fichier_resultat = argv[2];
const char* identifiant = argv[3]; //Récuperation le type de station

FILE* input = fopen(input_file, "r");
if(!input){
    printf("Attention : Erreur lors de l'ouverture du fichier input");
    return 1;
}
    FILE* resultat = fopen(fichier_resultat, "w");
    if(!=resultat){
        printf("Erreur lors de l'ouverture du fichier de sortie.\n");
        fclose(input);
        return 1;
    }
    Arbre* a = NULL;
    char ligne[256];

    //Lecture des données et insertion dans l'arbre AVL
    while (fgets(line, sizeof(ligne), input)){
        ligne[strcspn(ligne, "\n")] = 0;
    if ((strncmp(ligne, "LV Station:Capacity:Load", 24) == 0 && strcmp(identifiant, "LV") == 0) || (strncmp(ligne, "HV-A Station:Capacity:Load", 25) == 0 && strcmp(identifiant, "HV-A") == 0) || (strncmp(ligne, "HV-B Station:Capacity:Load", 25) == 0 && strcmp(identifiant, "HV-B") == 0)) {
        printf("INFO : header line ignorée);
        continue;
    }
    char* segment = strtok(ligne, ":");
        if(!segment){
            fprintf(stderr, "INFO : ligne ignorée : %s\n", ligne);
            continue;
        }
        long identifiant = parser_file(segment);

        segment = strtok(NULL, ":");
        if(!segment){
            fprintf("stderr, "INFO : ligne ignorée : %s\n", ligne);
            continue;
        }
        long capacite = parser_file(segment);

        segment = strtok(NULL, ":");
        if(!token){
            fprintf(stderr, "INFO : ligne ignorée : %s"\n", ligne);
            continue;
        }
        long load = parse_long(segment);

        a = insertion(a, identifiant, capacite, load);
    }
        //Ecriture des résultats triés par les identifiants
        fprintf("resultat, "Identifiant : Capacite : Consommation \n");
        infixe(a, resultat);
        
        //Libérer la mémoire et fermeture des ficheirs
        freeAVL(a);
        fclose(input);
        fclose(resultat);
        return 0;

}

