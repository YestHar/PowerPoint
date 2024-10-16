#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <memory>
#include <string>
#include "Command.hpp"  // Assuming ICommand is the base class for all commands

class CommandFactory {
public:
    std::unique_ptr<ICommand> createCommand(const std::string& commandWord, const std::string& argument, const std::string& value) {
        if (commandWord == "addSlide") {
            // Return the specific command object for addSlide
            return std::make_unique<AddSlideCommand>(argument, value); // Example command
        }
        else if (commandWord == "removeSlide") {
            // Return the specific command object for removeSlide
            return std::make_unique<RemoveSlideCommand>(argument, value); // Example command
        }
        // Add more commands as needed...
        else {
            throw std::runtime_error("Unknown command: " + commandWord);
        }
    }
};

#endif // COMMANDFACTORY_HPP
