#!/bin/bash

# Fonction pour arrête le chronomètre et afficher la durée
fin_chrono() {
    temps_2=$(date +%s.%N)
    temps=$(echo "$temps_2 - $1" | bc)
    echo "Durée utile du traitement : ${temps} sec"
}

aide() { 
    echo "Usage: bash <chemin(c-wire.sh)> <station> <consommateur> (<id centrale>)"
    echo "station : hvb, hva, lv"
    echo "type : comp, indiv, all"
    echo "chemin : nom du fichier ou autre"
    echo "PS: une hva et une hvb ne peut avoir comme consommateur qu'une entreprise (comp)"  
    exit 1
}

nom_fichier() {
nom_fichier="${1}_${2}.csv"
}


if [ $# -lt 1 ]; 
	then
	echo "Problème: nombre d'argument insuffisant"
 	echo "Durée utile du traitement : 0.0 sec"
	aide
	exit 1
fi

station=0
conso=0
plant=0

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
 	echo "Durée utile du traitement : 0.0 sec"
	aide
	exit 1
fi
		
if [ "$3" = "comp" ]; 
	then
	conso=1
elif [ "$3" = "indiv" ]; 
	then
	if [ "$station" = 1 ]
		then
		aide
		exit 1
	elif [ "$station" = 2	]
		then 
		aide
		exit 1
	fi	 
	conso=2
elif [ "$3" = "all" ]; 
	then
	if [ "$station" = 1 ]
		then
		aide
		exit 1
	elif [ "$station" = 2	]
		then 
		aide
		exit 1	
	fi	
	conso=3
else
	echo "Problème: mauvais consommateur argument"
 	echo "Durée utile du traitement : 0.0 sec"
	aide
	exit 1
fi


plant="$4"


#echo "Station: $station, Conso: $conso"


EXECUTABLE="main"

# Vérification de la présence du Makefile
if [ ! -f "makefile" ];
	then
	echo "Erreur: Le fichier Makefile est introuvable."
	exit 1
fi

# Vérification de la présence de l'exécutable
if [ ! -f "$EXECUTABLE" ];
	then
	echo "L'exécutable $EXECUTABLE est introuvable. Lancement de la compilation"
    
	# lancer la compilation avec le Makefile
	make "$EXECUTABLE"
    
	# Vérification si make a réussi
	if [ $? -ne 0 ]; then
		echo "Erreur: La compilation avec make a échoué."
        	exit 1
	fi
    
	echo "Compilation réussie. Exécutable $EXECUTABLE généré."
fi

# Vérification que l'exécutable a bien été créé
if [ ! -f "$EXECUTABLE" ];
	then
	echo "Erreur: L'exécutable $EXECUTABLE est introuvable même après compilation."
	exit 1
fi

# Exécuter l'exécutable avec les arguments donnés
echo "Exécution de l'exécutable $EXECUTABLE avec les arguments : $@"
./"$EXECUTABLE" "$@"

# Vérification de la réussite de l'exécution
if [ $? -ne 0 ]; 
	then
	echo "Erreur : L'exécution du programme a échoué."
	exit 1
fi

#dossier tmp
if [  -d "tmp" ];
	then
	rm -rf tmp/*
	if [ $? -ne 0 ];
		then
		echo "Erreur: impossible de vider le dossier, tmp déjà existant"
		exit 1
	fi
else
	mkdir tmp
	if [ $? -ne 0 ];
		then
		echo "Erreur: impossible de créer temp"
		exit 1
	fi			

fi

#dossier graphs
if [ -d "graphs" ];
	then
	rm -rf graphs/*
	if [ $? -ne 0 ]
		then
		echo "Erreur: impossibilité de vider le dossier graphs"
		exit 1
	fi
else 
	mkdir graphs
	if [ $? -ne 0 ];
		then 
		echo "Erreur: impossibilité de créer le dossier graphs"
		exit 1
	fi
fi
	
temps_1=$(date +%s.%N)

name_file1="hvb_comp.csv"
cd tmp
touch "$name_file1"
if [ $? -ne 0 ];
		then 
		echo "Erreur: impossibilité de créer le fichier demandé $name_file"
		fin_chrono $temps_1
  		exit 1
fi
head -n 1 c-wire_v00.csv > $name_file1
grep -E "[1-9];[1-9]+;-;-;[1-9]+;-;-;[1-9]+" c-wire_v00.csv | cut -d":" -f1 > $name_file1
#grep -E "^[1-9];[1-9]+;-;-;" c-wire_v00.csv | cut -d":" -f1 > $name_file1


fin_chrono
	
