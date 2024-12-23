#ifndef EXIT_HPP
#define EXIT_HPP

#include "ICommand.hpp"
#include <iostream>
#include <memory>


class Exit : public ICommand {
public:
    void exe() override;
};

#endif // EXIT_HPP