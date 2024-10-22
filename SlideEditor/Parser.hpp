#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <memory>
#include <sstream>
#include <variant>

#include "Tokenizer.hpp"
#include "SyntaxAnalysis.hpp"
#include "SemanticAnalysis.hpp"
#include "Command.hpp"
#include "CommandFactory.hpp"

// Forward declarations
class Tokenizer;
class SyntaxAnalysis;
class SemanticAnalysis;
class ICommand;
class CommandFactory;

class Parser {
private:
    // Pointers to Tokenizer, SyntaxAnalysis, and SemanticAnalysis
    std::unique_ptr<Tokenizer> tokenizer;
    std::unique_ptr<SyntaxAnalysis> syntaxAnalyzer;
    std::unique_ptr<SemanticAnalysis> semanticAnalyzer;

public:
    // Constructor: initialize pointers
    Parser() 
        : tokenizer(std::make_unique<Tokenizer>()), 
          syntaxAnalyzer(std::make_unique<SyntaxAnalysis>()),
          semanticAnalyzer(std::make_unique<SemanticAnalysis>())
    {}

    // The parse function that processes the input and returns a command object
    std::unique_ptr<ICommand> parse(std::istream& input);
};

#endif // PARSER_HPP
