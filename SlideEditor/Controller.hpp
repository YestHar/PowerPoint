#ifndef   Controller_HPP
#define   Controller_HPP

#include <iostream>
#include <sstream>
#include "Parser.hpp"
#include "Command.hpp"

// Forward declaration of Parser
class Parser;

class Controller {
public:
    void startProgram() {
        while (true) {
            try {
                // Instantiate a Parser object
                Parser parser;

                // Get a Command object after parsing
                std::unique_ptr<ICommand> command = parser.parse(std::cin);

                // Execute the command
                command->exe();

                break;

            } catch (const std::exception& e) {
                // Handle exceptions during parsing
                std::cerr << "Parsing error: " << e.what() << std::endl;
            }
        }
    }
};

#endif // Controller_HPP
