#premiere cible : sera executée en premier
all:exec

# Compilation de main.c
main.o: main.c biblio.h
      -gcc -c main.c -o main.o

# Compilation de fonction.c
fonction.o: fonction.c biblio.h
      -gcc -c fonction.c -o fonction.o

exec: main.o fonction.o
      gcc fonction.o main.o -o exec

#supprime tous les fichier objectifs
clean:
      rm -f *.o
      rm exec
