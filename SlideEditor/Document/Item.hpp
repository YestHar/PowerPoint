#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <utility>

// Define the EType enum for item types
enum class EType {
    Square,
    Circle,
    Triangle
};

struct Geometry {
    int x, y; // Coordinates
    int width, height; // Dimensions

    // Getters
    int get_x() const;
    int get_y() const;
    int get_width() const;
    int get_height() const;

    // Setters
    void set_x(int new_x);
    void set_y(int new_y);
    void set_width(int new_width);
    void set_height(int new_height);

    Geometry(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}
};

// Define the Attributes structure
struct Attributes {
    std::string color;
    int borderWidth;
    std::string borderColor;

    Attributes(std::string color = "white", int borderWidth = 1, std::string borderColor = "black")
        : color(std::move(color)), borderWidth(borderWidth), borderColor(std::move(borderColor)) {}
};

// Define the Item class
class Item {
public:
    Item(int x, int y, int w, int h, const Attributes& attributes, EType type)
        : geometry(x, y, w, h), attributes(attributes), _id(++s_id), type(type) {}

    Geometry get_geometry() const { return geometry; }
    const Attributes& get_attributes() const { return attributes; }
    Attributes& get_attributes() { return attributes; }

    // Getter and Setter for type
    EType get_type() const { return type; }
    void set_type(EType new_type) { type = new_type; }

    void set_geometry(const Geometry& geom) { geometry = geom; }
    void set_attributes(const Attributes& other) { attributes = other; }

    int get_id() const { return _id; }

private:
    inline static int s_id = 0;
    Geometry geometry;
    Attributes attributes;
    int _id;
    EType type; // Type of the item
};

#endif // ITEM_HPP
