#ifndef EDITOR_HPP
#define EDITOR_HPP

#include "../Document/SlideCollection.hpp"
#include <iostream>
#include <memory>

class Editor {
public:
    explicit Editor(SlideCollection& doc) : document(doc) {}

    void createSlide(int position);
    void addShapeToSlide(int slideIndex, std::unique_ptr<Item> shape);
    void removeSlide(int slideIndex);
    void removeShapeFromSlide(int slideIndex, int shapeIndex);
    void changeShapeColor(int slideIndex, int shapeIndex, const std::string& newColor);
    void changeShapeBorder(int slideIndex, int shapeIndex, int newThickness, const std::string& newBorderColor);
    void changeSlideBackgroundColor(int slideIndex, const std::string& color);
    void swapSlides(int index1, int index2);

private:
    SlideCollection& document;
};

#endif // EDITOR_HPP
