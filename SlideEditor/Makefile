# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17
CXXFLAGS += -I/path/to/nlohmann/json

# Directories
SRC_DIR = .
CLI_DIR = $(SRC_DIR)/CLI
CLI_CMD_DIR = $(CLI_DIR)/Command
DOC_DIR = $(SRC_DIR)/Document
EDITOR_DIR = $(SRC_DIR)/Editor
VIS_DIR = $(SRC_DIR)/Visualization
APP_DIR = $(SRC_DIR)/Application

# Source files
SRCS = main.cpp \
    $(APP_DIR)/Application.cpp \
    $(CLI_CMD_DIR)/AddSlide.cpp \
    $(CLI_CMD_DIR)/CommandFactory.cpp \
    $(CLI_CMD_DIR)/Exit.cpp \
    $(CLI_CMD_DIR)/Help.cpp \
    $(CLI_CMD_DIR)/ICommand.cpp \
    $(CLI_CMD_DIR)/RemoveSlide.cpp \
    $(CLI_DIR)/Controller.cpp \
    $(CLI_DIR)/Parser.cpp \
    $(CLI_DIR)/SemanticAnalysis.cpp \
    $(CLI_DIR)/Tokenizer.cpp \
    $(DOC_DIR)/Item.cpp \
    $(DOC_DIR)/Slide.cpp \
    $(DOC_DIR)/SlideCollection.cpp \
    $(EDITOR_DIR)/AddSlideAction.cpp \
    $(EDITOR_DIR)/Editor.cpp \
    $(EDITOR_DIR)/RemoveSlideAction.cpp \
    $(VIS_DIR)/Visualization.cpp

# Header files
HDRS = $(APP_DIR)/Application.hpp \
    $(CLI_CMD_DIR)/AddSlide.hpp \
    $(CLI_CMD_DIR)/CommandFactory.hpp \
    $(CLI_CMD_DIR)/Exit.hpp \
    $(CLI_CMD_DIR)/Help.hpp \
    $(CLI_CMD_DIR)/ICommand.hpp \
    $(CLI_CMD_DIR)/RemoveSlide.hpp \
    $(CLI_DIR)/Controller.hpp \
    $(CLI_DIR)/Parser.hpp \
    $(CLI_DIR)/SemanticAnalysis.hpp \
    $(CLI_DIR)/Tokenizer.hpp \
    $(DOC_DIR)/Item.hpp \
    $(DOC_DIR)/Slide.hpp \
    $(DOC_DIR)/SlideCollection.hpp \
    $(EDITOR_DIR)/AddSlideAction.hpp \
    $(EDITOR_DIR)/Editor.hpp \
    $(EDITOR_DIR)/IAction.hpp \
    $(EDITOR_DIR)/RemoveSlideAction.hpp \
    $(VIS_DIR)/IVisualization.hpp \
    $(VIS_DIR)/Visualization.hpp

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

# Clean target to remove object files, dependency files, and the executable
clean:
	rm -f $(OBJS) $(TARGET) $(OBJS:.o=.d)

.PHONY: all clean

# Include dependency files
-include $(OBJS:.o=.d)
