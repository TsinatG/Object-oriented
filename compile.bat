@echo off
setlocal enabledelayedexpansion

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

REM Compile the main program
echo Compiling Shape Management System...
g++ -std=c++14 main.cpp Coordinates.cpp Shape.cpp ShapeList.cpp -o shape_management.exe
if errorlevel 1 (
    echo Compilation of main program failed.
    pause
    exit /b 1
)

REM Compile the tests
echo Compiling Unit Tests...
g++ -std=c++14 tests.cpp Coordinates.cpp Shape.cpp ShapeList.cpp -o tests.exe
if errorlevel 1 (
    echo Compilation of unit tests failed.
    pause
    exit /b 1
)

REM Compile the calculation tests
echo Compiling Calculation Tests...
g++ -std=c++14 test_calculations.cpp Coordinates.cpp Shape.cpp ShapeList.cpp -o test_calculations.exe
if errorlevel 1 (
    echo Compilation of calculation tests failed.
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