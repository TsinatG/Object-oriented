#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <string>

class Coordinates {
private:
    int x, y; // Both positive (origin at top-left corner)

public:
    // Constructors
    Coordinates();
    Coordinates(int x, int y);
    
    // Getters and setters
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    
    // Methods
    double distance(const Coordinates& p) const;
    void translate(int dx, int dy);
    void scale(double factor, bool sign);
    std::string display() const;
};

#endif // COORDINATES_HPP 