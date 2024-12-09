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

// Fonction pour lire un fichier CSV et traiter les données
void fichier_csv(const char* fichier) {
    FILE* fichier=fopen("c-wire_v00.csv", "r");
    if (fichier==NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
int main(){
  FILE*fichier=fopen("fichier;txt","r");
  
  const char* fichier_csv = "c-wire_000.csv";

    printf("Lecture et traitement du fichier CSV : %s\n", fichier_csv);
    traiter_fichier_csv(fichier_csv);

    return 0;
}
