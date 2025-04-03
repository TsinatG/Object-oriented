#include "Shape.hpp"
#include <sstream>
#include <cmath>

// Define M_PI if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Constructor
Shape::Shape(const Coordinates& position, int sides) 
    : position(position), sides(sides) {}

// Getters
Coordinates Shape::getPosition() const {
    return position;
}

int Shape::getSides() const {
    return sides;
}

// Translate the shape by dx and dy
void Shape::translate(int dx, int dy) {
    position.translate(dx, dy);
}

// Display shape information
string Shape::display() const {
    stringstream ss;
    ss << "Position: " << position.display() << ", Sides: " << sides;
    return ss.str();
}

// Rectangle implementation
Rectangle::Rectangle(const Coordinates& position, int width, int length)
    : Shape(position, 4), width(width > 0 ? width : 0), length(length > 0 ? length : 0) {}

int Rectangle::getWidth() const { return width; }
int Rectangle::getLength() const { return length; }

double Rectangle::getArea() const {
    return width * length;
}

double Rectangle::getPerimeter() const {
    return 2 * (width + length);
}

void Rectangle::scale(double factor, bool sign) {
    if (factor <= 0) {
        // Handle invalid scale factor gracefully
        return;
    }
    
    if (sign) {
        // Multiply
        width = static_cast<int>(width * factor);
        length = static_cast<int>(length * factor);
    } else {
        // Divide
        width = static_cast<int>(width / factor);
        length = static_cast<int>(length / factor);
    }
}

string Rectangle::display() const {
    stringstream ss;
    ss << "Rectangle: " << Shape::display() 
       << ", Width: " << width << ", Length: " << length
       << ", Area: " << getArea() << ", Perimeter: " << getPerimeter();
    return ss.str();
}

// Square implementation
Square::Square(const Coordinates& position, int side)
    : Rectangle(position, side > 0 ? side : 0, side > 0 ? side : 0) {}

string Square::display() const {
    stringstream ss;
    ss << "Square: " << Shape::display() 
       << ", Side: " << width
       << ", Area: " << getArea() << ", Perimeter: " << getPerimeter();
    return ss.str();
}

// Triangle implementation
Triangle::Triangle(const Coordinates& v1, const Coordinates& v2, const Coordinates& v3)
    : Shape(v1, 3), v1(v1), v2(v2), v3(v3) {}

Coordinates Triangle::getV1() const { return v1; }
Coordinates Triangle::getV2() const { return v2; }
Coordinates Triangle::getV3() const { return v3; }

// Helper method to check if a triangle is valid (new method)
bool Triangle::isValidTriangle() const {
    // Calculate sides
    double side1 = v1.distance(v2);
    double side2 = v2.distance(v3);
    double side3 = v3.distance(v1);
    
    // Triangle inequality theorem
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return false;
    }
    
    // Check for collinear points (area ≈ 0)
    double area = abs((v1.getX() * (v2.getY() - v3.getY()) + 
                       v2.getX() * (v3.getY() - v1.getY()) + 
                       v3.getX() * (v1.getY() - v2.getY())) / 2.0);
    
    // If area is very small, consider points collinear
    const double EPSILON = 0.0001;
    if (area < EPSILON) {
        return false;
    }
    
    return true;
}

double Triangle::getArea() const {
    // First check if triangle is valid
    if (!isValidTriangle()) {
        return 0; // Return 0 for invalid triangles
    }
    
    // Using Heron's formula
    double a = v1.distance(v2);
    double b = v2.distance(v3);
    double c = v3.distance(v1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::getPerimeter() const {
    // First check if triangle is valid
    if (!isValidTriangle()) {
        return 0; // Return 0 for invalid triangles
    }
    
    return v1.distance(v2) + v2.distance(v3) + v3.distance(v1);
}

void Triangle::translate(int dx, int dy) {
    Shape::translate(dx, dy);
    v1.translate(dx, dy);
    v2.translate(dx, dy);
    v3.translate(dx, dy);
}

void Triangle::scale(double factor, bool sign) {
    if (factor <= 0) {
        // Handle invalid scale factor gracefully
        return;
    }
    
    // Scale all vertices relative to the first vertex
    Coordinates origin = v1;
    
    // Translate v2 and v3 relative to v1
    v2.translate(-origin.getX(), -origin.getY());
    v3.translate(-origin.getX(), -origin.getY());
    
    // Scale v2 and v3
    v2.scale(factor, sign);
    v3.scale(factor, sign);
    
    // Translate back
    v2.translate(origin.getX(), origin.getY());
    v3.translate(origin.getX(), origin.getY());
}

string Triangle::display() const {
    stringstream ss;
    ss << "Triangle: " << Shape::display();
    
    // Check if it's a valid triangle
    if (!isValidTriangle()) {
        ss << " [INVALID TRIANGLE]";
        return ss.str();
    }
    
    ss << ", V1: " << v1.display() << ", V2: " << v2.display() << ", V3: " << v3.display()
       << ", Area: " << getArea() << ", Perimeter: " << getPerimeter();
    return ss.str();
}

// Circle implementation
Circle::Circle(const Coordinates& center, int radius)
    : Shape(center, 0), radius(radius > 0 ? radius : 0) {}

int Circle::getRadius() const { return radius; }

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * radius;
}

void Circle::scale(double factor, bool sign) {
    if (factor <= 0) {
        // Handle invalid scale factor gracefully
        return;
    }
    
    if (sign) {
        // Multiply
        radius = static_cast<int>(radius * factor);
    } else {
        // Divide
        radius = static_cast<int>(radius / factor);
    }
}

string Circle::display() const {
    stringstream ss;
    ss << "Circle: " << "Center: " << position.display() 
       << ", Radius: " << radius
       << ", Area: " << getArea() << ", Perimeter: " << getPerimeter();
    return ss.str();
} 