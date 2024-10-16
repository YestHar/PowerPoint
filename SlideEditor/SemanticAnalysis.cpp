#include "SemanticAnalysis.hpp"

bool SemanticAnalysis::isValidCommand(const std::string& command) {
        return commandRules.find(command) != commandRules.end();
    }

bool SemanticAnalysis::isValidArgument(const std::string& command, const std::string& argument) {
    if (commandRules.find(command) == commandRules.end()) {
        throw std::runtime_error("Unknown command: " + command);
    }
    return commandRules[command].validArgs.find(argument) != commandRules[command].validArgs.end();
}

bool SemanticAnalysis::isValidValue(const std::string& command, const std::string& value) {
    if (commandRules.find(command) == commandRules.end()) {
        throw std::runtime_error("Unknown command: " + command);
    }
    return commandRules[command].validateValue(value);
}

