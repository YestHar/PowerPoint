#include "Parser.hpp"

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


std::unique_ptr<ICommand> Parser::parse(std::istringstream& inputStream) {
    enum class State { Start, Cmd, Arg, Value, Error } currentState = State::Start;
    std::string commandWord;  // To hold the command
    std::string argument;     // To hold the argument
    std::string value;        // To hold the value

    CommandFactory commandFactory; // Instantiate CommandFactory

    while (true) {
        std::unique_ptr<SToken> token = tokenizer->tokenize(inputStream);
        if (!token) break; // No more tokens

        switch (currentState) {
            case State::Start:
                if (token->_type == SToken::EType::Word) {
                    commandWord = token->_content; // Store the command word
                    if (!semanticAnalyzer.isValidCommand(commandWord)) {
                        throw std::runtime_error("Invalid command: " + commandWord);
                    }
                    currentState = State::Cmd;
                } else {
                    currentState = State::Error;
                    throw std::runtime_error("Expected a command word.");
                }
                break;

            case State::Cmd:
                if (token->_type == SToken::EType::Arg) {
                    argument = token->_content;
                    if (!semanticAnalyzer.isValidArgument(commandWord, argument)) {
                        throw std::runtime_error("Invalid argument for command: " + argument);
                    }
                    currentState = State::Arg;
                } else {
                    currentState = State::Error;
                    throw std::runtime_error("Expected an argument.");
                }
                break;

            case State::Arg:
                if (token->_type == SToken::EType::Value) {
                    value = token->_content; // Store the value
                    // Validate the value using the command's specific validation function
                    if (!semanticAnalyzer.isValidValue(commandWord, value)) {
                        throw std::runtime_error("Invalid value for " + argument + ": " + value);
                    }
                    currentState = State::Value;
                } else {
                    throw std::runtime_error("Expected a value.");
                }
                break;

            case State::Value:
                currentState = State::Start; // Reset for the next command
                break;

            default:
                throw std::runtime_error("Unexpected state.");
        }
    }

    // Create the command object using CommandFactory
    return commandFactory.createCommand(commandWord, argument, value);
}
