#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <sstream>
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
          semanticAnalyzer(nullptr) // Will add semantic analysis later
    {}

    // The parse function that processes the input and returns a command object
    std::unique_ptr<ICommand> parse(std::istringstream& inputStream);
};

#endif // PARSER_HPP
