#ifndef REMOVESLIDE_HPP
#define REMOVESLIDE_HPP

#include "ICommand.hpp"

#include "../../Editor/RemoveSlideAction.hpp"
#include <iostream>
#include <memory>
// #include <unordered_map>
// #include <memory>
// #include <vector>
// #include <string>
// #include <variant>
// #include "../../Application/Application.hpp"
// #include <unordered_map>
// #include <variant>
// #include "../../Application/Application.hpp"

// class ICommand {
// public:
//     virtual ~ICommand() = default; 
//     virtual void exe() = 0;  // Execute the command
//     virtual bool should_exit() const { return false; }
// };

class RemoveSlide : public ICommand {
public:
    RemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;

private:
    int position;
};

#endif // REMOVE_HPP
