#ifndef EXIT_HPP
#define EXIT_HPP

#include "ICommand.hpp"


class Exit : public ICommand {
public:
    void exe() override;
    bool should_exit() const override;
};

#endif // EXIT_HPP