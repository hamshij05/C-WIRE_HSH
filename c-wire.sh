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
