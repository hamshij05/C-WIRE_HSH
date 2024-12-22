#include <biblio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fonction de parsing et construction de l'arbre AVL
long parser_file(const char *str){
    char *restant;
    //Vérifier si la chaîne est NULL ou si elle contient "-"
    if(strcmp(str, "-") == 0){
        return 0; 
    }
    //Convertir la chaîne en entier en base 10
    long nombre = strtol(str, &restant, 10);
    //Si la conversion ne consomme pas toute la chaine
    if(*restant != '\0'){
        printf("Attention : %s contient des caractères non numériques \n", restant);
    }
    return nombre; //retourner la valeur convertie
}

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

