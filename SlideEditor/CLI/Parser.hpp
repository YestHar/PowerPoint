#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <memory>
#include <sstream>
#include "Tokenizer.hpp"
#include "SemanticAnalysis.hpp"
#include "Command/CommandFactory.hpp"

class Tokenizer;
class SemanticAnalysis;
class ICommand;
class CommandFactory;

class Parser {
private:
    std::shared_ptr<Tokenizer> tokenizer;
    std::shared_ptr<SemanticAnalysis> semanticAnalyzer;

public:
    Parser() 
        : tokenizer(std::make_shared<Tokenizer>()), 
          semanticAnalyzer(std::make_shared<SemanticAnalysis>())
    {}

    std::shared_ptr<ICommand> parse(std::istream& input);
};

#endif // PARSER_HPP
