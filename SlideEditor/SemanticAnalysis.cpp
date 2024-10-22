#include "SemanticAnalysis.hpp"

bool SemanticAnalysis::isValidCommand(const std::string& command) {
        return commandRules.find(command) != commandRules.end();
    }

// Check if an argument is valid for a given command
bool SemanticAnalysis::isValidArgument(const std::string& command, const std::string& argument) {
    auto commandIt = commandRules.find(command);
    if (commandIt != commandRules.end()) {
        const auto& argMap = commandIt->second;
        return argMap.find(argument) != argMap.end();
    }
    return false; // Argument not found for the given command
}

// Check if the value is valid for a given argument under a given command
bool SemanticAnalysis::isValidValue(const std::string& command, const std::string& argument, const std::string& value) {
    auto commandIt = commandRules.find(command);
    if (commandIt != commandRules.end()) {
        const auto& argMap = commandIt->second;
        auto argIt = argMap.find(argument);
        if (argIt != argMap.end()) {
            // Call the validation function for the value
            return argIt->second(value);  // Validate using the function defined in commandRules
        }
    }
    return false; // Argument or validation function not found
}


bool SemanticAnalysis::isValidPositiveInteger(const std::string& value) {
        std::istringstream iss(value);
        int intValue;
        iss >> intValue;
        // Check if the conversion succeeded and the integer is greater than 0
        return !iss.fail() && intValue > 0;
}

bool SemanticAnalysis::isValidColor(const std::string& value) {
    // Define a set of valid color names
    static const std::unordered_set<std::string> validColors = {
        "red", "green", "blue", "yellow", "black", "white", "purple", "orange", "pink", "gray", "brown"
    };

    // Check if the value is in the set of valid colors
    return validColors.find(value) != validColors.end();
}
