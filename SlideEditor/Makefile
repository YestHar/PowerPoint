# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17  # Updated to C++17

# Source files
SRCS = main.cpp Parser.cpp Command.cpp CommandFactory.cpp Controller.cpp Document.cpp Editor.cpp SemanticAnalysis.cpp Tokenizer.cpp SyntaxAnalysis.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = main

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files and generate dependencies
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MF"$(@:.o=.d)" -c $<

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET) *.d

.PHONY: all clean

# Include dependency files
-include $(OBJS:.o=.d)
