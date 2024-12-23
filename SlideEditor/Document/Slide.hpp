#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Item.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Slide {
public:
    // Add a new item to the slide
    void addItem(std::unique_ptr<Item> item);

    // Get an item by index
    std::shared_ptr<Item> getItem(size_t index) const;

    // Get the number of items on the slide
    size_t getItemCount() const;

    // Remove an item by index
    void removeItem(size_t index);

    // Set the background color of the slide
    void setBackgroundColor(const std::string& color);

    // Get the background color of the slide
    std::string getBackgroundColor() const;

private:
    std::vector<std::unique_ptr<Item>> items; // Items on the slide
    std::string backgroundColor = "white";   // Default background color
};

#endif // SLIDE_HPP
