# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17  # Updated to C++17

# Source files
SRCS = main.cpp \
    CLI/Command.cpp \
    CLI/CommandFactory.cpp \
    CLI/Controller.cpp \
    CLI/Parser.cpp \
    CLI/SemanticAnalysis.cpp \
    CLI/Tokenizer.cpp \
    Document/Item.cpp \
    Document/Slide.cpp \
    Document/SlideCollection.cpp \
    Editor/Editor.cpp

# Header files
HDRS = CLI/Command.hpp \
    CLI/CommandFactory.hpp \
    CLI/Controller.hpp \
    CLI/Parser.hpp \
    CLI/SemanticAnalysis.hpp \
    CLI/Tokenizer.hpp \
    Document/Item.hpp \
    Document/Slide.hpp \
    Document/SlideCollection.hpp \
    Editor/Editor.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = start

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
