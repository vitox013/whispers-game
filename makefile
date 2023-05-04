# Project Name
PROJECT := main

# Source, Objects and Binaries folder
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler
CC := g++

# Flags
CPPFLAGS := -Iinclude -O2
CFLAGS   := -Wall
LDFLAGS  := -Llib 
LDLIBS   := -lm -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

.PHONY: all clean build

all: build $(PROJECT)

$(PROJECT): $(OBJ)
	@ $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@ echo '============================ Finished building ============================'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	@ mkdir -p $@

build:
	@ echo '=============== Started building project using g++ compiler ==============='
	@ $(RM) $(OBJ_DIR)/main.o

clean:
	@ $(RM) -r $(OBJ_DIR) $(PROJECT) $(BIN_DIR)

rebuild: clean all

# Abrir o arquivo executável após a compilação
run: $(PROJECT)
ifeq ($(OS),Windows_NT)
	@ echo "Windows detected, cannot automatically open executable."
else ifeq ($(shell uname),Darwin)
	@ echo "Opening executable..."
	@ open $(PROJECT)
else
	@ echo "Opening executable..."
	@ ./$(PROJECT)
endif

-include $(OBJ:.o=.d)
