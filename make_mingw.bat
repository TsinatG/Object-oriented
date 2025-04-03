@echo off
echo Running MinGW Make for Shape Management System

REM Check if MinGW make is available
where mingw32-make >nul 2>nul
if errorlevel 1 (
    echo mingw32-make not found. Checking for alternative make...
    where make >nul 2>nul
    if errorlevel 1 (
        echo No make utility found. Please ensure MinGW is properly installed.
        pause
        exit /b 1
    ) else (
        set MAKE_CMD=make
    )
) else (
    set MAKE_CMD=mingw32-make
)

echo Using make command: %MAKE_CMD%

REM Run make to build all targets
%MAKE_CMD% all

if errorlevel 1 (
    echo Build failed.
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