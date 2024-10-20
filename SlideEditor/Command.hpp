#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>

class ICommand {
public:
    virtual void exe() = 0;
};

#endif // COMMAND_HPP
