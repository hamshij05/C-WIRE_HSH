#!/bin/bash


if [ $# -lt 1 ]; 
	then
	echo "Problème: nombre d'argument insuffisant"
	exit 1
fi

station=0
conso=0

if [ "$1" = "hvb" ]; 
	then
	station=1
elif [ "$1" = "hva" ]; 
	then
	station=2
elif [ "$1" = "lv" ]; 
	then
	station=3
else
	echo "Problème: mauvais premier argument"
	exit 1
fi
 
elif [ "$2" = "comp" ]; 
	then
	conso=1
elif [ "$2" = "indiv" ]; 
	then
	conso=2
elif [ "$2" = "all" ]; 
	then
	conso=3
else
	echo "Problème: mauvais second argument"
	exit 1
fi


echo "Station: $station, Conso: $conso"
