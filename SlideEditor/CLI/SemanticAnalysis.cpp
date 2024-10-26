#include "SemanticAnalysis.hpp"

bool SemanticAnalysis::isValidCommand(const std::string& command) {
    if (commandRules.find(command) != commandRules.end()) {
        currentCommand = command; 
        return true;
    }
    return false;
}

bool SemanticAnalysis::isValidArgument(const std::string& argument) {
    auto commandIt = commandRules.find(currentCommand);
    if (commandIt != commandRules.end()) {
        const auto& argMap = commandIt->second;
        if (argMap.find(argument) != argMap.end()) {
            currentArgument = argument; 
            return true;
        }
    }
    return false; 
}

bool SemanticAnalysis::isValidValue(const std::string& value) {
    auto commandIt = commandRules.find(currentCommand);
    if (commandIt != commandRules.end()) {
        const auto& argMap = commandIt->second;
        auto argIt = argMap.find(currentArgument);
        if (argIt != argMap.end()) {
            return argIt->second(value); 
        }
    }
    return false; 
}

bool SemanticAnalysis::isValidPositiveInteger(const std::string& value) {
    std::istringstream iss(value);
    int intValue;
    iss >> intValue;
    return !iss.fail() && intValue > 0;
}

bool SemanticAnalysis::isValidColor(const std::string& value) {
    // Define a set of valid color names
    static const std::unordered_set<std::string> validColors = {
        "red", "green", "blue", "yellow", "black", "white", "purple", "orange", "pink", "gray", "brown"
    };

    return validColors.find(value) != validColors.end();
}
