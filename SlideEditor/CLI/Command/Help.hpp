#ifndef HELP_HPP
#define HELP_HPP

#include "ICommand.hpp"
#include <iostream>
#include <memory>


class Help : public ICommand {
public:
    void exe() override;
};

#endif // HELP_HPP