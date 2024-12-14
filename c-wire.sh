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


#echo "Station: $station, Conso: $conso"
# Nom de l'exécutable (défini dans le Makefile)
EXECUTABLE="mon_programme"

# Vérification de la présence du Makefile
if [ ! -f "Makefile" ]; then
    echo "Erreur : Le fichier Makefile est introuvable."
    exit 1
fi

# Vérification de la présence de l'exécutable
if [ ! -f "$EXECUTABLE" ]; then
    echo "L'exécutable $EXECUTABLE est introuvable. Lancement de la compilation avec make..."
    
    # Lancer la compilation avec le Makefile
    make "$EXECUTABLE"
    
    # Vérification si make a réussi
    if [ $? -ne 0 ]; then
        echo "Erreur : La compilation avec make a échoué."
        exit 1
    fi
    
    echo "Compilation réussie. Exécutable $EXECUTABLE généré."
fi

# Vérification que l'exécutable a bien été créé
if [ ! -f "$EXECUTABLE" ]; then
    echo "Erreur : L'exécutable $EXECUTABLE est introuvable même après compilation."
    exit 1
fi

# Exécuter l'exécutable avec les arguments donnés
echo "Exécution de l'exécutable $EXECUTABLE avec les arguments : $@"
./"$EXECUTABLE" "$@"

# Vérification de la réussite de l'exécution
if [ $? -ne 0 ]; then
    echo "Erreur : L'exécution du programme a échoué."
    exit 1
fi

echo "Traitement terminé avec succès."
