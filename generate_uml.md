# UML Diagram for Shape Management System

Below is a PlantUML script that generates a UML class diagram for the Shape Management System. You can use this with any PlantUML tool or online service to create a diagram for your report.

```plantuml
@startuml

class Coordinates {
  - x: int
  - y: int
  + Coordinates()
  + Coordinates(x: int, y: int)
  + getX(): int
  + getY(): int
  + setX(x: int): void
  + setY(y: int): void
  + distance(p: Coordinates): double
  + translate(dx: int, dy: int): void
  + scale(factor: double, sign: bool): void
  + display(): string
}

abstract class Shape {
  # position: Coordinates
  # sides: int
  + Shape(position: Coordinates, sides: int)
  + getPosition(): Coordinates
  + getSides(): int
  + {abstract} getArea(): double
  + {abstract} getPerimeter(): double
  + translate(dx: int, dy: int): void
  + {abstract} scale(factor: double, sign: bool): void
  + display(): string
}

class Rectangle {
  # width: int
  # length: int
  + Rectangle(position: Coordinates, width: int, length: int)
  + getWidth(): int
  + getLength(): int
  + getArea(): double
  + getPerimeter(): double
  + scale(factor: double, sign: bool): void
  + display(): string
}

class Square {
  + Square(position: Coordinates, side: int)
  + display(): string
}

class Triangle {
  - v1: Coordinates
  - v2: Coordinates
  - v3: Coordinates
  + Triangle(v1: Coordinates, v2: Coordinates, v3: Coordinates)
  + getV1(): Coordinates
  + getV2(): Coordinates
  + getV3(): Coordinates
  + getArea(): double
  + getPerimeter(): double
  + translate(dx: int, dy: int): void
  + scale(factor: double, sign: bool): void
  + display(): string
}

class Circle {
  - radius: int
  + Circle(center: Coordinates, radius: int)
  + getRadius(): int
  + getArea(): double
  + getPerimeter(): double
  + scale(factor: double, sign: bool): void
  + display(): string
}

class ShapeList {
  - listOfShapes: vector<Shape*>
  + ShapeList()
  + ~ShapeList()
  + addShape(s: Shape*): void
  + removeShape(pos: int): bool
  + translateShapes(dx: int, dy: int): void
  + scale(factor: double, sign: bool): void
  + display(): string
  + getSize(): int
  + getShape(pos: int): Shape*
}

class ShapeManagement {
  - shapeList: ShapeList
  - printMenu(): void
  - addShape(): void
  - addRectangle(): void
  - addSquare(): void
  - addTriangle(): void
  - addCircle(): void
  - removeShape(): void
  - displayShapeInfo(): void
  - displayShapeAreaPerimeter(): void
  - translateShapes(): void
  - scaleShapes(): void
  - displayShapes(): void
  - runUnitTests(): void
  + run(): void
}

Shape <|-- Rectangle
Rectangle <|-- Square
Shape <|-- Triangle
Shape <|-- Circle
Shape o-- Coordinates
ShapeList o-- "0..*" Shape
ShapeManagement o-- ShapeList
Triangle o-- "3" Coordinates

@enduml
```

## How to Use This UML Diagram

1. Copy the PlantUML code above
2. Go to an online PlantUML editor such as:
   - http://www.plantuml.com/plantuml/uml/
   - https://www.planttext.com/
3. Paste the code and generate the diagram
4. Save the resulting image for your report

The diagram shows the class hierarchy and relationships in the Shape Management System:
- Inheritance relationships between Shape and derived classes
- Composition relationships (e.g., ShapeList contains Shape objects)
- Attributes and methods for each class

This UML diagram should be included in your report to illustrate the object-oriented design of your system. 