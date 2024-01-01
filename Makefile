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
LIBS = -L/opt/homebrew/Cellar/raylib/5.0/lib -lraylib

# Automatically generate a list of header files from source files
HEADERS = $(wildcard $(BASEDIR)/*.h)

# Automatically generate a list of source files
SRC = $(wildcard $(BASEDIR)/*.c)

# Generate object file names based on source file names
_OBJ = $(notdir $(SRC:.c=.o))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(PROGRAM_NAME)
	@./$(PROGRAM_NAME)


# Rule to compile .c files into .o files
$(ODIR)/%.o: $(BASEDIR)/%.c $(HEADERS)
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
