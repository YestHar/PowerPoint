#include "Tokenizer.hpp"

bool isInvalid(const std::string& token) {
    for (char c : token) {
        if (!std::isalpha(c) && !std::isdigit(c) && c != '-') {
            return true; // Invalid token if it contains non-alphabetic, non-digit, or non-argument characters
        }
    }
    return false; // Token is valid
}

bool isNumber(const std::string& token) {
    for (char c : token) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

bool isDouble(const std::string& token) {
    bool hasDot = false;
    for (char c : token) {
        if (c == '.') {
            if (hasDot) return false;  // More than one dot
            hasDot = true;
        } else if (!std::isdigit(c)) {
            return false;
        }
    }
    return hasDot;
}

bool isArgument(const std::string& token) {
    std::string subtoken = token.substr(1);
    return !token.empty() && token[0] == '-' && isWord(subtoken);
}

bool isWord(const std::string& token) {
    for (char c : token) {
        if (!std::isalpha(c) && c != '_') {
            return false;  // Return false if any character is not alphabetic or underscore
        }
    }
    return true;  // All characters passed the check
}


bool isValue(const std::string& token) {
    // We consider values to be numbers (int or double)
    return isNumber(token) || isDouble(token) || isWord(token);
}

SToken Tokenizer::determineTokenType(const std::string& word) {
    if (isNumber(word)) {
        return SToken(SToken::EType::Value, std::stoi(word));
    } else if (isDouble(word)) {
        return SToken(SToken::EType::Value, std::stod(word));
    } else if (isArgument(word)) {
        std::string argument = word.substr(1);
        return SToken(SToken::EType::Arg, argument);
    } else if (isWord(word)) {
        return SToken(SToken::EType::Word, word);
    } else {
        return SToken(SToken::EType::EOL, ""); // Fallback to EOL for other cases
    }
}

std::unique_ptr<SToken> Tokenizer::tokenize(std::istream& inputStream) {
    std::string word;

    // Get the next word from the input stream
    if (inputStream >> word) {
        // Check for invalid tokens first
        if (isInvalid(word)) {
            throw std::runtime_error("Invalid token: " + word);
        }

        // Call the function to determine the token type and content
        SToken result = determineTokenType(word);
        
        // Return a unique token using the public members or accessors
        return std::make_unique<SToken>(result.getType(), result.getContent());
    }

    return nullptr; // Return nullptr if no more tokens
}