#include <iostream>
#include "Coordinates.hpp"
#include "Shape.hpp"

int main() {
    std::cout << "Testing class declarations..." << std::endl;
    
    // Test Coordinates class
    Coordinates c(10, 20);
    std::cout << "Coordinates: " << c.getX() << ", " << c.getY() << std::endl;
    
    // Test Rectangle class
    std::cout << "Creating Rectangle..." << std::endl;
    Coordinates pos(5, 5);
    Rectangle r(pos, 10, 20);
    std::cout << "Rectangle width: " << r.getWidth() << std::endl;
    
    std::cout << "Diagnostic completed successfully!" << std::endl;
    
    return 0;
} 