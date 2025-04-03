#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Coordinates.hpp"
#include "Shape.hpp"
#include "ShapeList.hpp"
#include <cmath>

// Define M_PI if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// This file focuses specifically on verifying the mathematical correctness
// of our geometric calculations for the test plan

TEST_CASE("Test Triangle from test plan - coordinates (50,50), (20,70), (70,70)", "[test_plan]") {
    Coordinates v1(50, 50), v2(20, 70), v3(70, 70);
    Triangle t(v1, v2, v3);
    
    // For this triangle, we can calculate manually:
    // Base = 50 units (distance from (20,70) to (70,70))
    // Height = 20 units (perpendicular height from (50,50) to base)
    // Area = 1/2 * base * height = 1/2 * 50 * 20 = 500 square units
    
    REQUIRE(t.getArea() == Approx(500.0));
    
    // Sides:
    // a = distance((50,50), (20,70)) = sqrt(30^2 + 20^2) = sqrt(1300) ≈ 36.06
    // b = distance((20,70), (70,70)) = 50
    // c = distance((70,70), (50,50)) = sqrt(20^2 + 20^2) = sqrt(800) ≈ 28.28
    // Perimeter = a + b + c ≈ 114.34
    
    double side1 = v1.distance(v2); // ≈ 36.06
    double side2 = v2.distance(v3); // = 50
    double side3 = v3.distance(v1); // ≈ 28.28
    
    REQUIRE(side1 == Approx(sqrt(1300)));
    REQUIRE(side2 == Approx(50.0));
    REQUIRE(side3 == Approx(sqrt(800)));
    REQUIRE(t.getPerimeter() == Approx(side1 + side2 + side3));
}

TEST_CASE("Test Rectangle from test plan - position (100,20), width 10, length 15", "[test_plan]") {
    Coordinates pos(100, 20);
    Rectangle r(pos, 10, 15);
    
    REQUIRE(r.getArea() == 10 * 15);
    REQUIRE(r.getPerimeter() == 2 * (10 + 15));
}

TEST_CASE("Test Circle from test plan - center (80,100), radius 25", "[test_plan]") {
    Coordinates center(80, 100);
    Circle c(center, 25);
    
    REQUIRE(c.getArea() == Approx(M_PI * 25 * 25));
    REQUIRE(c.getPerimeter() == Approx(2 * M_PI * 25));
}

TEST_CASE("Test Square from test plan - position (90,40), side 20", "[test_plan]") {
    Coordinates pos(90, 40);
    Square s(pos, 20);
    
    REQUIRE(s.getArea() == 20 * 20);
    REQUIRE(s.getPerimeter() == 4 * 20);
}

TEST_CASE("Translation of shapes", "[test_plan]") {
    Coordinates pos(10, 10);
    Rectangle r(pos, 30, 40);
    
    // Before translation
    REQUIRE(r.getPosition().getX() == 10);
    REQUIRE(r.getPosition().getY() == 10);
    
    // Apply translation
    r.translate(10, 15);
    
    // After translation
    REQUIRE(r.getPosition().getX() == 20);
    REQUIRE(r.getPosition().getY() == 25);
}

TEST_CASE("Scaling of shapes", "[test_plan]") {
    Coordinates pos(10, 10);
    Rectangle r(pos, 30, 40);
    
    // Before scaling
    REQUIRE(r.getArea() == 30 * 40);
    REQUIRE(r.getPerimeter() == 2 * (30 + 40));
    
    // Apply scaling (multiply by 2)
    r.scale(2, true);
    
    // After scaling
    REQUIRE(r.getWidth() == 60);
    REQUIRE(r.getLength() == 80);
    REQUIRE(r.getArea() == 60 * 80);
    REQUIRE(r.getPerimeter() == 2 * (60 + 80));
}

TEST_CASE("Triangle from test plan additional calculations", "[test_plan]") {
    Coordinates v1(0, 0), v2(30, 0), v3(15, 20);
    Triangle t(v1, v2, v3);
    
    // Calculate area manually:
    // Base = 30 units
    // Height = 20 units
    // Area = 1/2 * base * height = 1/2 * 30 * 20 = 300 square units
    
    REQUIRE(t.getArea() == Approx(300.0));
}

// New test cases for error handling

TEST_CASE("Handling invalid dimensions in shape creation", "[error_handling]") {
    SECTION("Rectangle with zero or negative dimensions") {
        // Zero width
        Rectangle r1(Coordinates(10, 10), 0, 5);
        REQUIRE(r1.getArea() == 0);
        REQUIRE(r1.getWidth() == 0);
        
        // Negative width
        Rectangle r2(Coordinates(10, 10), -5, 5);
        REQUIRE(r2.getArea() == 0);
        REQUIRE(r2.getWidth() == 0);
        
        // Zero length
        Rectangle r3(Coordinates(10, 10), 5, 0);
        REQUIRE(r3.getArea() == 0);
        REQUIRE(r3.getLength() == 0);
        
        // Negative length
        Rectangle r4(Coordinates(10, 10), 5, -5);
        REQUIRE(r4.getArea() == 0);
        REQUIRE(r4.getLength() == 0);
    }
    
    SECTION("Square with zero or negative side") {
        // Zero side
        Square s1(Coordinates(10, 10), 0);
        REQUIRE(s1.getArea() == 0);
        REQUIRE(s1.getWidth() == 0);
        REQUIRE(s1.getLength() == 0);
        
        // Negative side
        Square s2(Coordinates(10, 10), -5);
        REQUIRE(s2.getArea() == 0);
        REQUIRE(s2.getWidth() == 0);
        REQUIRE(s2.getLength() == 0);
    }
    
    SECTION("Circle with zero or negative radius") {
        // Zero radius
        Circle c1(Coordinates(10, 10), 0);
        REQUIRE(c1.getArea() == 0);
        REQUIRE(c1.getRadius() == 0);
        
        // Negative radius
        Circle c2(Coordinates(10, 10), -5);
        REQUIRE(c2.getArea() == 0);
        REQUIRE(c2.getRadius() == 0);
    }
}

TEST_CASE("Triangle validation tests", "[error_handling]") {
    SECTION("Collinear points") {
        // Points on a straight line
        Triangle t1(Coordinates(0, 0), Coordinates(5, 5), Coordinates(10, 10));
        REQUIRE(t1.getArea() == 0);
        REQUIRE(t1.getPerimeter() == 0);
        
        // Another collinear case
        Triangle t2(Coordinates(0, 0), Coordinates(10, 0), Coordinates(5, 0));
        REQUIRE(t2.getArea() == 0);
        REQUIRE(t2.getPerimeter() == 0);
    }
    
    SECTION("Triangle inequality theorem violations") {
        // Sum of two sides equals the third side
        Triangle t1(Coordinates(0, 0), Coordinates(0, 5), Coordinates(0, 10));
        REQUIRE(t1.getArea() == 0);
        REQUIRE(t1.getPerimeter() == 0);
        
        // Sum of two sides less than the third side
        Triangle t2(Coordinates(0, 0), Coordinates(1, 0), Coordinates(10, 0));
        REQUIRE(t2.getArea() == 0);
        REQUIRE(t2.getPerimeter() == 0);
    }
}

TEST_CASE("Scaling with invalid factors", "[error_handling]") {
    SECTION("Rectangle scaling with invalid factor") {
        Rectangle r(Coordinates(10, 10), 5, 10);
        int initialWidth = r.getWidth();
        int initialLength = r.getLength();
        
        // Try scaling with zero
        r.scale(0, true);
        REQUIRE(r.getWidth() == initialWidth);
        REQUIRE(r.getLength() == initialLength);
        
        // Try scaling with negative factor
        r.scale(-2, true);
        REQUIRE(r.getWidth() == initialWidth);
        REQUIRE(r.getLength() == initialLength);
    }
    
    SECTION("Circle scaling with invalid factor") {
        Circle c(Coordinates(10, 10), 5);
        int initialRadius = c.getRadius();
        
        // Try scaling with zero
        c.scale(0, true);
        REQUIRE(c.getRadius() == initialRadius);
        
        // Try scaling with negative factor
        c.scale(-2, true);
        REQUIRE(c.getRadius() == initialRadius);
    }
    
    SECTION("Triangle scaling with invalid factor") {
        Triangle t(Coordinates(0, 0), Coordinates(3, 0), Coordinates(0, 4));
        double initialArea = t.getArea();
        
        // Try scaling with zero
        t.scale(0, true);
        REQUIRE(t.getArea() == Approx(initialArea));
        
        // Try scaling with negative factor
        t.scale(-2, true);
        REQUIRE(t.getArea() == Approx(initialArea));
    }
}

TEST_CASE("ShapeList operations with error handling", "[error_handling]") {
    ShapeList list;
    
    SECTION("Adding null pointer") {
        // Add a null pointer to the list
        list.addShape(nullptr);
        REQUIRE(list.getSize() == 0); // Should not add null pointers
    }
    
    SECTION("Removing shape at invalid index") {
        // Try to remove from empty list
        REQUIRE(list.removeShape(0) == false);
        
        // Add a shape
        list.addShape(new Rectangle(Coordinates(10, 10), 5, 5));
        REQUIRE(list.getSize() == 1);
        
        // Try to remove at negative index
        REQUIRE(list.removeShape(-1) == false);
        REQUIRE(list.getSize() == 1);
        
        // Try to remove at out-of-bounds index
        REQUIRE(list.removeShape(5) == false);
        REQUIRE(list.getSize() == 1);
        
        // Valid removal
        REQUIRE(list.removeShape(0) == true);
        REQUIRE(list.getSize() == 0);
    }
    
    SECTION("Getting shape at invalid index") {
        // Try to get from empty list
        REQUIRE(list.getShape(0) == nullptr);
        
        // Add a shape
        list.addShape(new Rectangle(Coordinates(10, 10), 5, 5));
        
        // Try to get at negative index
        REQUIRE(list.getShape(-1) == nullptr);
        
        // Try to get at out-of-bounds index
        REQUIRE(list.getShape(5) == nullptr);
        
        // Valid get
        REQUIRE(list.getShape(0) != nullptr);
        
        // Clean up
        list.removeShape(0);
    }
    
    SECTION("Performance optimizations") {
        // Add some shapes
        list.addShape(new Rectangle(Coordinates(10, 10), 5, 5));
        list.addShape(new Circle(Coordinates(20, 20), 10));
        
        // Test translate with no change (dx=0, dy=0)
        list.translateShapes(0, 0);
        REQUIRE(list.getShape(0)->getPosition().getX() == 10);
        REQUIRE(list.getShape(0)->getPosition().getY() == 10);
        
        // Test scale with factor 1 (no change)
        list.scale(1, true);
        
        // Rectangle should be unchanged
        Rectangle* rect = static_cast<Rectangle*>(list.getShape(0));
        REQUIRE(rect->getWidth() == 5);
        REQUIRE(rect->getLength() == 5);
        
        // Clean up happens in destructor
    }
} 