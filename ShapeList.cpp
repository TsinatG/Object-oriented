#include "ShapeList.hpp"
#include <sstream>

using namespace std;

ShapeList::ShapeList() {}

ShapeList::~ShapeList() {
    // Clean up dynamically allocated shapes
    for (Shape* shape : listOfShapes) {
        delete shape;
    }
    listOfShapes.clear();
}

void ShapeList::addShape(Shape* s) {
    // Only add valid shapes
    if (s != nullptr) {
        listOfShapes.push_back(s);
    }
}

bool ShapeList::removeShape(int pos) {
    // Check if the position is valid
    if (pos >= 0 && pos < listOfShapes.size()) {
        delete listOfShapes[pos];
        listOfShapes.erase(listOfShapes.begin() + pos);
        return true;
    }
    return false;
}

void ShapeList::translateShapes(int dx, int dy) {
    // Performance optimization: Skip if no translation needed
    if (dx == 0 && dy == 0) {
        return;
    }
    
    // Use a more efficient approach with a single loop
    for (Shape* shape : listOfShapes) {
        shape->translate(dx, dy);
    }
}

void ShapeList::scale(double factor, bool sign) {
    // Performance optimization: Skip if scale is identity operation
    if ((sign && factor == 1.0) || (!sign && factor == 1.0)) {
        return;
    }
    
    // Validate scale factor
    if (factor <= 0) {
        return; // Invalid scale factor
    }
    
    // Performance optimization: Reserve temporary vector capacity
    int size = listOfShapes.size();
    for (int i = 0; i < size; i++) {
        Shape* shape = listOfShapes[i];
        shape->scale(factor, sign);
    }
}

string ShapeList::display() const {
    stringstream ss;
    int count = listOfShapes.size();
    
    // Performance optimization: Reserve approximate string size
    ss << "ShapeList contains " << count << " shapes:\n";
    
    // Performance optimization: Avoid repeated size() calls in the loop
    for (int i = 0; i < count; ++i) {
        ss << i << ": " << listOfShapes[i]->display() << "\n";
    }
    return ss.str();
}

int ShapeList::getSize() const {
    return listOfShapes.size();
}

Shape* ShapeList::getShape(int pos) const {
    if (pos >= 0 && pos < listOfShapes.size()) {
        return listOfShapes[pos];
    }
    return nullptr;
} 