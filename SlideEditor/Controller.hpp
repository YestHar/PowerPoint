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
        std::string input;

        while (true) {
            // Get input from the user
            std::cout << "Enter your command: ";
            getline(std::cin, input);

            // Convert the input to an input stream
            std::istringstream inputStream(input);

            try {
                // Instantiate a Parser object
                Parser parser;

                // Get a Command object after parsing
                std::unique_ptr<ICommand> command = parser.parse(inputStream);

                // Execute the command
                command->exe();

                // Exit loop if needed (for example, if you have a quit command)
                break;

            } catch (const std::exception& e) {
                // Handle exceptions during parsing
                std::cerr << "Parsing error: " << e.what() << std::endl;
            }
        }
    }
};

#endif // Controller_HPP
