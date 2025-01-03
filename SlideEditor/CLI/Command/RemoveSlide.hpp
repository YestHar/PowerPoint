#ifndef REMOVESLIDE_HPP
#define REMOVESLIDE_HPP

#include "ICommand.hpp"

class RemoveSlide : public ICommand {
public:
    RemoveSlide(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;

private:
    int position;
};


#endif // REMOVE_HPP
