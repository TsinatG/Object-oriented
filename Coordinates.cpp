#include "Coordinates.hpp"
#include <cmath>
#include <sstream>

using namespace std;

// Constructors
Coordinates::Coordinates() : x(0), y(0) {}
Coordinates::Coordinates(int x, int y) : x(x), y(y) {}

// Getters and setters
int Coordinates::getX() const { return x; }
int Coordinates::getY() const { return y; }
void Coordinates::setX(int x) { this->x = x; }
void Coordinates::setY(int y) { this->y = y; }

// Calculate Euclidean distance between two points
double Coordinates::distance(const Coordinates& p) const {
    int dx = x - p.x;
    int dy = y - p.y;
    return sqrt(dx*dx + dy*dy);
}

// Translate coordinates by dx and dy
void Coordinates::translate(int dx, int dy) {
    x += dx;
    y += dy;
}

// Scale coordinates by factor (multiply if sign is true, divide if false)
void Coordinates::scale(double factor, bool sign) {
    if (sign) {
        // Multiply
        x = static_cast<int>(x * factor);
        y = static_cast<int>(y * factor);
    } else {
        // Divide
        x = static_cast<int>(x / factor);
        y = static_cast<int>(y / factor);
    }
}

// Display coordinates as a string
string Coordinates::display() const {
    stringstream ss;
    ss << "X = " << x << ", Y = " << y;
    return ss.str();
} 