#ifndef SEMANTICANALYSIS_HPP
#define SEMANTICANALYSIS_HPP

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stdexcept>
#include <sstream>
#include <functional>
#include <variant>

class SemanticAnalysis {
public:
    bool isValidCommand(const std::string& command);
    bool isValidArgument(const std::string& command, const std::string& argument);
    bool isValidValue(const std::string& command, const std::string& argument, const std::string& value);

    static bool isValidPositiveInteger(const std::string& value);
    static bool isValidColor(const std::string& value);

private:
    // Updated commandRules to include validation for arguments and their values
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<bool(const std::string&)>>> commandRules = {
        {"addslide", {{"pos", [](const std::string& value) { return isValidPositiveInteger(value); }}}},
        {"removeslide", {{"pos", [](const std::string& value) { return isValidPositiveInteger(value); }}}},
        {"view", {{"pos", [](const std::string& value) { return isValidPositiveInteger(value); }}}},
        {"exit", {}},
        {"help", {}},
        {"changeslidebg", {
            {"slide_id", [](const std::string& value) { return isValidPositiveInteger(value); }},
            {"color", [](const std::string& value) { return isValidColor(value); }},
        }},
        {"swapslide", {
            {"pos", [](const std::string& value) { return isValidPositiveInteger(value); }}
        }}
    };
};

#endif // SEMANTICANALYSIS_HPP
