# C-WIRE_HSH

### **************CY Tech - C-WIRE**************

## ***Projet-semestre1 - PréIng2***
**Bienvenue dans notre programme**

## -  Sommaire
1. [Description du projet](#description-du-projet)
2. [Structure](#structure)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Auteurs](#auteurs)

## **Description du projet :**
Le projet C-Wire vise à développer un système pour analyser les données de distribution d'énergie en France. L'objectif est de déterminer la production, la consommation et la répartition énergétique à travers les différents niveaux du réseau électrique (centrales, stations HV-B, HV-A, postes LV).
Le système est composé de :
- **Un script Shell (`c-wire.sh`)** :
  Filtrer les données et orchestrer les traitements.  
-  **Un programme C** :  
 Utilisation d'arbre AVL pour traiter efficacement les données : faire la somme des consommations d'un type de station. Etant donnée les nombreauses données et stations, nous allons passer par un AVL afin de limiter le temps de traitement.  

## **Structure :**
  - **`biblio.h`** : contient tous les bibliothèques utilisées  
  - **`Makefile`** : permet d'automatiser la compilation  
  - **`fonctions.c`** :  
  - **`main.c`** lit le fichier CSV, extrait les données et les insère dans un arbre AVL  

  - **`Rapport du projet`** contient un compte rendu sur l'organisation de l'équipe concernant le projet, les difficultés rencontrées, les solutions apportées et une brève description du projet.  



## **Auteurs :**   
- **Hamshigaa JEKUMAR** - hamshij05  
- **Sira DIAKITE** - Sira-la-Staaar  
- **Hajar BELQUASS** - hjrblq  
