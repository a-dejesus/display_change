# Directories
SRCDIR = src
INCDIR = admin_prompt
BINDIR = bin

# Executable
TARGET = $(BINDIR)/display_change 

# Source files 
# wildcard walks through all .cpp files
CPPSOURCES = $(wildcard $(SRCDIR)/*.cpp)
RCSOURCES = $(wildcard $(INCDIR)/*.rc)

# Object files
# first arg is the the cpp's in src
# second arg is the .rc in admin_prompt
OBJECTS = $(CPPSOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o) $(RCSOURCES:$(INCDIR)/%.rc=$(BINDIR)/%.o) 

# Compiler flags
# -Wall is all compiler warnings
# -g is debugging symbols
CXXFLAGS =	-Wall -g

# Linker flags, library files, none for this project since windows.h is included in mingw32
LDFLAGS =	

# Main order, objects need to be compiled before linking
$(TARGET): $(OBJECTS)
	@echo "Linking $@ $(shell date +%s)"
	g++ $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo

# Rules for compiling CPP and RC filetypes
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@echo
	@echo "Compiling CPPs $< $(shell date +%s)"
	g++ $(CXXFLAGS) -c $< -o $@
	@echo

$(BINDIR)/%.o: $(INCDIR)/%.rc
	@echo "Compiling RCs $< $(shell date +%s)"
	windres $< -O coff -o $@
	@echo

# erase object files from bin folder
.PHONY: clean
clean:
	@echo
	@echo "Cleaning up... "
	rm -rf $(BINDIR)/*.o $(TARGET)
	@echo