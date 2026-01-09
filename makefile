# Generated using Gemini; I don't know how to write MakeFiles

#-Wall -Wextra
# Define the compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++17 -I $(INCDIR)

# Define directories and target
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = my_program

# 1. FIND ALL SOURCE FILES, including those in subdirectories
SOURCES := $(shell find $(SRCDIR) -name "*.cpp")

# 2. CREATE A LIST OF DIRECTORIES NEEDED IN THE BUILD FOLDER
# This finds all subdirectories in src and maps them to the build path
SUBDIRS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(shell find $(SRCDIR) -type d))

# 3. GENERATE THE LIST OF OBJECT FILES (.o) with the correct path
# Substitutes 'src' with 'build' and '.cpp' with '.o'
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

# --- Targets ---

# The default target - builds the executable
all: $(SUBDIRS) $(TARGET)

# Rule to recursively create the required build subdirectories
$(SUBDIRS):
	@mkdir -p $@

# Rule to create the executable (Linking step)
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Rule to compile each .cpp file into an object file .o
# The prerequisite is the corresponding .cpp
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for cleaning up compiled files and the executable
clean:
	@rm -rf $(BUILDDIR) $(TARGET)
	@echo "Cleaned up build directory and executable."

test:
	

# Phony targets
.PHONY: all clean