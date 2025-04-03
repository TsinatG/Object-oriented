# Shape Management System

A comprehensive C++ application for managing and manipulating 2D geometric shapes.

## Project Overview

The Shape Management System is an object-oriented C++ application that provides functionality for creating, displaying, and manipulating various 2D shapes. It demonstrates key OOP principles including inheritance, polymorphism, and encapsulation.

### Features

- Create and manage multiple types of shapes:
  - Points
  - Lines
  - Circles
  - Rectangles
  - Squares
  - Triangles
- Perform operations on shapes:
  - Calculate area and perimeter
  - Translate (move) shapes
  - Scale shapes
  - Display shape properties
- Manage collections of shapes using ShapeList
- Comprehensive error handling and input validation
- Thorough unit testing

## Project Structure

- `Coordinates.hpp` & `Coordinates.cpp`: Coordinate class implementation
- `Shape.hpp` & `Shape.cpp`: Base Shape class and derived classes
- `ShapeList.hpp` & `ShapeList.cpp`: ShapeList class implementation
- `main.cpp`: ShapeManagement console application
- `tests.cpp`: Unit tests for the classes
- `test_calculations.cpp`: Tests for geometric calculations
- `compile.sh`: Compilation script for Linux
- `compile.bat`, `compile_mingw.bat`, `compile_msvc.bat`: Compilation scripts for Windows

## Compilation and Running

### Linux

To compile and run on Linux:

1. Open a terminal in the project directory
2. Run `chmod +x compile.sh` to make the script executable
3. Run `./compile.sh`
4. The script will compile the main program and tests
5. Run the program: `./shape_management`
6. Run tests: `./tests` or `./test_calculations`

### Windows

For Windows compilation instructions, see [README_WINDOWS.md](README_WINDOWS.md).

## Requirements

- C++11 compatible compiler (GCC, MinGW, MSVC, Clang)
- Catch2 header file (automatically downloaded by compilation scripts)

## Implementation Details

### Shape Hierarchy

The system implements the following class hierarchy:

```
Shape (Abstract Base Class)
├── Point
├── Line
├── Circle
├── Rectangle
│   └── Square
└── Triangle
```

### Shape Operations

Each shape supports the following operations:

- `display()`: Outputs the shape's properties
- `area()`: Calculates the area of the shape
- `perimeter()`: Calculates the perimeter of the shape
- `translate(dx, dy)`: Moves the shape by the specified offsets
- `scale(factor)`: Scales the shape by the given factor

### ShapeList

The `ShapeList` class manages a collection of shapes and supports:

- Adding shapes
- Removing shapes
- Displaying all shapes
- Applying operations to all shapes (translate, scale)

## Error Handling

The system implements robust error handling:

- Input validation for all shape parameters
- Triangle inequality verification for triangles
- Non-negative validation for dimensions
- Appropriate error messages for invalid operations

## Testing

The project includes comprehensive unit tests using the Catch2 framework:

- Tests for shape creation and properties
- Tests for shape operations
- Tests for error handling and edge cases
- Tests for ShapeList functionality

## License

This project is open source and available under the MIT License. 