@echo off
echo Shape Management System - Compilation with All Fixes

REM Make a backup of original files
if not exist backups mkdir backups
if not exist backups\Shape.hpp copy Shape.hpp backups\Shape.hpp
if not exist backups\tests.cpp copy tests.cpp backups\tests.cpp
if not exist backups\test_calculations.cpp copy test_calculations.cpp backups\test_calculations.cpp

REM Copy fixed header files
echo Copying fixed header files...
copy /Y Shape_fixed.hpp Shape.hpp
copy /Y tests_fixed.cpp tests.cpp
copy /Y test_calculations_fixed.cpp test_calculations.cpp

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

REM Compile main program one by one
echo Compiling main.cpp...
g++ -std=c++14 -c main.cpp -o main.o
if errorlevel 1 (
    echo Error compiling main.cpp. Aborting.
    pause
    exit /b 1
)

echo Linking main program...
g++ -o shape_management.exe main.o Coordinates.o Shape.o ShapeList.o
if errorlevel 1 (
    echo Error linking main program. Aborting.
    pause
    exit /b 1
)

REM Compile tests.cpp one by one
echo Compiling tests.cpp...
g++ -std=c++14 -c tests.cpp -o tests.o
if errorlevel 1 (
    echo Error compiling tests.cpp. Skipping tests.
    goto skip_tests
)

echo Linking tests...
g++ -o tests.exe tests.o Coordinates.o Shape.o ShapeList.o
if errorlevel 1 (
    echo Error linking tests. Skipping tests.
    goto skip_tests
)

:skip_tests

REM Compile test_calculations.cpp one by one
echo Compiling test_calculations.cpp...
g++ -std=c++14 -c test_calculations.cpp -o test_calculations.o
if errorlevel 1 (
    echo Error compiling test_calculations.cpp. Skipping test_calculations.
    goto skip_calculations
)

echo Linking test_calculations...
g++ -o test_calculations.exe test_calculations.o Coordinates.o Shape.o ShapeList.o
if errorlevel 1 (
    echo Error linking test_calculations. Skipping test_calculations.
    goto skip_calculations
)

:skip_calculations

echo.
echo Compilation complete!
echo.
echo To run the Shape Management System: shape_management.exe
if exist tests.exe echo To run the Unit Tests: tests.exe
if exist test_calculations.exe echo To run the Calculation Tests: test_calculations.exe
echo.

REM Ask user if they want to run one of the programs
set /p choice="Would you like to run one of the programs now? (1=Management System, 2=Unit Tests, 3=Calculation Tests, 0=Exit): "

if "%choice%"=="1" (
    echo Running Shape Management System...
    shape_management.exe
) else if "%choice%"=="2" (
    if exist tests.exe (
        echo Running Unit Tests...
        tests.exe
    ) else (
        echo Tests executable does not exist.
    )
) else if "%choice%"=="3" (
    if exist test_calculations.exe (
        echo Running Calculation Tests...
        test_calculations.exe
    ) else (
        echo Test Calculations executable does not exist.
    )
) else (
    echo Exiting.
)

pause 