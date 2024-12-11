CC=gcc
SRC=$(wildcard *.c) 
OBJ=$(SRC:.c=.o)
#nom repertoire
BUILD_DIR=build

#mise à jour liste obj avec nom dossier
OBJ2=$(addprefix $(BUILD_DIR)/, $(OBJ))
all: $(BUILD_DIR)/exec

#BUILD_DIR sert de dépendance
$(BUILD_DIR)/%.o : %.c tri.h $(BUILD_DIR)
      $(CC) -c $< -o $@

$(BUILD_DIR)/exec: $(OBJ2)
      $(CC) $^ -o $@

#creation repertoire
$(BUILD_DIR):
      mkdir -p $(BUILD_DIR)/
 clean:
    rm -rf $(BUILD_DIR)


#premiere cible : sera executée en premier
all:exec
main.o: main.c fonction.c biblio.h
      -gcc -c main.c -o main.o

fonction_tri.o: fonction_biblio.c biblio.h
      -gcc -c fonction_tri.c -o fonction_tri.o

fonction_tableau.o: fonction_tableau.c tri.h
      -gcc -c foncion_tableau.c -o fonction_tableau.o
exec: main.o fonction_tri.o fonction_tableau.o
      gcc fonction_tableau.o main.o fonction_tri.o -o exec
#supprime tous les fichier objectifs
clean:
      rm -f *.o
      rm exec
