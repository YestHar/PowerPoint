cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SlideEditor)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/Application
    ${CMAKE_SOURCE_DIR}/CLI/Command
    ${CMAKE_SOURCE_DIR}/CLI
    ${CMAKE_SOURCE_DIR}/Document
    ${CMAKE_SOURCE_DIR}/Editor
    ${CMAKE_SOURCE_DIR}/Visualization
)

# Define source files for the project
set(SOURCES
    main.cpp

    # Application
    Application/Application.cpp

    # CLI
    CLI/Tokenizer.cpp
    CLI/Parser.cpp
    CLI/SemanticAnalysis.cpp
    CLI/Controller.cpp
    CLI/Command/AddSlide.cpp
    CLI/Command/CommandFactory.cpp
    CLI/Command/Exit.cpp
    CLI/Command/Help.cpp
    CLI/Command/RemoveSlide.cpp
    CLI/Command/ICommand.cpp
    CLI/Command/SaveCommand.cpp  # New file
    CLI/Command/LoadCommand.cpp  # New file
    CLI/Command/UndoRedo.cpp
    CLI/Command/View.cpp

    # Document
    Document/DocumentSerializer.cpp
    Document/Item.cpp
    Document/Slide.cpp
    Document/SlideCollection.cpp

    # Editor
    Editor/AddSlideAction.cpp
    Editor/Editor.cpp
    Editor/RemoveSlideAction.cpp

    # Visualization
    Visualization/Visualization.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Specify additional compilation options if needed
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
