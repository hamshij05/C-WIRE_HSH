#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Structure d'Arbre AVL
typedef struct arbre{
  int elmt;
  struct arbre *fg;
  struct arbre *fd;
  int equilibre; //facteur d'équilibre
  int hauteur;
}Arbre;

//Structure pour représenter les données électriques
typedef struct electricite{
  int identifiant;
  int capacite; //capacité de la station
  int consommation;  //consommation totale
}Electricite;



