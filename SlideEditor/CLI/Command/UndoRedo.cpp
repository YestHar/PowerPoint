#include "UndoRedo.hpp"
#include "../../Application/Application.hpp"

void Redo::exe() {
    Application::get_instance().get_editor()->redo();
}

void Undo::exe() {
    Application::get_instance().get_editor()->undo();
}
