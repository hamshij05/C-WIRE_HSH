#!/bin/bash

# Check if the minimum number of arguments is provided
if [ $# -lt 1 ]; then
    echo "Problème: nombre d'argument insuffisant"
    exit 1
fi

# Initialize variables
station=0
conso=0

# Check the value of $2
if [ "$2" = "hvb" ]; then
    station=1
elif [ "$2" = "hva" ]; then
    station=2
elif [ "$2" = "lv" ]; then
    station=3
elif [ "$2" = "comp" ]; then
    conso=1
elif [ "$2" = "indiv" ]; then
    conso=2
elif [ "$2" = "all" ]; then
    conso=3
else
    echo "Problème: mauvais argument"
    exit 1
fi

# Example output to debug the result
echo "Station: $station, Conso: $conso"
