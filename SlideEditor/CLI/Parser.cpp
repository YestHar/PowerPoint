#include "Parser.hpp"

std::shared_ptr<ICommand> Parser::parse(std::istream& inputStream) {
    enum class State { Start, Cmd, CurrentCmd, Arg, Value, Error, End };

    const std::unordered_map<State, std::unordered_map<SToken::EType, State>> stateMachine = {
        { State::Start,      { { SToken::EType::Word, State::Cmd }, { SToken::EType::EOL, State::End }, { SToken::EType::Arg, State::Error }, { SToken::EType::Value, State::Error }, { SToken::EType::Invalid, State::Error } } },
        { State::Cmd,        { { SToken::EType::Word, State::Cmd }, { SToken::EType::Arg, State::CurrentCmd }, { SToken::EType::EOL, State::End }, { SToken::EType::Value, State::Error }, { SToken::EType::Invalid, State::Error } } },
        { State::CurrentCmd, { { SToken::EType::Arg, State::Arg } } },
        { State::Arg,        { { SToken::EType::Arg, State::Arg }, { SToken::EType::Value, State::Value }, { SToken::EType::EOL, State::Error }, { SToken::EType::Word, State::Value }, { SToken::EType::Invalid, State::Error } } },
        { State::Value,      { { SToken::EType::Value, State::Value }, { SToken::EType::Arg, State::Arg }, { SToken::EType::EOL, State::End }, { SToken::EType::Word, State::Error }, { SToken::EType::Invalid, State::Error } } }
    };

    State currentState = State::Start;
    std::string commandWord, argument, value;
    
    SemanticAnalysis semanticAnalyzer;
    CommandFactory commandFactory;

    std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>> commandArgs;

    while (true) {
        std::shared_ptr<SToken> token = tokenizer->tokenize(inputStream);
        if (!token) break; 

        // Determine the next state based on the current state and token type
        auto nextStateIt = stateMachine.at(currentState).find(token->_type);
        if (nextStateIt == stateMachine.at(currentState).end()) {
            currentState = State::Error;
        } else {
            currentState = nextStateIt->second;
        }

        std::cout << int(currentState) << std::endl;

        // Process tokens based on the current state
        switch (currentState) {
            case State::Cmd:
                commandWord += std::get<std::string>(token->_content);
                break;

            case State::CurrentCmd:
                std::cout << "CURRENT CMD STATE" << std::endl;
                if (!semanticAnalyzer.isValidCommand(commandWord)) {
                    throw std::runtime_error("Invalid command: " + commandWord);
                }
                currentState = State::Arg;
                std::cout << int(currentState) << std::endl;
                // break;

            case State::Arg:
                std::cout << "ARG STATE" << std::endl;
                if (std::holds_alternative<std::string>(token->_content)) {
                argument = std::get<std::string>(token->_content);
                } else {
                    std::cerr << "Error: token->_content does not hold a std::string" << std::endl;
                }
                if (!semanticAnalyzer.isValidArgument(argument)) {
                    throw std::runtime_error("Invalid argument: " + argument);
                }
                commandArgs[argument] = {}; 
                break;

            case State::Value:
                std::cout << "VALUE STATE" << std::endl;
                if (std::holds_alternative<int>(token->_content)) {
                    int val = std::get<int>(token->_content);
                    value = std::to_string(val);
                } else if (std::holds_alternative<std::string>(token->_content)) {
                    std::cout << "string" << std::endl;
                    value = std::get<std::string>(token->_content);
                } else {
                    std::cerr << "Error: token->_content does not hold a std::string" << std::endl;
                }
                if (!semanticAnalyzer.isValidValue(value)) {
                    throw std::runtime_error("Invalid value: " + value);
                }
                commandArgs[argument].push_back(token->_content);
                break;

            case State::End:
                std::cout << "END STATE" << std::endl;
                return commandFactory.createCommand(commandWord, commandArgs);

            case State::Error:
                throw std::runtime_error("Parsing error: Invalid token encountered.");

            default:
                throw std::runtime_error("Unexpected state encountered.");
        }
    }

    throw std::runtime_error("Unexpected end of input: Incomplete command.");
}
