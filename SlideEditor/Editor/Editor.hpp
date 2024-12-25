#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "IAction.hpp"
#include <stack>
#include <memory>

class Editor {
public:
    Editor(std::shared_ptr<SlideCollection> doc);
    
    // Handles a new action
    void progress(std::shared_ptr<IAction> action);

    std::shared_ptr<SlideCollection> getDocument();

    // Undo the last action
    void undo();

    // Redo the last undone action
    void redo();

private:
    std::shared_ptr<SlideCollection> document;
    std::stack<std::shared_ptr<IAction>> undoStack;
    std::stack<std::shared_ptr<IAction>> redoStack;
};


#endif // EDITOR_HPP

