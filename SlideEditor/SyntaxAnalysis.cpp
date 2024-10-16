#include "SyntaxAnalysis.hpp"


// std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>> SyntaxAnalysis::analyze(std::istream& inputStream) {
//     enum class State { Start, Cmd, Arg, Value, Error } currentState = State::Start;
//     std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>> commandMap;
//     std::string currentCmd;

//     while (true) {
//         std::unique_ptr<SToken> token = tokenizer->tokenize(inputStream);
//         if (!token) break; // No more tokens

//         switch (currentState) {
//             case State::Start:
//                 if (token->_type == SToken::EType::Word) {
//                     currentCmd = std::get<std::string>(token->_content);
                    
//                     // Check if the command already exists, otherwise create a new entry
//                     if (commandMap.find(currentCmd) == commandMap.end()) {
//                         commandMap[currentCmd] = {}; // Initialize an empty vector for the command
//                     }
//                     currentState = State::Cmd;
//                 } else {
//                     currentState = State::Error;
//                     throw std::runtime_error("Expected a command word, but got something else.");
//                 }
//                 break;

//             case State::Cmd:
//                 if (token->_type == SToken::EType::Word) {
//                     // Handle another word for the command, possibly concatenate or store the previous one
//                     currentCmd += std::get<std::string>(token->_content); 
//                     currentState = State::Cmd; 
//                 } else if (token->_type == SToken::EType::Arg) {
//                     currentState = State::Arg;
//                 } else {
//                     currentState = State::Error;
//                     throw std::runtime_error("Expected a word or argument, but got something else.");
//                 }
//                 break;

//             case State::Arg:
//                 if (token->_type == SToken::EType::Arg || token->_type == SToken::EType::Value) {
//                     // Move the token into the command map
//                     commandMap[currentCmd].emplace_back(std::move(token));
//                     currentState = (token->_type == SToken::EType::Arg) ? State::Arg : State::Value; 
//                 } else {
//                     throw std::runtime_error("Expected an argument or value, but got something else.");
//                 }
//                 break;

//             case State::Value:
//                 if (token->_type == SToken::EType::Value) {
//                     // Move the value to the command map
//                     commandMap[currentCmd].emplace_back(std::move(token));
//                     currentCmd.clear(); // Reset the command after processing the value
//                     currentState = State::Start; // Go back to the start for the next command
//                 } else {
//                     throw std::runtime_error("Expected a value.");
//                 }
//                 break;

//             default:
//                 throw std::runtime_error("Unexpected state.");
//         }
//     }

//     return commandMap; // Return the filled map with commands and their associated tokens
// }



// void SyntaxAnalysis::printCommandMap(const std::unordered_map<std::string, std::vector<std::unique_ptr<SToken>>>& commandMap) {
//     for (const auto& pair : commandMap) {
//         std::cout << "Command: " << pair.first << std::endl;

//         // Iterate over the vector of unique_ptr<SToken>
//         for (const auto& token : pair.second) {
//             std::cout << "  Token Type: ";
//             switch (token->_type) {
//                 case SToken::EType::Word: 
//                     std::cout << "Word"; 
//                     break;
//                 case SToken::EType::Arg: 
//                     std::cout << "Argument"; 
//                     break;
//                 case SToken::EType::Value: 
//                     std::cout << "Value"; 
//                     break;
//                 case SToken::EType::EOL: 
//                     std::cout << "End of Line"; 
//                     break;
//             }

//             // Check the variant type and print the token content
//             std::cout << " - Value: ";
//             if (std::holds_alternative<std::string>(token->_content)) {
//                 std::cout << std::get<std::string>(token->_content);
//             } else if (std::holds_alternative<int>(token->_content)) {
//                 std::cout << std::get<int>(token->_content);
//             } else if (std::holds_alternative<double>(token->_content)) {
//                 std::cout << std::get<double>(token->_content);
//             }

//             std::cout << std::endl;
//         }
//     }
// }
