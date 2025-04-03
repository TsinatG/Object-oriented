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

// Test functions with unique names
TEST_CASE("Coordinates_Constructor_and_getters", "[coordinates]") {
    Coordinates c(10, 20);
    REQUIRE(c.getX() == 10);
    REQUIRE(c.getY() == 20);
}

TEST_CASE("Coordinates_Distance_calculation", "[coordinates]") {
    Coordinates c1(0, 0);
    Coordinates c2(3, 4);
    REQUIRE(c1.distance(c2) == 5.0);
}

TEST_CASE("Coordinates_Translation", "[coordinates]") {
    Coordinates c(10, 20);
    c.translate(5, -10);
    REQUIRE(c.getX() == 15);
    REQUIRE(c.getY() == 10);
}

TEST_CASE("Coordinates_Scaling_multiply", "[coordinates]") {
    Coordinates c(10, 20);
    c.scale(2, true);
    REQUIRE(c.getX() == 20);
    REQUIRE(c.getY() == 40);
}

TEST_CASE("Coordinates_Scaling_divide", "[coordinates]") {
    Coordinates c(10, 20);
    c.scale(2, false);
    REQUIRE(c.getX() == 5);
    REQUIRE(c.getY() == 10);
}

TEST_CASE("Coordinates_Display", "[coordinates]") { 
    Coordinates c(10, 20);
    REQUIRE(c.display() == "X = 10, Y = 20");
}

// Rectangle tests with unique function names
TEST_CASE("Rectangle_Constructor_and_getters", "[rectangle]") {
    Coordinates pos(10, 20);
    Rectangle r(pos, 30, 40);
    REQUIRE(r.getPosition().getX() == 10);
    REQUIRE(r.getPosition().getY() == 20);
    REQUIRE(r.getWidth() == 30);
    REQUIRE(r.getLength() == 40);
    REQUIRE(r.getSides() == 4);
}

TEST_CASE("Rectangle_Area_and_perimeter", "[rectangle]") {
    Coordinates pos(10, 20);
    Rectangle r(pos, 30, 40);
    REQUIRE(r.getArea() == 1200);
    REQUIRE(r.getPerimeter() == 140);
}

TEST_CASE("Rectangle_Translation", "[rectangle]") {
    Coordinates pos(10, 20);
    Rectangle r(pos, 30, 40);
    r.translate(5, -10);
    REQUIRE(r.getPosition().getX() == 15);
    REQUIRE(r.getPosition().getY() == 10);
}

TEST_CASE("Rectangle_Scaling_multiply", "[rectangle]") {
    Coordinates pos(10, 20);
    Rectangle r(pos, 30, 40);
    r.scale(2, true);
    REQUIRE(r.getWidth() == 60);
    REQUIRE(r.getLength() == 80);
}

// Triangle tests with unique function names
TEST_CASE("Triangle_Constructor_and_getters", "[triangle]") {
    Coordinates v1(0, 0), v2(3, 0), v3(0, 4);
    Triangle t(v1, v2, v3);
    REQUIRE(t.getV1().getX() == 0);
    REQUIRE(t.getV1().getY() == 0);
    REQUIRE(t.getSides() == 3);
}

TEST_CASE("Triangle_Area_and_perimeter", "[triangle]") {
    Coordinates v1(0, 0), v2(3, 0), v3(0, 4);
    Triangle t(v1, v2, v3);
    REQUIRE(t.getArea() == Approx(6.0));
    REQUIRE(t.getPerimeter() == Approx(12.0));
}

TEST_CASE("Triangle_Translation", "[triangle]") {
    Coordinates v1(0, 0), v2(3, 0), v3(0, 4);
    Triangle t(v1, v2, v3);
    t.translate(10, 10);
    REQUIRE(t.getV1().getX() == 10);
    REQUIRE(t.getV1().getY() == 10);
    REQUIRE(t.getV2().getX() == 13);
    REQUIRE(t.getV2().getY() == 10);
    REQUIRE(t.getV3().getX() == 10);
    REQUIRE(t.getV3().getY() == 14);
}

// Circle tests with unique function names
TEST_CASE("Circle_Constructor_and_getters", "[circle]") {
    Coordinates center(10, 20);
    Circle c(center, 5);
    REQUIRE(c.getPosition().getX() == 10);
    REQUIRE(c.getPosition().getY() == 20);
    REQUIRE(c.getRadius() == 5);
    REQUIRE(c.getSides() == 0);
}

TEST_CASE("Circle_Area_and_perimeter", "[circle]") {
    Coordinates center(10, 20);
    Circle c(center, 5);
    REQUIRE(c.getArea() == Approx(M_PI * 25));
    REQUIRE(c.getPerimeter() == Approx(2 * M_PI * 5));
}

// ShapeList tests with unique function names
TEST_CASE("ShapeList_Add_and_remove_shapes", "[shapelist]") {
    ShapeList list;
    Coordinates pos(10, 20);
    list.addShape(new Rectangle(pos, 30, 40));
    REQUIRE(list.getSize() == 1);
    
    list.removeShape(0);
    REQUIRE(list.getSize() == 0);
}

TEST_CASE("ShapeList_Translate_shapes", "[shapelist]") {
    ShapeList list;
    Coordinates pos(10, 20);
    list.addShape(new Rectangle(pos, 30, 40));
    list.translateShapes(5, -10);
    
    Shape* shape = list.getShape(0);
    REQUIRE(shape->getPosition().getX() == 15);
    REQUIRE(shape->getPosition().getY() == 10);
} 