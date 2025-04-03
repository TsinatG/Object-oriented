#!/bin/bash

# Check if Catch2 header exists, if not download it
if [ ! -f "catch.hpp" ]; then
    echo "Downloading Catch2 header..."
    curl -o catch.hpp https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp
fi

# Clean any previous build artifacts
rm -f shape_management tests test_calculations
rm -f *.o

# Compile individual object files first
echo "Compiling source files..."
g++ -std=c++14 -c Coordinates.cpp -o Coordinates.o
g++ -std=c++14 -c Shape.cpp -o Shape.o
g++ -std=c++14 -c ShapeList.cpp -o ShapeList.o

# Check if compilation of object files was successful
if [ $? -ne 0 ]; then
    echo "Error compiling source files. Aborting."
    exit 1
fi

# Compile the main program
echo "Compiling Shape Management System..."
g++ -std=c++14 main.cpp Coordinates.o Shape.o ShapeList.o -o shape_management

# Compile the tests
echo "Compiling Unit Tests..."
g++ -std=c++14 tests.cpp Coordinates.o Shape.o ShapeList.o -o tests

# Compile the calculation tests
echo "Compiling Calculation Tests..."
g++ -std=c++14 test_calculations.cpp Coordinates.o Shape.o ShapeList.o -o test_calculations

# Make the executables executable
chmod +x shape_management
chmod +x tests
chmod +x test_calculations

echo "Compilation complete!"
echo ""
echo "To run the Shape Management System: ./shape_management"
echo "To run the Unit Tests: ./tests"
echo "To run the Calculation Tests: ./test_calculations" 