#ifndef UNDOREDO_HPP
#define UNDOREDO_HPP

#include "ICommand.hpp"

class Undo : public ICommand {
public:
    Undo() {};

    void exe() override;

};

class Redo : public ICommand {
public:
    Redo(){};

    void exe() override ;
};

#endif // UNDOREDO_HPP