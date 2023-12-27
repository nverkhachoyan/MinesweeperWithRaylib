# Name of the program
PROGRAM_NAME = main

# Base directory for the source and object files
BASEDIR = src

# Directories for object files, header files, and libraries
ODIR = obj
IDIR = include
LDIR = lib

# Compiler to use
CC = gcc

# Compiler flags: -Wall (show all warnings), -g (debugging), -I (include directory)
CFLAGS = -Wall -g -I$(IDIR)

# Libraries to include
LIBS = -lraylib

# Dependencies (header files)
_DEPS = main.h Init.h Board.h Cell.h Globals.h Cleanup.h GameLogic.h Utils.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Object files
_OBJ = main.o Init.o Cleanup.o GameLogic.o Utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(PROGRAM_NAME)
	@./$(PROGRAM_NAME)

# Rule to compile .c files into .o files (regular expressions)
$(ODIR)/%.o: $(BASEDIR)/%.c $(DEPS)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Build target
$(PROGRAM_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

# Rule to run the executable
run: $(PROGRAM_NAME)
	@./$(PROGRAM_NAME)

# Phony target for clean-up
.PHONY: clean

clean:
	@rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
	@echo "Build clean up complete."
