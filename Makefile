# Makefile for Shape Management System (Windows MinGW)
CXX = g++
CXXFLAGS = -std=c++14 -Wall -I.
DEPS = Coordinates.hpp Shape.hpp ShapeList.hpp
OBJ = Coordinates.o Shape.o ShapeList.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

shape_management: $(OBJ) main.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

tests: $(OBJ) tests.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

test_calculations: $(OBJ) test_calculations.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

all: shape_management tests test_calculations

main.o: main.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

tests.o: tests.cpp $(DEPS) catch.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

test_calculations.o: test_calculations.cpp $(DEPS) catch.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Download Catch2 header if it doesn't exist
catch.hpp:
	@echo Downloading Catch2 header...
	@powershell -Command "Invoke-WebRequest -Uri https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp -OutFile catch.hpp"

clean:
	rm -f *.o shape_management.exe tests.exe test_calculations.exe

.PHONY: all clean 