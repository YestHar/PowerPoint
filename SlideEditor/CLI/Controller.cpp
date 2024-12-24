#include "Controller.hpp"
#include <iostream>
#include <memory>
#include <exception>

void Controller::startProgram() {
    while (true) {
        try {
            // Use the existing Parser instance from the Application
            auto parser = Application::get_instance().get_parser();

            // Parse the input command
            std::shared_ptr<ICommand> command = parser->parse(std::cin);

            // Execute the command 
            command->exe();

            // Check if the command indicates the program should exit
            if (command->should_exit()) {
                std::cout << "Exiting program...\n";
                break;
            }

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
