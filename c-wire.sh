#!/bin/bash

# Fonction pour arrête le chronomètre et afficher la durée: fait à l'aide de CHAT GPT
#temps_1=$(date +%s.%N)
fin_chrono() {
    # Vérifier si $1 est un nombre valide (entier ou flottant)
    if ! [[ "$1" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
        echo "Erreur : L'argument de temps ($1) n'est pas un nombre valide."
        exit 1
    fi

    # Obtenir le temps actuel
    temps_2=$(date +%s.%N)

    # Vérifier que temps_2 est un nombre valide
    if ! [[ "$temps_2" =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
        echo "Erreur : Le calcul du temps a échoué, temps_2 n'est pas valide."
        exit 1
    fi

    # Effectuer le calcul du temps avec une précision de 2 décimales
    temps=$(echo "scale=2; $temps_2 - $1" | bc)

    # Si le résultat est trop petit (par exemple moins de 0.01 sec), on peut l'afficher avec une précision contrôlée
    if [ $(echo "$temps < 0.01" | bc) -eq 1 ]; then
        echo "Durée utile du traitement : 0.00 sec"
    else
        echo "Durée utile du traitement : $temps sec"
    fi
}


aide() { 
	echo "assurez vous d'abord que le fichier à traiter est le premier argument et qu'il est dans le même dossier que celui-ci"	
	echo "Usage: bash <chemin(c-wire.sh)> <station> <consommateur> (<id centrale>)"
	echo "station : hvb, hva, lv"
	echo "type : comp, indiv, all"
	echo "chemin : nom du fichier ou autre"
	echo "PS: une hva et une hvb ne peut avoir comme consommateur qu'une entreprise (comp)
	Si vous avez mis un numéro de centrale et qu'en sortie vous n'obtenez rien, cela veut dire que l'identifiant de votre centrale ne figure pas dans le CSV d'origine"  
	exit 1
}

fichier=$1
if [ "$fichier" == "-h" ]; then
	echo "appel à l'aide:" 
	echo "ce script vous permet de faire un tri par rapport à un type de station précis, et un type de consommateur donné"
	aide
	exit 1
fi

if [ ! -f "$fichier" ]; then
	echo "Erreur: le fichier $fichier n'existe pas"
	echo "Durée utile du traitement : 0.00 sec"
	exit 1
fi

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
 	echo "Station: $station, Conso: $conso"
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
if [ -n "$4" ]; then
	plant="$4"
else
	plant="[1-9]"
fi



#echo "Station: $station, Conso: $conso"


###################################################################################################

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
		echo "Erreur: impossibilité de créer le fichier demandé $name_file1"
		fin_chrono $temps_1
  		exit 1
fi
head -n 1 ../$fichier | cut -d';' -f2,7,8 > $name_file1 
grep -E "$plant;[0-9]+;-;-;-;-;[0-9]+;-" ../$fichier | cut -d';' -f2,7,8 | sed 's/;/:/g' >> $name_file1 
grep -E "$plant;[0-9]+;-;-;[1-9]+;-;-;[1-9]+" ../$fichier | cut -d';' -f2,7,8 | sed 's/;/:/g' >> $name_file1 

#grep -E "^[1-9];[1-9]+;-;-;" c-wire_v00.csv | cut -d":" -f1 > $name_file1

name_file2="hva_comp.csv"
touch "$name_file2"
if [ $? -ne 0 ];
		then 
		echo "Erreur: impossibilité de créer le fichier demandé $name_file2"
		fin_chrono $temps_1
  		exit 1
fi
head -n 1 ../$fichier | cut -d';' -f3,7,8 > $name_file2 
grep -E "$plant;[0-9]+;[0-9]+;-;-;-;[0-9]+;-" ../$fichier| cut -d';' -f3,7,8 | sed 's/;/:/g' >> $name_file2  
grep -E "$plant;-;[0-9]+;-;[0-9]+;-;-;[0-9]+" ../$fichier| cut -d';' -f3,7,8 | sed 's/;/:/g' >> $name_file2


name_file3="lv_comp.csv"
touch "$name_file3"
if [ $? -ne 0 ];
		then 
		echo "Erreur: impossibilité de créer le fichier demandé $name_file3"
		fin_chrono $temps_1
  		exit 1
fi 
head -n 1 ../$fichier | cut -d';' -f4,7,8 > $name_file3
grep -E "$plant;-;[0-9]+;[0-9]+;-;-;[0-9]+;-" ../$fichier | cut -d";" -f4,7,8 | sed 's/;/:/g' >> $name_file3
grep -E "$plant;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" ../$fichier | cut -d';' -f4,7,8 | sed 's/;/:/g' >> $name_file3


name_file4="lv_indiv.csv"
touch "$name_file4"
if [ $? -ne 0 ];
		then 
		echo "Erreur: impossibilité de créer le fichier demandé $name_file4"
		fin_chrono $temps_1
  		exit 1
fi
head -n 1 ../$fichier | cut -d';' -f4,7,8 > $name_file4
grep -E "$plant;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" ../$fichier | cut -d';' -f4,7,8 | sed 's/;/:/g' >> $name_file4
grep -E "$plant;-;[0-9]+;[0-9]+;-;-;[0-9]+;-" ../$fichier | cut -d";" -f4,7,8 | sed 's/;/:/g' >> $name_file4

name_file5="lv_all.csv"
touch "$name_file5"
if [ $? -ne 0 ];
		then 
		echo "Erreur: impossibilité de créer le fichier demandé $name_file5"
		fin_chrono $temps_1
  		exit 1
fi
head -n 1 ../$fichier | cut -d';' -f4,7,8 >> $name_file5 
grep -E "$plant;-;[0-9]+;[0-9]+;-;-;[0-9]+;-" ../$fichier | cut -d";" -f4,7,8 | sed 's/;/:/g' >> $name_file5
grep -E "$plant;-;-;[0-9]+;[0-9]+;-;-;[0-9]+" ../$fichier | cut -d';' -f4,7,8 | sed 's/;/:/g' >> $name_file5
grep -E "$plant;-;-;[0-9]+;-;[0-9]+;-;[0-9]+" ../$fichier | cut -d';' -f4,7,8 | sed 's/;/:/g' >> $name_file5

cd ..

fin_chrono $temps_1
	
