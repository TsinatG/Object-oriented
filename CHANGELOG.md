# Changelog

All notable changes to the Shape Management System will be documented in this file.

## [1.1.0] - 2023-12-01

### Added
- Comprehensive error handling for all shape operations
- Triangle validation using the triangle inequality theorem
- Performance optimizations for ShapeList operations
- Windows compilation scripts (`compile.bat`, `compile_mingw.bat`, `compile_msvc.bat`)
- UML diagram of the Shape Management System architecture
- Detailed README files with compilation and usage instructions

### Changed
- Improved validation in shape constructors
- Enhanced error messages for invalid operations
- Optimized ShapeList methods for better performance
- Added non-negative validation for all shape dimensions
- Updated scale methods to handle negative scale factors

### Fixed
- Triangle validation to properly check the triangle inequality theorem
- ShapeList removeShape method to validate index before removal
- Scale methods to reject zero or negative scale factors
- Memory management in ShapeList to prevent memory leaks

## [1.0.0] - 2023-10-15

### Added
- Initial release of the Shape Management System
- Base Shape abstract class and derived shape classes
- Coordinates class for position management
- ShapeList class for managing collections of shapes
- Basic operations: display, area, perimeter, translate, scale
- Unit tests for basic functionality
- Linux compilation script 