#include "Slide.hpp"

// Add a new item to the slide
void Slide::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
}

// Get an item by index
std::shared_ptr<Item> Slide::getItem(size_t index) const {
    if (index < items.size()) {
        return std::shared_ptr<Item>(items[index].get(), [](Item*) {});
    } else {
        throw std::out_of_range("Index out of bounds");
    }
}

// Get the number of items on the slide
size_t Slide::getItemCount() const {
    return items.size();
}

// Remove an item by index
void Slide::removeItem(size_t index) {
    if (index < items.size()) {
        items.erase(items.begin() + index);
    } else {
        throw std::out_of_range("Index out of bounds");
    }
}

// Set the background color of the slide
void Slide::setBackgroundColor(const std::string& color) {
    backgroundColor = color;
}

// Get the background color of the slide
std::string Slide::getBackgroundColor() const {
    return backgroundColor;
}
