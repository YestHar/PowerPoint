#ifndef SEMANTICANALYSIS_HPP
#define SEMANTICANALYSIS_HPP

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stdexcept>
#include <sstream>
#include <functional>

class SemanticAnalysis {
public:
    // Struct to hold command validation rules
    struct CommandRule {
        std::unordered_set<std::string> validArgs;
        std::function<bool(const std::string&)> validateValue;
    };

    // Map to hold command rules
    std::unordered_map<std::string, CommandRule> commandRules = {
        {"addSlide", {{"pos"}, [](const std::string& value) { return isValidPositiveInteger(value); }}},
        {"removeSlide", {{"index"}, [](const std::string& value) { return isValidPositiveInteger(value); }}},
        {"editSlide", {{"index", "newContent"}, [](const std::string& value) { return !value.empty(); }}}
    };

    bool isValidCommand(const std::string& command);

    bool isValidArgument(const std::string& command, const std::string& argument);

    bool isValidValue(const std::string& command, const std::string& value);

    // Function to check if the provided string is a valid positive integer
    static bool isValidPositiveInteger(const std::string& value) {
        std::istringstream iss(value);
        int intValue;
        iss >> intValue;

        // Check if the conversion succeeded and the integer is greater than 0
        return !iss.fail() && intValue > 0;
    }
};

#endif // SEMANTICANALYSIS_HPP
