# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Source files
SRCS = main.cpp Parser.hpp Command.hpp CommandFactory.hpp Controller.hpp SemanticAnalysis.hpp SyntaxAnalysis.hpp Tokenizer.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
