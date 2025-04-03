@echo off
setlocal enabledelayedexpansion

echo Shape Management System - Windows Compilation Script (MSVC Version)

REM Check if the Visual Studio Developer Command Prompt is initialized
where cl >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo Visual C++ compiler (cl.exe) not found.
    echo Please run this script from a Visual Studio Developer Command Prompt
    echo or run vcvarsall.bat first to set up the Visual C++ environment.
    echo.
    echo For example:
    echo   "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
    pause
    exit /b 1
)

REM Create build directory if it doesn't exist
if not exist build mkdir build

REM Check if Catch2 header exists, if not download it
if not exist catch.hpp (
    echo Downloading Catch2 header...
    powershell -Command "Invoke-WebRequest -Uri https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp -OutFile catch.hpp"
    if %ERRORLEVEL% NEQ 0 (
        echo Failed to download Catch2 header.
        echo Please download it manually from: https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp
        pause
        exit /b 1
    )
)

REM Define M_PI if not defined in Visual C++
set CPPFLAGS=/D_USE_MATH_DEFINES /EHsc /std:c++14

REM Compile the main program
echo Compiling Shape Management System...
cl %CPPFLAGS% main.cpp Coordinates.cpp Shape.cpp ShapeList.cpp /Fe: build\shape_management.exe
if %ERRORLEVEL% NEQ 0 (
    echo Compilation of main program failed.
    pause
    exit /b 1
)

REM Compile the tests
echo Compiling Unit Tests...
cl %CPPFLAGS% tests.cpp Coordinates.cpp Shape.cpp ShapeList.cpp /Fe: build\tests.exe
if %ERRORLEVEL% NEQ 0 (
    echo Compilation of unit tests failed.
    pause
    exit /b 1
)

REM Compile the calculation tests
echo Compiling Calculation Tests...
cl %CPPFLAGS% test_calculations.cpp Coordinates.cpp Shape.cpp ShapeList.cpp /Fe: build\test_calculations.exe
if %ERRORLEVEL% NEQ 0 (
    echo Compilation of calculation tests failed.
    pause
    exit /b 1
)

REM Clean up intermediate object files
del *.obj

echo.
echo Compilation complete!
echo.
echo To run the Shape Management System: build\shape_management.exe
echo To run the Unit Tests: build\tests.exe
echo To run the Calculation Tests: build\test_calculations.exe
echo.

REM Ask user if they want to run one of the programs
set /p choice="Would you like to run one of the programs now? (1=Management System, 2=Unit Tests, 3=Calculation Tests, 0=Exit): "

if "%choice%"=="1" (
    echo Running Shape Management System...
    build\shape_management.exe
) else if "%choice%"=="2" (
    echo Running Unit Tests...
    build\tests.exe
) else if "%choice%"=="3" (
    echo Running Calculation Tests...
    build\test_calculations.exe
) else (
    echo Exiting.
)

pause 