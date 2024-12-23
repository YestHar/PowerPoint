#ifndef UNDO_HPP
#define UNDO_HPP

#include "ICommand.hpp"


class Undo : public ICommand {
public:
    Undo() : application(&Application::get_instance()) {}

    void exe() override {
        application->get_editor()->undo();
    }

private:
    Application* application;
};

#endif // UNDO_HPP