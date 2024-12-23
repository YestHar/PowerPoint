#include "CommandFactory.hpp"

std::unique_ptr<ICommand> CommandFactory::createCommand(const std::string& commandWord, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& commandArgs) {
    auto it = commandMap.find(commandWord);
    if (it != commandMap.end()) {
        return it->second(commandArgs);
    }
    return nullptr; // Or handle unknown command case
}