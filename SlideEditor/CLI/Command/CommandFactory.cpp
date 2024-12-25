#include "CommandFactory.hpp"

std::shared_ptr<ICommand> CommandFactory::createCommand(const std::string& commandWord, const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& commandArgs) {
    std::cout << commandWord << std::endl;
    auto it = commandMap.find(commandWord);
    if (it != commandMap.end()) {
        std::cout << "Creating command\n";
        return it->second(commandArgs);
    }
    std::cout << "NOT CREATE command\n";
    return nullptr; // Or handle unknown command case
}


