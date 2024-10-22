#ifndef   SyntaxAnalysis_HPP
#define   SyntaxAnalysis_HPP

#include "Tokenizer.hpp"
#include <unordered_map>
class SyntaxAnalysis {
private:
    // Tokenizer* tokenizer;

public:
    // Constructor that takes a pointer to the Tokenizer object
    // SyntaxAnalysis(Tokenizer* tokenizer) : tokenizer(tokenizer) {}

    // // Syntax analysis function that returns an unordered_map representing the command
    std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>> analyze(std::istream& inputStream);
    // void printCommandMap(const std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>>& commandMap);
};

#endif //SyntaxAnalysis_HPP