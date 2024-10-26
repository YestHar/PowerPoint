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
    bool isValidArgument(const std::string& argument);
    bool isValidValue(const std::string& value);

    static bool isValidPositiveInteger(const std::string& value);
    static bool isValidColor(const std::string& value);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<bool(const std::string&)>>> commandRules = {
        {"addslide", {{"pos", isValidPositiveInteger}}},
        {"removeslide", {{"pos", isValidPositiveInteger}}},
        {"view", {{"pos", isValidPositiveInteger}}},
        {"exit", {}},
        {"help", {}},
        {"changeslidebg", {{"slide_id", isValidPositiveInteger}, {"color", isValidColor}}},
        {"swapslide", {{"pos", isValidPositiveInteger}}}
    };

    std::string currentCommand;
    std::string currentArgument;
};

#endif // SEMANTICANALYSIS_HPP
