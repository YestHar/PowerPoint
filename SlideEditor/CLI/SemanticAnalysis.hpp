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
    static bool isValidFilename(const std::string& filename);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<bool(const std::string&)>>> commandRules = {
        {"addslide", {{"pos", isValidPositiveInteger}}},
        {"removeslide", {{"pos", isValidPositiveInteger}}},
        {"view", {{"id", isValidPositiveInteger}}},
        {"addshape", {{"id", isValidPositiveInteger}, {"type", isValidPositiveInteger}, {"color", isValidColor}, {"borderwidth", isValidPositiveInteger}, {"bordercolor", isValidColor}, {"x", isValidPositiveInteger}, {"y", isValidPositiveInteger}, {"width", isValidPositiveInteger}, {"height", isValidPositiveInteger}}},
        {"removeshape", {{"id", isValidPositiveInteger}, {"shapeid", isValidPositiveInteger}}},
        {"changeshapecolor", {{"id", isValidPositiveInteger}, {"shapeid", isValidPositiveInteger}, {"color", isValidColor}}},
        {"changeshapeborder", {{"id", isValidPositiveInteger}, {"shapeid", isValidPositiveInteger}, {"borderwidth", isValidPositiveInteger}, {"bordercolor", isValidColor}}},
        {"exit", {}},
        {"help", {}},
        {"udno", {}},
        {"redo", {}},
        {"save", {{"filename", isValidFilename}}},
        {"load", {{"filename", isValidFilename}}},
        {"changeslidebg", {{"id", isValidPositiveInteger}, {"color", isValidColor}}},
        {"swapslide", {{"pos", isValidPositiveInteger}}}
    };

    std::string currentCommand;
    std::string currentArgument;
};

#endif // SEMANTICANALYSIS_HPP
