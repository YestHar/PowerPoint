#ifndef SAVECOMMAND_HPP
#define SAVECOMMAND_HPP

#include "ICommand.hpp"
#include <string>
#include <memory>



class SaveCommand : public ICommand {
public:
    SaveCommand(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);
    void exe() override;

private:
    std::string filename;
};

#endif // SAVECOMMAND_HPP
