#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <memory>
#include <sstream>
#include "Tokenizer.hpp"
#include "SemanticAnalysis.hpp"
#include "Command.hpp"
#include "CommandFactory.hpp"

class Tokenizer;
class SemanticAnalysis;
class ICommand;
class CommandFactory;

class Parser {
private:
    std::unique_ptr<Tokenizer> tokenizer;
    std::unique_ptr<SemanticAnalysis> semanticAnalyzer;

public:
    Parser() 
        : tokenizer(std::make_unique<Tokenizer>()), 
          semanticAnalyzer(std::make_unique<SemanticAnalysis>())
    {}

    std::unique_ptr<ICommand> parse(std::istream& input);
};

#endif // PARSER_HPP