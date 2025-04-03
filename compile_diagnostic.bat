@echo off
echo Compiling diagnostic...

REM Compile all files with verbose output
echo Step 1: Compiling Coordinates.cpp
g++ -std=c++14 -v -c Coordinates.cpp -o Coordinates.o
if errorlevel 1 (
    echo Error compiling Coordinates.cpp
    goto :end
)

echo Step 2: Compiling Shape.cpp
g++ -std=c++14 -v -c Shape.cpp -o Shape.o
if errorlevel 1 (
    echo Error compiling Shape.cpp
    goto :end
)

echo Step 3: Compiling ShapeList.cpp
g++ -std=c++14 -v -c ShapeList.cpp -o ShapeList.o
if errorlevel 1 (
    echo Error compiling ShapeList.cpp
    goto :end
)

echo Step 4: Compiling and linking diagnostic.cpp
g++ -std=c++14 -v diagnostic.cpp Coordinates.o Shape.o -o diagnostic.exe
if errorlevel 1 (
    echo Error compiling diagnostic.cpp
    goto :end
)

echo Compilation successful! Running diagnostic...
diagnostic.exe

:end
pause 