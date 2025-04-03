@echo off
echo Shape Management System - Windows Compilation Script

REM Check if Catch2 header exists, if not download it
if not exist catch.hpp (
    echo Downloading Catch2 header...
    powershell -Command "Invoke-WebRequest -Uri https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp -OutFile catch.hpp"
    if errorlevel 1 (
        echo Failed to download Catch2 header.
        echo Please download it manually from: https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp
        pause
        exit /b 1
    )
)

REM Clean any previous build artifacts
del /q shape_management.exe tests.exe test_calculations.exe 2>nul
del /q *.o 2>nul

REM Compile individual object files first
echo Compiling source files...
g++ -std=c++14 -c Coordinates.cpp -o Coordinates.o
if errorlevel 1 (
    echo Error compiling Coordinates.cpp. Aborting.
    pause
    exit /b 1
)

g++ -std=c++14 -c Shape.cpp -o Shape.o
if errorlevel 1 (
    echo Error compiling Shape.cpp. Aborting.
    pause
    exit /b 1
)

g++ -std=c++14 -c ShapeList.cpp -o ShapeList.o
if errorlevel 1 (
    echo Error compiling ShapeList.cpp. Aborting.
    pause
    exit /b 1
)

REM Compile the main program
echo Compiling Shape Management System...
g++ -std=c++14 main.cpp Coordinates.o Shape.o ShapeList.o -o shape_management.exe
if errorlevel 1 (
    echo Error compiling main program. Aborting.
    pause
    exit /b 1
)

REM Compile the tests
echo Compiling Unit Tests...
g++ -std=c++14 tests.cpp Coordinates.o Shape.o ShapeList.o -o tests.exe
if errorlevel 1 (
    echo Error compiling unit tests. Aborting.
    pause
    exit /b 1
)

REM Compile the calculation tests
echo Compiling Calculation Tests...
g++ -std=c++14 test_calculations.cpp Coordinates.o Shape.o ShapeList.o -o test_calculations.exe
if errorlevel 1 (
    echo Error compiling calculation tests. Aborting.
    pause
    exit /b 1
)

echo.
echo Compilation complete!
echo.
echo To run the Shape Management System: shape_management.exe
echo To run the Unit Tests: tests.exe
echo To run the Calculation Tests: test_calculations.exe
echo.

REM Ask user if they want to run one of the programs
set /p choice="Would you like to run one of the programs now? (1=Management System, 2=Unit Tests, 3=Calculation Tests, 0=Exit): "

if "%choice%"=="1" (
    echo Running Shape Management System...
    shape_management.exe
) else if "%choice%"=="2" (
    echo Running Unit Tests...
    tests.exe
) else if "%choice%"=="3" (
    echo Running Calculation Tests...
    test_calculations.exe
) else (
    echo Exiting.
)

pause 