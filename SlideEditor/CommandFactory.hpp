#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include "Command.hpp"  

class CommandFactory {
public:
    // Define the function signature for command creation functions
    using CommandCreator = std::function<std::unique_ptr<ICommand>(std::unordered_map<std::string, std::vector<std::string>>&)>;

    CommandFactory() {
        // Initialize the command map
        commandMap = {
            {"addSlide", [this](const auto& args) { return createAddSlide(args); }},
            {"removeSlide", [this](const auto& args) { return createRemoveSlide(args); }},
            {"view", [this](const auto& args) { return createView(args); }},
            {"exit", [this](const auto&) { return createExit(); }},
            {"help", [this](const auto&) { return createHelp(); }},
            {"changeSlideBg", [this](const auto& args) { return createChangeSlideBg(args); }},
            {"swapSlide", [this](const auto& args) { return createSwapSlide(args); }},
        };
    }

    std::unique_ptr<ICommand> createCommand(const std::string& commandWord, std::unordered_map<std::string, std::vector<std::string>>& commandArgs) {
        auto it = commandMap.find(commandWord);
        if (it != commandMap.end()) {
            return it->second(commandArgs); // Call the command creation function
        }
        throw std::runtime_error("Unknown command: " + commandWord);
    }

private:
    // Map to hold command creators
    std::unordered_map<std::string, CommandCreator> commandMap;

    // Helper functions to create specific command objects
    std::unique_ptr<ICommand> createAddSlide(const std::unordered_map<std::string, std::vector<std::string>>& args) {
        return std::make_unique<AddSlide>(args); 
    }

    std::unique_ptr<ICommand> createRemoveSlide(const std::unordered_map<std::string, std::vector<std::string>>& args) {
        return std::make_unique<RemoveSlide>(args); 
    }

    std::unique_ptr<ICommand> createView(const std::unordered_map<std::string, std::vector<std::string>>& args) {
        return std::make_unique<View>(args);
    }

    std::unique_ptr<ICommand> createExit() {
        return std::make_unique<Exit>();
    }

    std::unique_ptr<ICommand> createHelp() {
        return std::make_unique<Help>();
    }

    std::unique_ptr<ICommand> createChangeSlideBg(const std::unordered_map<std::string, std::vector<std::string>>& args) {
        return std::make_unique<ChangeSlideBg>(args);
    }

    std::unique_ptr<ICommand> createSwapSlide(const std::unordered_map<std::string, std::vector<std::string>>& args) {
        return std::make_unique<SwapSlide>(args);
    }
    // Add more helper functions for additional commands as needed...
};

#endif // COMMANDFACTORY_HPP
