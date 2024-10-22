#ifndef   TOKENIZER_HPP
#define   TOKENIZER_HPP

#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <exception>
#include <variant>


// SToken structure to hold the token type and content
struct SToken {
    enum class EType {
        Word,
        Arg,
        Value,
        Invalid,
        EOL // End of line, if needed for processing
    } _type;

    std::variant<std::string, int, double> _content;

    // Constructor
    SToken(EType type, std::variant<std::string, int, double> content)
        : _type(type), _content(content) {}

    // Copy constructor
    SToken(const SToken& other)
        : _type(other._type), _content(other._content) {}

    // Move constructor
    SToken(SToken&& other) noexcept
        : _type(other._type), _content(std::move(other._content)) {}

    // Move assignment operator
    SToken& operator=(SToken&& other) noexcept {
        if (this != &other) {
            _type = other._type;
            _content = std::move(other._content);
        }
        return *this;
    }
    
    // Deleted copy constructor to prevent accidental copying
    SToken(const SToken& other) = delete;
    SToken& operator=(const SToken& other) = delete;

    EType getType() const { return _type; }
    std::variant<std::string, int, double> getContent() const { return _content; }

};

class Tokenizer {
public:
    
    // Function to tokenize the input stream
    std::unique_ptr<SToken> tokenize(std::istream& inputStream);  

    SToken determineTokenType(const std::string& word);   

};


#endif //TOKENIZER_HPP