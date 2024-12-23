# C-WIRE_HSH
## **************CY Tech - C-WIRE**************

### ***Projet-semestre1 - PréIng2***
## **Bienvenue dans notre programme**

## Sommaire
1. [Description du projet](#description-du-projet)
2. [Structure](#structure)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Auteurs](#auteurs)

## Description du projet     
Le projet C-Wire vise à développer un système pour analyser les données de distribution d'énergie en France. L'objectif est de déterminer la production, la consommation et la répartition énergétique à travers les différents niveaux du réseau électrique (centrales, stations HV-B, HV-A, postes LV).
Le système est composé de :
- **Un script Shell (`c-wire.sh`)** :
  Filtrer les données et orchestrer les traitements.  
-  **Un programme C (`main.c` et `fonction.c`)** :  
 Utilisation d'arbre AVL pour traiter efficacement les données : faire la somme des consommations d'un type de station. Etant donnée les nombreauses données et stations, nous allons passer par un AVL afin de limiter le temps de traitement.  

## Structure 
  - **`biblio.h`** : contient tous les bibliothèques utilisées, les définitions de les structures et les déclarations des fonctions.  
  - **`Makefile`** : permet d'automatiser la compilation  
  - **`fonctions.c`** : implémentation des fonctions déclarées dans biblio.h
  - **`main.c`** lit le fichier CSV, extrait les données et les insère dans un arbre AVL
  - **`c-wire.sh`** fait le premier tri pour rassembler toute les informations par station, consommateur et centrale et organise et verifie puis appelle la partie C du processus via le makefile.
  - **`Rapport du projet`** contient un compte rendu sur l'organisation de l'équipe concernant le projet, les difficultés rencontrées, les solutions apportées et une brève description du projet.  

## Installation
 **Prerequis**  
Avant de commencer, assurez-vous les outils suivants sont installes sur votre système :   
- **`GnuPlot`** : pour la génération de graphiques
- **`Bash`** : pour exécuter le script Shell
- **`grep et awk`** : pour des fonctions utiles pour le traitement de données

Vous pouvez installer tous les outils via le gestionnaire de paquets de votre système d'exploitation, en écrivant ces commandes dans votre terminal.  
    
    sudo apt -get update
    sudo apt -get install bash awk gnuplot
  
## Utilisation

## Auteurs    
- **Hamshigaa JEKUMAR** - hamshij05  
- **Sira DIAKITE** - Sira-la-Staaar  
- **Hajar BELQUASS** - hjrblq  
