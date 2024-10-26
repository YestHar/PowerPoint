#include "SlideCollection.hpp"

void SlideCollection::addSlide(std::unique_ptr<Slide> slide, int position) {
    if(slide) {
        if (position < 0 || position > slides.size()) {
            throw std::out_of_range("Invalid position to add slide");
        }
        slides.insert(slides.begin() + position, std::move(slide));
    } 
}

size_t SlideCollection::getCount() const {
    return slides.size();
}

std::shared_ptr<Slide> SlideCollection::getSlide(size_t index) const {
    if (index < slides.size()) {
        return std::shared_ptr<Slide>(slides[index].get());
    }
    throw std::out_of_range("Slide index out of range");
}

size_t SlideCollection::getCountOfSlides() const {
    return slides.size();
}

void SlideCollection::removeSlide(size_t index)  {
    if (index < slides.size()) {
        slides.erase(slides.begin() + index);
    } else {
        throw std::out_of_range("Slide index out of range");
    }
}


void SlideCollection::swapSlides(int index1, int index2) {
    if (index1 < 0 || index2 < 0 || index1 >= slides.size() || index2 >= slides.size()) {
        std::cerr << "Invalid indices for swapping slides." << std::endl;
        return;
    }

    std::swap(slides[index1], slides[index2]);
}