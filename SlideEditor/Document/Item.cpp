#include "Item.hpp"

// ShapeAttributes constructor
ShapeAttributes::ShapeAttributes(const std::string& col, int thickness, const std::string& lineCol)
    : color(col), lineThickness(thickness), lineColor(lineCol) {}

std::string ShapeAttributes::getColor() const {
    return color;
}

int ShapeAttributes::getLineThickness() const {
    return lineThickness;
}

std::string ShapeAttributes::getLineColor() const {
    return lineColor;
}

void ShapeAttributes::setColor(const std::string& newColor) {
    color = newColor;
}

void ShapeAttributes::setLineThickness(int newThickness) {
    lineThickness = newThickness;
}

void ShapeAttributes::setLineColor(const std::string& newLineColor) {
    lineColor = newLineColor;
}

// Square constructor
Square::Square(double x1, double y1, double x2, double y2, const std::string& color, int thickness, const std::string& lineColor)
    : geometry{x1, y1, x2, y2},
      attributes(std::make_shared<ShapeAttributes>(color, thickness, lineColor)) {}

EType Square::getType() const {
    return EType::Square;
}

SGeom Square::getGeometry() const {
    return geometry;
}

std::shared_ptr<IAttributes> Square::getAttributes() const {
    return attributes;
}

// Circle constructor
Circle::Circle(double x1, double y1, double radiusX, double radiusY, const std::string& color, int thickness, const std::string& lineColor)
    : geometry{x1, y1, radiusX, radiusY},
      attributes(std::make_shared<ShapeAttributes>(color, thickness, lineColor)) {}

EType Circle::getType() const {
    return EType::Circle;
}

SGeom Circle::getGeometry() const {
    return geometry;
}

std::shared_ptr<IAttributes> Circle::getAttributes() const {
    return attributes;
}

// Triangle constructor
Triangle::Triangle(double x1, double y1, double x2, double y2, const std::string& color, int thickness, const std::string& lineColor)
    : geometry{x1, y1, x2, y2},
      attributes(std::make_shared<ShapeAttributes>(color, thickness, lineColor)) {}

EType Triangle::getType() const {
    return EType::Triangle;
}

SGeom Triangle::getGeometry() const {
    return geometry;
}

std::shared_ptr<IAttributes> Triangle::getAttributes() const {
    return attributes;
}
