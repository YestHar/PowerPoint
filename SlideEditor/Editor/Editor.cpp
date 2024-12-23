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



// #include "Editor.hpp"

// void Editor::createSlide(int position) {
//     auto slide = std::make_unique<Slide>("Slide " + std::to_string(document.getCountOfSlides() + 1));
    
//     if (position < 0 || position > document.getCountOfSlides()) {
//         std::cerr << "Invalid position. Slide not added." << std::endl;
//         return;
//     }

//     document.addSlide(std::move(slide), position);
// }


// void Editor::addShapeToSlide(int slideIndex, std::unique_ptr<Item> shape) {
//     if (std::shared_ptr<Slide> slide = document.getSlide(slideIndex)) {
//         slide->addItem(std::move(shape));
//     }
// }

// void Editor::changeSlideBackgroundColor(int slideIndex, const std::string& color) {
//     if (std::shared_ptr<Slide> slide = document.getSlide(slideIndex)) {
//         slide->setBackgroundColor(color);
//     } else {
//         throw std::out_of_range("Invalid slide index");
//     }
// }

// void Editor::removeSlide(int slideIndex) {
//     if (slideIndex < 0 || slideIndex >= document.getCount()) {
//         std::cerr << "Slide index out of range.\n";
//         return;
//     }
//     document.removeSlide(slideIndex);
// }

// void Editor::removeShapeFromSlide(int slideIndex, int shapeIndex) {
//     auto slide = document.getSlide(slideIndex);
//     if (slide) {
//         slide->removeItem(shapeIndex);
//     } else {
//         std::cerr << "Slide index out of range.\n";
//     }
// }

// void Editor::changeShapeColor(int slideIndex, int shapeIndex, const std::string& newColor) {
//     auto slide = document.getSlide(slideIndex);
//     if (slide) {
//         auto shape = slide->getItem(shapeIndex);
//         if (shape) {
//             shape->getAttributes()->setColor(newColor); 
//         } else {
//             std::cerr << "Shape index out of range.\n";
//         }
//     } else {
//         std::cerr << "Slide index out of range.\n";
//     }
// }

// void Editor::changeShapeBorder(int slideIndex, int shapeIndex, int newThickness, const std::string& newBorderColor) {
//     auto slide = document.getSlide(slideIndex);
//     if (slide) {
//         auto shape = slide->getItem(shapeIndex);
//         if (shape) {
//             shape->getAttributes()->setLineThickness(newThickness); 
//             shape->getAttributes()->setLineColor(newBorderColor); 
//         } else {
//             std::cerr << "Shape index out of range.\n";
//         }
//     } else {
//         std::cerr << "Slide index out of range.\n";
//     }
// }

// void Editor::swapSlides(int index1, int index2) {
//     if (index1 < 0 || index2 < 0 || index1 >= document.getCountOfSlides() || index2 >= document.getCountOfSlides()) {
//         std::cerr << "Invalid indices for swapping slides." << std::endl;
//         return;
//     }

//     document.swapSlides(index1, index2); 
//     std::cout << "Swapped slides at indices: " << index1 << " and " << index2 << "." << std::endl;
// }