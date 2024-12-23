#include "Item.hpp"

int Geometry::get_x() const {
    return x;
}

int Geometry::get_y() const {
    return y;
}

int Geometry::get_width() const {
    return width;
}

int Geometry::get_height() const {
    return height;
}

// Setters
void Geometry::set_x(int new_x) {
    x = new_x;
}

void Geometry::set_y(int new_y) {
    y = new_y;
}

void Geometry::set_width(int new_width) {
    width = new_width;
}

void Geometry::set_height(int new_height) {
    height = new_height;
}