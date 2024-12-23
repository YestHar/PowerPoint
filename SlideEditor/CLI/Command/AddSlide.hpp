#ifndef ADDSLIDE_HPP
#define ADDSLIDE_HPP

#include "ICommand.hpp"
#include "../../Editor/AddSlideAction.hpp"
#include <iostream>
#include <memory>

class AddSlide : public ICommand {
public:
    AddSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;

private:
    int position;
};

#endif // ADDSLIDE_HPP
