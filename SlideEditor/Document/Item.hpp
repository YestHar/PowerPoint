#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <memory>

// Enum for Item Types
enum class EType {
    Square,
    Circle,
    Triangle
};

// Struct for Geometry
struct SGeom {
    double x1, y1; 
    double x2, y2; 
};

// Interface for Attributes
class IAttributes {
public:
    virtual ~IAttributes() = default;
    virtual std::string getColor() const = 0; 
    virtual int getLineThickness() const = 0; 
    virtual std::string getLineColor() const = 0; 
    virtual void setColor(const std::string& color) = 0;
    virtual void setLineThickness(int thickness) = 0; 
    virtual void setLineColor(const std::string& lineColor) = 0; 
};

// Base Item class
class Item {
public:
    virtual ~Item() = default;
    
    // Returns the shape type
    virtual EType getType() const = 0;

    // Returns geometry details
    virtual SGeom getGeometry() const = 0;

    // Returns attributes
    virtual std::shared_ptr<IAttributes> getAttributes() const = 0;
};

// Attributes class for shapes
class ShapeAttributes : public IAttributes {
private:
    std::string color;
    int lineThickness;
    std::string lineColor;

public:
    ShapeAttributes(const std::string& col, int thickness, const std::string& lineCol);
    
    std::string getColor() const override;
    int getLineThickness() const override;
    std::string getLineColor() const override;

    void setColor(const std::string& color) override;
    void setLineThickness(int thickness) override;
    void setLineColor(const std::string& lineColor) override;
};

// Square class derived from Item
class Square : public Item {
private:
    SGeom geometry;
    std::shared_ptr<IAttributes> attributes;

public:
    Square(double x1, double y1, double x2, double y2, const std::string& color, int thickness, const std::string& lineColor);
    
    EType getType() const override;
    SGeom getGeometry() const override;
    std::shared_ptr<IAttributes> getAttributes() const override;
};

// Circle class derived from Item
class Circle : public Item {
private:
    SGeom geometry;
    std::shared_ptr<IAttributes> attributes;

public:
    Circle(double x1, double y1, double radiusX, double radiusY, const std::string& color, int thickness, const std::string& lineColor);
    
    EType getType() const override;
    SGeom getGeometry() const override;
    std::shared_ptr<IAttributes> getAttributes() const override;
};

// Triangle class derived from Item
class Triangle : public Item {
private:
    SGeom geometry;
    std::shared_ptr<IAttributes> attributes;

public:
    Triangle(double x1, double y1, double x2, double y2, const std::string& color, int thickness, const std::string& lineColor);
    
    EType getType() const override;
    SGeom getGeometry() const override;
    std::shared_ptr<IAttributes> getAttributes() const override;
};

#endif // ITEM_HPP
