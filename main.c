//Cette fichier main.c lit le fichier CSV, extrait les données et les insère dans un arbre AVL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour les données électriques
typedef struct electricite {
    int identifiant; //identifiant de la centrale éléctrique
    int hvb_station;
    int hva_station;
    int lv_station;
    long capacite;
}Electricite;

//Fonction pour la lecture CSV et Insertion dans l’Arbre
Arbre *creationAVLFromCSV(const char *file) {
    FILE *file=fopen("c-wire_v00.csv", "r");
    if (file==NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    Arbre *a = NULL;
    int h = 0;
    char ligne[1024];
    while (fgets(ligne, sizeof(ligne), file)) {
        int e;
        if (sscanf(ligne, "%d", &e) == 1) {
            a = insertionAVL(a, e, &h);
        }
    }
    fclose(file);
    return a;
}

int parseCSV(const char *filename, AVLNode **root) {
   
int main(){
  FILE*fichier=fopen("c-wire.csv","r");
  
  const char* fichier_csv = "c-wire_000.csv";

    printf("Lecture et traitement du fichier CSV : %s\n", fichier_csv);
    traiter_fichier_csv(fichier_csv);

    return 0;
}

int main(int argc, char *argv[])
{
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
    
