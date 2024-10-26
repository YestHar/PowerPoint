#include "Slide.hpp"
#include <stdexcept>

void Slide::addItem(std::unique_ptr<Item> item) {
    items.push_back(std::move(item));
}

std::shared_ptr<Item> Slide::getItem(size_t index) {
        if (index < items.size()) {
            return std::shared_ptr<Item>(items[index].get()); 
        }
        return nullptr;
    }

size_t Slide::getItemCount() const {
    return items.size();
}

void Slide::removeItem(size_t index) {
    if (index < 0 || index >= items.size()) {
        throw std::out_of_range("Item index is out of range.");
    }
    items.erase(items.begin() + index);
}

void Slide::setBackgroundColor(const std::string& color) {
    backgroundColor = color;
}

std::string Slide::getBackgroundColor() const {
    return backgroundColor;
}
