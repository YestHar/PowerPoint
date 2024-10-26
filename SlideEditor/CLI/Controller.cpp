#include "Controller.hpp"

void Controller::startProgram() {
    while (true) {
        try {
            Parser parser;

            std::unique_ptr<ICommand> command = parser.parse(std::cin);

            command->exe();

            break;

        } catch (const std::exception& e) {
            std::cerr << "Parsing error: " << e.what() << std::endl;
        }
    }
}