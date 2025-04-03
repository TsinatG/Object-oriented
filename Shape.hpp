#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Coordinates.hpp"
#include <string>

class Shape {
protected:
    Coordinates position;
    int sides;

public:
    // Constructor
    Shape(const Coordinates& position, int sides);
    
    // Virtual destructor
    virtual ~Shape() = default;
    
    // Getters
    Coordinates getPosition() const;
    int getSides() const;
    
    // Virtual methods
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void translate(int dx, int dy);
    virtual void scale(double factor, bool sign) = 0;
    virtual std::string display() const;
};

class Rectangle : public Shape {
protected:
    int width;
    int length;

public:
    Rectangle(const Coordinates& position, int width, int length);
    
    // Getters
    int getWidth() const;
    int getLength() const;
    
    // Override methods
    double getArea() const override;
    double getPerimeter() const override;
    void scale(double factor, bool sign) override;
    std::string display() const override;
};

class Square : public Rectangle {
public:
    Square(const Coordinates& position, int side);
    
    // Override methods
    std::string display() const override;
};

class Triangle : public Shape {
private:
    Coordinates v1, v2, v3;
    
    // Helper method to check if a triangle is valid
    bool isValidTriangle() const;

public:
    Triangle(const Coordinates& v1, const Coordinates& v2, const Coordinates& v3);
    
    // Getters
    Coordinates getV1() const;
    Coordinates getV2() const;
    Coordinates getV3() const;
    
    // Override methods
    double getArea() const override;
    double getPerimeter() const override;
    void translate(int dx, int dy) override;
    void scale(double factor, bool sign) override;
    std::string display() const override;
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(const Coordinates& center, int radius);
    
    // Getter
    int getRadius() const;
    
    // Override methods
    double getArea() const override;
    double getPerimeter() const override;
    void scale(double factor, bool sign) override;
    std::string display() const override;
};

#endif // SHAPE_HPP 