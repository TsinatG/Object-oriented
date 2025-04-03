#ifndef SHAPELIST_HPP
#define SHAPELIST_HPP

#include "Shape.hpp"
#include <vector>
#include <string>

class ShapeList {
private:
    std::vector<Shape*> listOfShapes;

public:
    // Constructor and destructor
    ShapeList();
    ~ShapeList();
    
    // Methods
    void addShape(Shape* s);
    bool removeShape(int pos);
    void translateShapes(int dx, int dy);
    void scale(double factor, bool sign);
    std::string display() const;
    
    // Getters
    int getSize() const;
    Shape* getShape(int pos) const;
};

#endif // SHAPELIST_HPP 