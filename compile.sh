#!/bin/bash

# Check if Catch2 header exists, if not download it
if [ ! -f "catch.hpp" ]; then
    echo "Downloading Catch2 header..."
    curl -O https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp
fi

# Compile the main program
echo "Compiling Shape Management System..."
g++ -std=c++14 main.cpp Coordinates.cpp Shape.cpp ShapeList.cpp -o shape_management

# Compile the tests
echo "Compiling Unit Tests..."
g++ -std=c++14 tests.cpp Coordinates.cpp Shape.cpp ShapeList.cpp -o tests

# Compile the calculation tests
echo "Compiling Calculation Tests..."
g++ -std=c++14 test_calculations.cpp Coordinates.cpp Shape.cpp ShapeList.cpp -o test_calculations

# Make the executables executable
chmod +x shape_management
chmod +x tests
chmod +x test_calculations

echo "Compilation complete!"
echo ""
echo "To run the Shape Management System: ./shape_management"
echo "To run the Unit Tests: ./tests"
echo "To run the Calculation Tests: ./test_calculations" 