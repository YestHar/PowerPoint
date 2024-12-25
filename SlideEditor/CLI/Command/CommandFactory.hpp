#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <variant>
#include "RemoveSlide.hpp"
#include "AddSlide.hpp"
#include "Exit.hpp"
#include "Help.hpp"
#include "UndoRedo.hpp"
#include "SaveCommand.hpp"
#include "LoadCommand.hpp"
#include "View.hpp"

class CommandFactory {
public:
    using CommandCreator = std::function<std::shared_ptr<ICommand>(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>&)>;

    CommandFactory() {
        // Initialize command map with associated creation functions
        commandMap = {
            {"addslide", [this](const auto& args) { return this->createAddSlide(args); }},
            {"removeslide", [this](const auto& args) { return this->createRemoveSlide(args); }},
            {"view", [this](const auto& args) { return this->createView(args); }},
            {"save", [this](const auto& args) { return this->createSave(args); }},
            {"load", [this](const auto& args) { return this->createLoad(args); }},
            {"exit", [this](const auto&) { return createExit(); }},
            {"help", [this](const auto&) { return createHelp(); }},
            {"undo", [this](const auto&) { return createUndo(); }},
            {"redo", [this](const auto&) { return createRedo(); }},
        };
    }

    std::shared_ptr<ICommand> createCommand(const std::string& commandWord, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& commandArgs);

private:
    std::unordered_map<std::string, CommandCreator> commandMap;

    // Command creation functions simplified to no longer need Editor or Visualization
    std::shared_ptr<ICommand> createAddSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_shared<AddSlide>(args);  
    }

    std::shared_ptr<ICommand> createRemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_shared<RemoveSlide>(args); 
    }

    std::shared_ptr<ICommand> createView(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_shared<View>(args);
    }

    std::shared_ptr<ICommand> createExit() {
        return std::make_shared<Exit>();
    }

    std::shared_ptr<ICommand> createHelp() {
        return std::make_shared<Help>();
    }

    std::shared_ptr<ICommand> createUndo() {
        return std::make_shared<Undo>();
    }

    std::shared_ptr<ICommand> createRedo() {
        return std::make_shared<Redo>();
    }

    std::shared_ptr<ICommand> createSave(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_shared<SaveCommand>(args);
    }

    std::shared_ptr<ICommand> createLoad(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_shared<LoadCommand>(args);
    }

    
};

#endif // COMMANDFACTORY_HPP

