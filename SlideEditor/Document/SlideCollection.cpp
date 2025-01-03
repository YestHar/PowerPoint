#include "SlideCollection.hpp"
#include <stdexcept>

// Add a new slide at a specific position
void SlideCollection::addSlide(std::shared_ptr<Slide> slide, int position) {
    if (position < 0 || position > static_cast<int>(slides.size()) + 1) {
        throw std::out_of_range("Position is out of range");
    }
    if (slides.size() + 1 == position) {
        slides.push_back(slide);
        return;
    }
    slides.insert(slides.begin() + position, slide);
}

// Get the total number of slides
size_t SlideCollection::getCount() const {
    return slides.size();
}

// Get a specific slide by index
std::shared_ptr<Slide> SlideCollection::getSlide(size_t index) const {
    if (index >= slides.size()) {
        throw std::out_of_range("Index is out of range");
    }
    return std::shared_ptr<Slide>(slides[index].get(), [](Slide*) {});
}

// Get the count of slides (duplicate of getCount)
size_t SlideCollection::getCountOfSlides() const {
    return getCount();
}

// Remove a slide at a specific index
void SlideCollection::removeSlide(size_t index) {
    if (index >= slides.size()) {
        throw std::out_of_range("Index is out of range");
    }
    slides.erase(slides.begin() + index);
}

// Swap two slides
void SlideCollection::swapSlides(int index1, int index2) {
    if (index1 < 0 || index1 >= static_cast<int>(slides.size()) ||
        index2 < 0 || index2 >= static_cast<int>(slides.size())) {
        throw std::out_of_range("Index is out of range");
    }
    std::swap(slides[index1], slides[index2]);
}
