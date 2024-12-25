#ifndef LOADCOMMAND_HPP
#define LOADCOMMAND_HPP

#include "ICommand.hpp"
#include <string>
#include <memory>

class LoadCommand : public ICommand {
public:
    LoadCommand(const std::unordered_map<std::string, std::vector<std::variant<std::string, int, double>>>& args);


    void exe() override;

private:
    std::string filename;
};

#endif // LOADCOMMAND_HPP
