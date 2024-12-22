#include <biblio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Fonction de parsing et construction de l'arbre AVL
Arbre *parser_file(const char *str){
    char *restant;
    //Vérifier si la chaîne est NULL ou si elle contient "-"
    if(str == NULL || strcmp(str, "-") == 0){
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
    char line[256];

    //Lecture des données et insertion dans l'arbre AVL
    while (fgets(line, sizeof(line), input)){
        
    

  FILE*fichier=fopen("c-wire.csv","r");
  
  const char* fichier_csv = "c-wire_000.csv";

    printf("Lecture et traitement du fichier CSV : %s\n", fichier_csv);
    traiter_fichier_csv(fichier_csv);

    return 0;
}

