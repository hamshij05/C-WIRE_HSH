#!/bin/bash
 
if [ $# -lt 1 ]
then
	echo "probleme: nombre d'argument"
	exit()
fi

if [ $2="hvb" ]
then
	station=1
	
elif [ $2="hva" ]
then 
	station=2
	
elif [ $2="lv" ]
then
	station=3

elif [ $2="comp" ]
then
	conso=1

elif [ $2="indiv" ]
then
	conso=2
	
elif [ $2="all" ]
then
	conso=3

else	
	echo "probleme: mauvais argument"		

fi
