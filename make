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
