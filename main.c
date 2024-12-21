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
        printf("Attention : \"%s\" contient des caractères non numériques\n", str);
    }
    return nombre; //retourner la valeur convertie
}
       
int main(){
  FILE*fichier=fopen("c-wire.csv","r");
  
  const char* fichier_csv = "c-wire_000.csv";

    printf("Lecture et traitement du fichier CSV : %s\n", fichier_csv);
    traiter_fichier_csv(fichier_csv);

    return 0;
}

int main(int argc, char* argv[]){
    if(argc < 3){
        fprintf(stderr, 

    int RouteID;
    float distance;
    char header[256];
    int h = 0;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error while trying to open csv file.\n");
        exit(1);
    }

    // Creates the AVL root with first line of csv
    fgets(header, sizeof(header), file); // Skips header line

    if (fscanf(file, "%d;%*d;%*[^;];%*[^;];%f;%*[^\n]", &RouteID, &distance) != 2)
    {
        printf("Error while gettings variables of csv.\n");
        exit(1);
    }
    pAVL root = CreateAVL(RouteID, distance);













#!/bin/bash

    while getopts"nrt/k"opt
    
