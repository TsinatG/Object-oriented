#include "ShapeList.hpp"
#include <iostream>
#include <limits>

using namespace std;

class ShapeManagement {
private:
    ShapeList shapeList;

    void printMenu() {
        cout << "\n===== Shape Management System =====\n";
        cout << "1. Add Shape\n";
        cout << "2. Remove Shape by position\n";
        cout << "3. Get information about a shape by position\n";
        cout << "4. Area and perimeter of a shape by position\n";
        cout << "5. Display information of all shapes\n";
        cout << "6. Translate all shapes\n";
        cout << "7. Scale all shapes\n";
        cout << "8. Run Unit Tests\n";
        cout << "0. Quit program\n";
        cout << "Enter your choice: ";
    }

    void addShape() {
        cout << "\n--- Add Shape ---\n";
        cout << "1. Rectangle\n";
        cout << "2. Square\n";
        cout << "3. Triangle\n";
        cout << "4. Circle\n";
        cout << "Enter shape type: ";
        
        int type;
        cin >> type;
        
        switch (type) {
            case 1: addRectangle(); break;
            case 2: addSquare(); break;
            case 3: addTriangle(); break;
            case 4: addCircle(); break;
            default: cout << "Invalid shape type.\n";
        }
    }
    
    void addRectangle() {
        int x, y, width, length;
        cout << "Enter position (x y): ";
        cin >> x >> y;
        
        // Validate coordinates
        if (x < 0 || y < 0) {
            cout << "Error: Coordinates must be non-negative (origin is at top-left corner).\n";
            return;
        }
        
        cout << "Enter width: ";
        cin >> width;
        
        // Validate width
        if (width <= 0) {
            cout << "Error: Width must be a positive number.\n";
            return;
        }
        
        cout << "Enter length: ";
        cin >> length;
        
        // Validate length
        if (length <= 0) {
            cout << "Error: Length must be a positive number.\n";
            return;
        }
        
        Coordinates pos(x, y);
        shapeList.addShape(new Rectangle(pos, width, length));
        cout << "Rectangle added successfully.\n";
    }
    
    void addSquare() {
        int x, y, side;
        cout << "Enter position (x y): ";
        cin >> x >> y;
        
        // Validate coordinates
        if (x < 0 || y < 0) {
            cout << "Error: Coordinates must be non-negative (origin is at top-left corner).\n";
            return;
        }
        
        cout << "Enter side length: ";
        cin >> side;
        
        // Validate side length
        if (side <= 0) {
            cout << "Error: Side length must be a positive number.\n";
            return;
        }
        
        Coordinates pos(x, y);
        shapeList.addShape(new Square(pos, side));
        cout << "Square added successfully.\n";
    }
    
    void addTriangle() {
        int x1, y1, x2, y2, x3, y3;
        cout << "Enter first vertex (x y): ";
        cin >> x1 >> y1;
        
        // Validate first vertex
        if (x1 < 0 || y1 < 0) {
            cout << "Error: Coordinates must be non-negative (origin is at top-left corner).\n";
            return;
        }
        
        cout << "Enter second vertex (x y): ";
        cin >> x2 >> y2;
        
        // Validate second vertex
        if (x2 < 0 || y2 < 0) {
            cout << "Error: Coordinates must be non-negative (origin is at top-left corner).\n";
            return;
        }
        
        cout << "Enter third vertex (x y): ";
        cin >> x3 >> y3;
        
        // Validate third vertex
        if (x3 < 0 || y3 < 0) {
            cout << "Error: Coordinates must be non-negative (origin is at top-left corner).\n";
            return;
        }
        
        // Check if the points form a valid triangle
        Coordinates v1(x1, y1), v2(x2, y2), v3(x3, y3);
        
        // Calculate distances between vertices
        double a = v1.distance(v2);
        double b = v2.distance(v3);
        double c = v3.distance(v1);
        
        // Check triangle inequality theorem
        if (a + b <= c || a + c <= b || b + c <= a) {
            cout << "Error: The vertices do not form a valid triangle. Triangle inequality theorem violated.\n";
            return;
        }
        
        // Check if points are collinear (area would be 0)
        double area = abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0);
        if (area == 0) {
            cout << "Error: The vertices are collinear and do not form a valid triangle.\n";
            return;
        }
        
        shapeList.addShape(new Triangle(v1, v2, v3));
        cout << "Triangle added successfully.\n";
    }
    
    void addCircle() {
        int x, y, radius;
        cout << "Enter center position (x y): ";
        cin >> x >> y;
        
        // Validate coordinates
        if (x < 0 || y < 0) {
            cout << "Error: Coordinates must be non-negative (origin is at top-left corner).\n";
            return;
        }
        
        cout << "Enter radius: ";
        cin >> radius;
        
        // Validate radius
        if (radius <= 0) {
            cout << "Error: Radius must be a positive number.\n";
            return;
        }
        
        Coordinates center(x, y);
        shapeList.addShape(new Circle(center, radius));
        cout << "Circle added successfully.\n";
    }
    
    void removeShape() {
        if (shapeList.getSize() == 0) {
            cout << "No shapes to remove.\n";
            return;
        }
        
        cout << "\n--- Remove Shape by Position ---\n";
        cout << shapeList.display();
        cout << "Enter the index of the shape to remove: ";
        
        int index;
        cin >> index;
        
        if (index < 0) {
            cout << "Error: Index cannot be negative.\n";
            return;
        }
        
        if (shapeList.removeShape(index)) {
            cout << "Shape removed successfully.\n";
        } else {
            cout << "Error: Invalid index. The index is out of bounds.\n";
        }
    }
    
    void displayShapeInfo() {
        if (shapeList.getSize() == 0) {
            cout << "No shapes available.\n";
            return;
        }
        
        cout << "\n--- Shape Information ---\n";
        cout << shapeList.display();
        cout << "Enter the index of the shape: ";
        
        int index;
        cin >> index;
        
        if (index < 0) {
            cout << "Error: Index cannot be negative.\n";
            return;
        }
        
        Shape* shape = shapeList.getShape(index);
        if (shape) {
            cout << shape->display() << endl;
        } else {
            cout << "Error: Invalid index. The index is out of bounds.\n";
        }
    }
    
    void displayShapeAreaPerimeter() {
        if (shapeList.getSize() == 0) {
            cout << "No shapes available.\n";
            return;
        }
        
        cout << "\n--- Shape Area and Perimeter ---\n";
        cout << shapeList.display();
        cout << "Enter the index of the shape: ";
        
        int index;
        cin >> index;
        
        if (index < 0) {
            cout << "Error: Index cannot be negative.\n";
            return;
        }
        
        Shape* shape = shapeList.getShape(index);
        if (shape) {
            cout << "Area: " << shape->getArea() << endl;
            cout << "Perimeter: " << shape->getPerimeter() << endl;
        } else {
            cout << "Error: Invalid index. The index is out of bounds.\n";
        }
    }
    
    void translateShapes() {
        if (shapeList.getSize() == 0) {
            cout << "No shapes to translate.\n";
            return;
        }
        
        cout << "\n--- Translate Shapes ---\n";
        cout << "Enter translation values (dx dy): ";
        
        int dx, dy;
        cin >> dx >> dy;
        
        // Check if translation would result in negative coordinates
        bool invalid = false;
        for (int i = 0; i < shapeList.getSize(); i++) {
            Shape* shape = shapeList.getShape(i);
            if (shape) {
                Coordinates pos = shape->getPosition();
                if (pos.getX() + dx < 0 || pos.getY() + dy < 0) {
                    invalid = true;
                    break;
                }
            }
        }
        
        if (invalid) {
            cout << "Error: Translation would result in negative coordinates for some shapes.\n";
            return;
        }
        
        shapeList.translateShapes(dx, dy);
        cout << "Shapes translated successfully.\n";
    }
    
    void scaleShapes() {
        if (shapeList.getSize() == 0) {
            cout << "No shapes to scale.\n";
            return;
        }
        
        cout << "\n--- Scale Shapes ---\n";
        cout << "Enter scale factor: ";
        
        double factor;
        cin >> factor;
        
        // Validate scale factor
        if (factor <= 0) {
            cout << "Error: Scale factor must be a positive number.\n";
            return;
        }
        
        cout << "Multiply (1) or Divide (0)? ";
        int choice;
        cin >> choice;
        
        if (choice != 0 && choice != 1) {
            cout << "Error: Invalid choice. Must be 0 or 1.\n";
            return;
        }
        
        bool sign = (choice == 1);
        shapeList.scale(factor, sign);
        cout << "Shapes scaled successfully.\n";
    }
    
    void displayShapes() {
        if (shapeList.getSize() == 0) {
            cout << "No shapes to display.\n";
            return;
        }
        
        cout << "\n--- All Shapes ---\n";
        cout << shapeList.display();
    }
    
    void runUnitTests() {
        cout << "\n--- Unit Tests are in a separate executable ---\n";
        cout << "Please run the tests executable to see unit test results.\n";
    }

public:
    void run() {
        while (true) {
            printMenu();
            
            int choice;
            
            // Validate menu choice input
            if (!(cin >> choice)) {
                cout << "Error: Invalid input. Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            // Clear input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            switch (choice) {
                case 1: addShape(); break;
                case 2: removeShape(); break;
                case 3: displayShapeInfo(); break;
                case 4: displayShapeAreaPerimeter(); break;
                case 5: displayShapes(); break;
                case 6: translateShapes(); break;
                case 7: scaleShapes(); break;
                case 8: runUnitTests(); break;
                case 0: 
                    cout << "Exiting program.\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    ShapeManagement app;
    app.run();
    return 0;
} 