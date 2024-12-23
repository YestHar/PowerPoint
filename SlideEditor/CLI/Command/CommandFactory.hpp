#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <variant>
#include "ICommand.hpp"
#include "RemoveSlide.hpp"
#include "AddSlide.hpp"
#include "Exit.hpp"
#include "Help.hpp"

class CommandFactory {
public:
    using CommandCreator = std::function<std::unique_ptr<ICommand>(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>&)>;

    CommandFactory() {
        // Initialize command map with associated creation functions
        commandMap = {
            {"addSlide", [this](const auto& args) { return this->createAddSlide(args); }},
            {"removeSlide", [this](const auto& args) { return this->createRemoveSlide(args); }},
            {"exit", [](const auto&) { return createExit(); }},
            {"help", [](const auto&) { return createHelp(); }},
        };
    }

    std::unique_ptr<ICommand> createCommand(const std::string& commandWord, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& commandArgs) {
        auto it = commandMap.find(commandWord);
        if (it != commandMap.end()) {
            return it->second(commandArgs);
        }
        throw std::runtime_error("Unknown command: " + commandWord);
    }

private:
    std::unordered_map<std::string, CommandCreator> commandMap;

    // Command creation functions simplified to no longer need Editor or Visualization
    std::unique_ptr<ICommand> createAddSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<AddSlide>(args);  
    }

    std::unique_ptr<ICommand> createRemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
        return std::make_unique<RemoveSlide>(args); 
    }

    static std::unique_ptr<ICommand> createExit() {
        return std::make_unique<Exit>();
    }

    static std::unique_ptr<ICommand> createHelp() {
        return std::make_unique<Help>();
    }
};

#endif // COMMANDFACTORY_HPP


// #ifndef COMMANDFACTORY_HPP
// #define COMMANDFACTORY_HPP

// #include <memory>
// #include <string>
// #include <unordered_map>
// #include <functional>
// #include <variant>
// // #include "ICommand.hpp"
// #include "RemoveSlide.hpp"
// #include "AddSlide.hpp"
// #include "Exit.hpp"
// #include "Help.hpp"

// class ICommand;
// class RemoveSlide;
// class AddSlide;


// class CommandFactory {
// public:
//     using CommandCreator = std::function<std::unique_ptr<ICommand>(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>&)>;

//     CommandFactory() {
//         // Initialize command map with associated creation functions
//         commandMap = {
//             {"addSlide", [this](const auto& args) { return this->createAddSlide(args); }},
//             {"removeSlide", [this](const auto& args) { return this->createRemoveSlide(args); }},
//             // {"view", [this](const auto& args) { return createView(args); }},
//             {"exit", [](const auto&) { return createExit(); }},
//             {"help", [](const auto&) { return createHelp(); }},
//             // {"changeSlideBg", [this](const auto& args) { return createChangeSlideBg(args); }},
//             // {"swapSlide", [this](const auto& args) { return createSwapSlide(args); }},
//         };
//     }

//     std::unique_ptr<ICommand> createCommand(const std::string& commandWord, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& commandArgs) {
//         auto it = commandMap.find(commandWord);
//         if (it != commandMap.end()) {
//             return it->second(commandArgs); // Create command using the function in the map
//         }
//         throw std::runtime_error("Unknown command: " + commandWord);
//     }

// private:
//     std::unordered_map<std::string, CommandCreator> commandMap;

//     // Command creation functions simplified to no longer need Editor or Visualization
//     std::unique_ptr<ICommand> createAddSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
//         return std::make_unique<AddSlide>(args);  
//     }

//     std::unique_ptr<ICommand> createRemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
//         return std::move(std::make_unique<RemoveSlide>(args)); 
//     }

//     // std::unique_ptr<ICommand> createView(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
//     //     return std::make_unique<View>(args);  
//     // }

//     static std::unique_ptr<ICommand> createExit() {
//         return std::make_unique<Exit>();
//     }

//     static std::unique_ptr<ICommand> createHelp() {
//         return std::make_unique<Help>();
//     }

//     // std::unique_ptr<ICommand> createChangeSlideBg(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
//     //     return std::make_unique<ChangeSlideBg>(args);  // Editor will be accessed inside ChangeSlideBg
//     // }

//     // std::unique_ptr<ICommand> createSwapSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args) {
//     //     return std::make_unique<SwapSlide>(args);  // Editor will be accessed inside SwapSlide
//     // }
// };

// #endif // COMMANDFACTORY_HPP

