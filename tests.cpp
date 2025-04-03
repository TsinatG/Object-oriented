#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // You'll need to download the Catch2 header
#include "Shape.hpp"
#include "ShapeList.hpp"
#include <cmath>

// Define M_PI if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

TEST_CASE("Coordinates operations", "[coordinates]") {
    SECTION("Constructor and getters") {
        Coordinates c(10, 20);
        REQUIRE(c.getX() == 10);
        REQUIRE(c.getY() == 20);
    }
    
    SECTION("Distance calculation") {
        Coordinates c1(0, 0);
        Coordinates c2(3, 4);
        REQUIRE(c1.distance(c2) == 5.0);
    }
    
    SECTION("Translation") {
        Coordinates c(10, 20);
        c.translate(5, -10);
        REQUIRE(c.getX() == 15);
        REQUIRE(c.getY() == 10);
    }
    
    SECTION("Scaling - multiply") {
        Coordinates c(10, 20);
        c.scale(2, true);
        REQUIRE(c.getX() == 20);
        REQUIRE(c.getY() == 40);
    }
    
    SECTION("Scaling - divide") {
        Coordinates c(10, 20);
        c.scale(2, false);
        REQUIRE(c.getX() == 5);
        REQUIRE(c.getY() == 10);
    }
    
    SECTION("Display") { 
        Coordinates c(10, 20);
        REQUIRE(c.display() == "X = 10, Y = 20");
    }
}

TEST_CASE("Rectangle operations", "[rectangle]") {
    SECTION("Constructor and getters") {
        Coordinates pos(10, 20);
        Rectangle r(pos, 30, 40);
        REQUIRE(r.getPosition().getX() == 10);
        REQUIRE(r.getPosition().getY() == 20);
        REQUIRE(r.getWidth() == 30);
        REQUIRE(r.getLength() == 40);
        REQUIRE(r.getSides() == 4);
    }
    
    SECTION("Area and perimeter") {
        Coordinates pos(10, 20);
        Rectangle r(pos, 30, 40);
        REQUIRE(r.getArea() == 1200);
        REQUIRE(r.getPerimeter() == 140);
    }
    
    SECTION("Translation") {
        Coordinates pos(10, 20);
        Rectangle r(pos, 30, 40);
        r.translate(5, -10);
        REQUIRE(r.getPosition().getX() == 15);
        REQUIRE(r.getPosition().getY() == 10);
    }
    
    SECTION("Scaling - multiply") {
        Coordinates pos(10, 20);
        Rectangle r(pos, 30, 40);
        r.scale(2, true);
        REQUIRE(r.getWidth() == 60);
        REQUIRE(r.getLength() == 80);
    }
}

TEST_CASE("Triangle operations", "[triangle]") {
    SECTION("Constructor and getters") {
        Coordinates v1(0, 0), v2(3, 0), v3(0, 4);
        Triangle t(v1, v2, v3);
        REQUIRE(t.getV1().getX() == 0);
        REQUIRE(t.getV1().getY() == 0);
        REQUIRE(t.getSides() == 3);
    }
    
    SECTION("Area and perimeter") {
        Coordinates v1(0, 0), v2(3, 0), v3(0, 4);
        Triangle t(v1, v2, v3);
        REQUIRE(t.getArea() == Approx(6.0));
        REQUIRE(t.getPerimeter() == Approx(12.0));
    }
    
    SECTION("Translation") {
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
}

TEST_CASE("Circle operations", "[circle]") {
    SECTION("Constructor and getters") {
        Coordinates center(10, 20);
        Circle c(center, 5);
        REQUIRE(c.getPosition().getX() == 10);
        REQUIRE(c.getPosition().getY() == 20);
        REQUIRE(c.getRadius() == 5);
        REQUIRE(c.getSides() == 0);
    }
    
    SECTION("Area and perimeter") {
        Coordinates center(10, 20);
        Circle c(center, 5);
        REQUIRE(c.getArea() == Approx(M_PI * 25));
        REQUIRE(c.getPerimeter() == Approx(2 * M_PI * 5));
    }
}

TEST_CASE("ShapeList operations", "[shapelist]") {
    SECTION("Add and remove shapes") {
        ShapeList list;
        Coordinates pos(10, 20);
        list.addShape(new Rectangle(pos, 30, 40));
        REQUIRE(list.getSize() == 1);
        
        list.removeShape(0);
        REQUIRE(list.getSize() == 0);
    }
    
    SECTION("Translate shapes") {
        ShapeList list;
        Coordinates pos(10, 20);
        list.addShape(new Rectangle(pos, 30, 40));
        list.translateShapes(5, -10);
        
        Shape* shape = list.getShape(0);
        REQUIRE(shape->getPosition().getX() == 15);
        REQUIRE(shape->getPosition().getY() == 10);
    }
} 