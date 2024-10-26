#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include "Command.hpp"
#include "../Editor/Editor.hpp"

class Editor;

class CommandFactory {
public:
    using CommandCreator = std::function<std::unique_ptr<ICommand>(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>&)>;

    CommandFactory(Editor& editor) : editor(editor) {
        commandMap = {
            {"addSlide", [this](const auto& args) { return createAddSlide(args); }},
            {"removeSlide", [this](const auto& args) { return createRemoveSlide(args); }},
            {"view", [this](const auto& args) { return createView(args); }},
            {"exit", [](const auto&) { return createExit(); }},
            {"help", [](const auto&) { return createHelp(); }},
            {"changeSlideBg", [this](const auto& args) { return createChangeSlideBg(args); }},
            {"swapSlide", [this](const auto& args) { return createSwapSlide(args); }},
        };
    }

    std::unique_ptr<ICommand> createCommand(const std::string& commandWord, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& commandArgs);

private:
    Editor& editor; 
    std::unordered_map<std::string, CommandCreator> commandMap;

    std::unique_ptr<ICommand> createAddSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<AddSlide>(editor, args);
    }

    std::unique_ptr<ICommand> createRemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<RemoveSlide>(editor, args);
    }

    std::unique_ptr<ICommand> createView(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<View>(args);
    }

    static std::unique_ptr<ICommand> createExit() {
        return std::make_unique<Exit>();
    }

    static std::unique_ptr<ICommand> createHelp() {
        return std::make_unique<Help>();
    }

    std::unique_ptr<ICommand> createChangeSlideBg(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<ChangeSlideBg>(editor, args);
    }

    std::unique_ptr<ICommand> createSwapSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<SwapSlide>(editor, args);
    }
};

#endif // COMMANDFACTORY_HPP
