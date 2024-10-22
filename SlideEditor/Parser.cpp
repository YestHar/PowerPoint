#include "Parser.hpp"

std::unique_ptr<ICommand> Parser::parse(std::istream& inputStream) {
    // Define the state machine
    enum class State { Start, Cmd, Arg, Value, Error };

    // State transition map
    const std::unordered_map<State, std::unordered_map<SToken::EType, State>> stateMachine = {
        { State::Start, { { SToken::EType::Word, State::Cmd }, { SToken::EType::Invalid, State::Error } } },
        { State::Cmd,   { { SToken::EType::Arg, State::Arg }, { SToken::EType::Word, State::Cmd }, { SToken::EType::Invalid, State::Error } } },
        { State::Arg,   { { SToken::EType::Value, State::Value }, { SToken::EType::Invalid, State::Error } } },
        { State::Value, { { SToken::EType::Value, State::Start }, { SToken::EType::Invalid, State::Error } } }
    };

    State currentState = State::Start;
    std::string commandWord, argument, value;
    
    SemanticAnalysis semanticAnalyzer;
    CommandFactory commandFactory;

    // Structure to hold command arguments
    std::unordered_map<std::string, std::vector<std::string>> commandArgs;

    // Read input from the stream
    std::string input;
    std::cout << "Enter your command: ";
    std::getline(inputStream, input);
    std::istringstream commandStream(input);

    while (true) {
        std::unique_ptr<SToken> token = tokenizer->tokenize(commandStream);
        if (!token) break; // No more tokens

        // Determine the next state based on the current state and token type
        auto nextStateIt = stateMachine.at(currentState).find(token->_type);
        if (nextStateIt == stateMachine.at(currentState).end()) {
            // Transition to the error state if no valid transition is found
            currentState = State::Error;
        } else {
            // Move to the next state
            currentState = nextStateIt->second;
        }

        // Process tokens based on the current state
        switch (currentState) {
            case State::Start:
                commandWord = std::get<std::string>(token->_content);
                break;

            case State::Cmd:
                commandWord += std::get<std::string>(token->_content);
                if (!semanticAnalyzer.isValidCommand(commandWord)) {
                    throw std::runtime_error("Invalid command: " + commandWord);
                }
                break;

            case State::Arg:
                argument = std::get<std::string>(token->_content);
                if (!semanticAnalyzer.isValidArgument(commandWord, argument)) {
                    throw std::runtime_error("Invalid argument: " + argument);
                }
                commandArgs[argument] = {};  // Initialize vector for the argument
                break;

            case State::Value:
                value = std::get<std::string>(token->_content);
                if (!semanticAnalyzer.isValidValue(commandWord, argument, value)) {
                    throw std::runtime_error("Invalid value: " + value);
                }
                // Append the value to the argument's vector in the map
                commandArgs[argument].push_back(value);
                break;

            case State::Error:
                throw std::runtime_error("Parsing error: Invalid token encountered.");

            default:
                throw std::runtime_error("Unexpected state encountered.");
        }
    }

    // Create and return the command object after parsing is complete
    return commandFactory.createCommand(commandWord, commandArgs);
}




// std::unique_ptr<ICommand> Parser::parse(std::istringstream& inputStream) {
//     // Step 1: Tokenize the input
    

//     // Step 2: Syntax analysis
//     // syntaxAnalyzer->analyze(tokens);

//     // Step 3: (Placeholder for semantic analysis, to be added later)
//     // semanticAnalyzer->analyze(tokens);

//     enum class State { Start, Cmd, Arg, Value, Error } currentState = State::Start;

//     while (true) {
//         std::unique_ptr<SToken> token = tokenizer->tokenize(inputStream);
//         if (!token) break; // No more tokens

//         switch (currentState) {
//             case State::Start:
//                 if (token->_type == SToken::EType::Word) {
//                     currentState = State::Cmd;
//                 } else {
//                     currentState = State::Error;
//                     throw std::runtime_error("Expected a command word, but got something else.");
//                 }
//                 break;

//             case State::Cmd:
//                 if (token->_type == SToken::EType::Word) {
//                     currentState = State::Cmd; 
//                 } else if (token->_type == SToken::EType::Arg) {
//                     currentState = State::Arg;
//                 } else {
//                     currentState = State::Error;
//                     throw std::runtime_error("Expected a word or argument, but got something else.");
//                 }
//                 break;

//             case State::Arg:
//                 if (token->_type == SToken::EType::Arg) {
//                     currentState = State::Arg; 
//                 } else if (token->_type == SToken::EType::Value)  {
//                     currentState = State::Value;
//                 } else {
//                     throw std::runtime_error("Expected an argument or value, but got something else.");
//                 }
//                 break;

//             case State::Value:
//                 if (token->_type == SToken::EType::Value) {
//                     currentState = State::Start; // Go back to the start for the next command
//                 } else {
//                     throw std::runtime_error("Expected a value.");
//                 }
//                 break;

//             default:
//                 throw std::runtime_error("Unexpected state.");
//         }
//     }

//     // Step 4: After analysis, create a Command object (Placeholder)
//     std::unique_ptr<ICommand> command = std::make_unique<ICommand>(); // This will later create concrete command objects

//     return command; // Return the command object
// }

