# Directories
SRCDIR = src
BINDIR = bin
DOCDIR = docs

# Executable
TARGET = $(BINDIR)/display_change 

# Source files 
# wildcard walks through all .cpp files
CPPSOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Object files
# first arg is the the cpp's in src
OBJECTS = $(CPPSOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Compiler flags
# -Wall is all compiler warnings
# -g is debugging symbols
CXXFLAGS =	-Wall -g

# Linker flags, library files, none for this project since windows.h is included in mingw32
LDFLAGS =	

# generate docs after target
docs: $(TARGET)
	@echo "Generating documentation..."
	doxygen Doxyfile > doxygen.log 2>&1

# Main order, objects need to be compiled before linking
$(TARGET): $(OBJECTS)
	@echo "Linking $@ $(shell date +%s)"
	g++ $(OBJECTS) -o $(TARGET) $(LDFLAGS)
	@echo

# Rules for compiling CPP and RC filetypes
$(BINDIR)/%.o: $(SRCDIR)/%.cpp | $(BINDIR)
	@echo
	@echo "Compiling CPPs $< $(shell date +%s)"
	g++ $(CXXFLAGS) -c $< -o $@
	@echo

# Create bin directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# erase object files from bin folder
clean:
	@echo
	@echo "Cleaning up... "
	rm -rf $(BINDIR)/*.o $(TARGET)
	rm -rf docs
	rm -f doxygen.log
	@echo

# Phony targets
.PHONY: clean