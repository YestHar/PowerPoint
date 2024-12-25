#include "Editor.hpp"
#include <stdexcept>

Editor::Editor(std::shared_ptr<SlideCollection> doc) : document(std::move(doc)) {}

void Editor::progress(std::shared_ptr<IAction> action) {
    auto inverseAction = action->do_action(document);
    undoStack.push(inverseAction);
    while (!redoStack.empty()) {
        redoStack.pop();
    }
}

void Editor::undo() {
    if (undoStack.empty()) {
        throw std::runtime_error("Undo stack is empty!");
    }
    auto action = undoStack.top();
    undoStack.pop();
    auto inverseAction = action->do_action(document);

    redoStack.push(inverseAction);
}

void Editor::redo() {
    if (redoStack.empty()) {
        throw std::runtime_error("Redo stack is empty!");
    }
    auto action = redoStack.top();
    redoStack.pop();
    auto inverseAction = action->do_action(document);
    undoStack.push(inverseAction);
}

std::shared_ptr<SlideCollection> Editor::getDocument() {
    return document;
}


