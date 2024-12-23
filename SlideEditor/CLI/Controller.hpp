#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../Application/Application.hpp"
#include "Command/ICommand.hpp"
#include "Parser.hpp"
#include <memory>
#include <iostream>

class Parser;

class Controller {
public:
    // Starts the program, parsing commands and executing them
    void startProgram();

};

#endif // CONTROLLER_HPP
