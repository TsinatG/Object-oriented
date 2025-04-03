# Shape Management System - Windows Compilation Guide

This document explains how to compile and run the Shape Management System on Windows 10.

## Prerequisites

You need one of the following C++ compilers installed on your system:

1. **MinGW-w64 / GCC for Windows**
   - Download from: https://winlibs.com/ or https://www.mingw-w64.org/
   - Make sure to add the bin directory to your PATH environment variable

2. **Visual Studio with C++ development tools**
   - Download Visual Studio Community Edition from: https://visualstudio.microsoft.com/
   - During installation, select "Desktop development with C++"

## Compilation Options

We provide three different batch files for compiling the Shape Management System on Windows:

### Option 1: Standard Compilation (GCC/MinGW)

Use this option if you have MinGW/GCC installed and added to your PATH:

1. Double-click on `compile.bat` or run it from the command prompt
2. The script will:
   - Download the Catch2 header file if needed
   - Compile the main program and tests
   - Create executable files in the current directory

### Option 2: MinGW with Custom Setup

Use this option if you need to customize the compilation for MinGW:

1. Edit `compile_mingw.bat` to set the path to your MinGW installation if needed
2. Double-click on `compile_mingw.bat` or run it from the command prompt
3. The script will:
   - Download the Catch2 header file if needed
   - Create a `build` directory
   - Compile the main program and tests
   - Create executable files in the `build` directory

### Option 3: Visual Studio / MSVC

Use this option if you have Visual Studio installed:

1. Open a "Developer Command Prompt for VS" (search for it in the Start menu)
2. Navigate to the project directory using `cd` command
3. Run `compile_msvc.bat`
4. The script will:
   - Check if the Visual C++ environment is properly set up
   - Download the Catch2 header file if needed
   - Create a `build` directory
   - Compile the main program and tests using the MSVC compiler
   - Create executable files in the `build` directory

## Running the Programs

After successful compilation, you can run:

- `shape_management.exe` - The main Shape Management System
- `tests.exe` - The unit tests for the system
- `test_calculations.exe` - Tests for geometric calculations

The compilation scripts will offer to run one of these programs immediately after compilation.

## Troubleshooting

### Compiler Not Found

If you get an error that the compiler (g++ or cl) is not found:

- For MinGW/GCC: Make sure the bin directory of your MinGW installation is in your PATH
- For MSVC: Make sure you're running the script from a Developer Command Prompt for VS

### Missing Header Files

If you get errors about missing header files:

- Make sure you have all the source files in the correct directory
- If there's an error about missing `catch.hpp`, the automatic download might have failed. Download it manually from the URL provided in the error message.

### Runtime Errors

If the program compiles but crashes when running:

- For MinGW/GCC: Make sure you have the necessary DLLs in your PATH
- For MSVC: Make sure you have the Visual C++ Redistributable installed

## Project Structure

- `Coordinates.hpp` & `Coordinates.cpp`: Coordinate class implementation
- `Shape.hpp` & `Shape.cpp`: Base Shape class and derived classes
- `ShapeList.hpp` & `ShapeList.cpp`: ShapeList class implementation
- `main.cpp`: ShapeManagement console application
- `tests.cpp`: Unit tests for the classes
- `test_calculations.cpp`: Tests for geometric calculations 