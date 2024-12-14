#!/bin/bash


if [ $# -lt 1 ]; 
	then
	echo "Problème: nombre d'argument insuffisant"
	exit 1
fi

station=0
conso=0

if [ "$2" = "hvb" ]; 
	then
	station=1
elif [ "$2" = "hva" ]; 
	then
	station=2
elif [ "$2" = "lv" ]; 
	then
	station=3
else
	echo "Problème: mauvaise station argument"
	exit 1
fi
 
elif [ "$3" = "comp" ]; 
	then
	conso=1
elif [ "$3" = "indiv" ]; 
	then
	conso=2
elif [ "$3" = "all" ]; 
	then
	conso=3
else
	echo "Problème: mauvais consommateur argument"
	exit 1
fi


echo "Station: $station, Conso: $conso"
# Nom de l'exécutable et du fichier source
EXECUTABLE="mon_programme"
SOURCE="mon_programme.c"

# Vérification de la présence du fichier source C
if [ ! -f "$SOURCE" ]; then
    echo "Erreur : Le fichier source $SOURCE est introuvable."
    exit 1
fi

# Vérification de la présence de l'exécutable
if [ ! -f "$EXECUTABLE" ]; then
    echo "L'exécutable $EXECUTABLE est introuvable. Lancement de la compilation..."
    
    # Lancer la compilation
    gcc "$SOURCE" -o "$EXECUTABLE"
    
    # Vérification de la réussite de la compilation
    if [ $? -ne 0 ]; then
        echo "Erreur : La compilation a échoué."
        exit 1
    fi
    
    echo "Compilation réussie. Exécutable $EXECUTABLE généré."
fi

# Vérification que l'exécutable est bien créé
if [ ! -f "$EXECUTABLE" ]; then
    echo "Erreur : L'exécutable $EXECUTABLE est introuvable même après compilation."
    exit 1
fi

# Exécuter le programme avec les arguments donnés
echo "Exécution de l'exécutable $EXECUTABLE avec les arguments : $@"
./"$EXECUTABLE" "$@"

# Vérification du succès de l'exécution
if [ $? -ne 0 ]; then
    echo "Erreur : L'exécution du programme a échoué."
    exit 1
fi

echo "Traitement terminé avec succès."
