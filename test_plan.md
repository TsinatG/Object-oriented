# Shape Management System Test Plan

## Test Case Execution Instructions

1. Compile and run the Shape Management System:
   ```bash
   ./compile.sh
   ./shape_management
   ```
2. For each test case, follow the instructions and document the results
3. Include console outputs or screenshots as evidence
4. Complete the "Evidence Result" column with observations

## Test Cases

| Action | Expected Result | Evidence Result |
|--------|----------------|-----------------|
| Create a triangle whose vertices have the coordinates (50,50), (20,70), (70,70) and add it to the list of shapes | ShapeList contains 1 shape and it's a triangle at the location supplied. Triangle area and perimeter calculations are correct. | |
| Create a Rectangle in position (100, 20) width 10, length 15 and add it to the list of shapes | ShapeList contains 2 shapes. Rectangle dimensions and position are correct. | |
| Create a circle in position (80, 100) and radius 25 and add it to the list of shapes | ShapeList contains 3 shapes. Circle position and radius are correct. | |
| Create a square in position (90, 40) with side 20 and add it to the list of shapes | ShapeList contains 4 shapes. Square dimensions and position are correct. | |
| Add three other shapes of your choice here | ShapeList contains 7 shapes. All shapes properly initialized. | |
| Show area and perimeter the second shape of the list | Display correct area and perimeter of Rectangle at position 1 | |
| Display information of all the shapes | All 7 shapes display their properties correctly | |
| Remove the third shape and check that no error occurs | ShapeList contains 6 shapes. Circle removed successfully. | |
| Translate all the shapes by 10 for coordinate x and 15 for coordinate y | All shapes moved by (10,15) from their original positions | |
| Display information of all the shapes | All shapes show updated coordinates after translation | |
| Increase all the shapes by a factor of 2 | All shape dimensions doubled in size | |
| Display all the shapes and see if they have changed in position and dimensions | All shapes maintain translated positions with doubled dimensions | |
| Add more Actions - Attempt to create a shape with invalid dimensions (e.g., negative width) | System should reject the invalid input or handle it appropriately | |
| Add actions for error handling - Remove a shape in position 20 | System shows appropriate error message indicating position is out of bounds | |
| Add actions for error handling - Display area of shape in position 100 | System shows appropriate error message indicating position is out of bounds | |

## Detailed Testing Instructions

### Test Case 1: Create a Triangle
1. Select option 1 (Add Shape)
2. Select option 3 (Triangle)
3. Enter vertices coordinates: (50,50), (20,70), (70,70)
4. Select option 5 to display all shapes
5. Record the area and perimeter values

### Test Case 2: Create a Rectangle
1. Select option 1 (Add Shape)
2. Select option 1 (Rectangle)
3. Enter position (100,20)
4. Enter width: 10
5. Enter length: 15
6. Select option 5 to display all shapes
7. Verify both shapes are in the list

### Test Case 3: Create a Circle
1. Select option 1 (Add Shape)
2. Select option 4 (Circle)
3. Enter center position (80,100)
4. Enter radius: 25
5. Select option 5 to display all shapes
6. Verify all three shapes are in the list

### Test Case 4: Create a Square
1. Select option 1 (Add Shape)
2. Select option 2 (Square)
3. Enter position (90,40)
4. Enter side length: 20
5. Select option 5 to display all shapes
6. Verify all four shapes are in the list

### Test Case 5: Add Three More Shapes
Add three more shapes of your choice, such as:
1. Another Triangle (e.g., vertices at (0,0), (30,0), (15,20))
2. Another Rectangle (e.g., position (50,50), width 25, length 40)
3. Another Circle (e.g., center (120,120), radius 15)

### Test Case 6: Show Area and Perimeter of Second Shape
1. Select option 4 (Area and perimeter of a shape by position)
2. Enter position: 1
3. Record the area and perimeter values

### Test Case 7: Display All Shapes
1. Select option 5
2. Verify all 7 shapes are displayed with correct properties

### Test Case 8: Remove the Third Shape
1. Select option 2 (Remove Shape by position)
2. Enter position: 2
3. Select option 5 to display all shapes
4. Verify the third shape was removed and there are now 6 shapes

### Test Case 9: Translate All Shapes
1. Select option 6 (Translate all shapes)
2. Enter translation values: 10 15
3. Select option 5 to display all shapes
4. Verify all coordinates have been updated

### Test Case 10: Display All Shapes After Translation
1. Select option 5
2. Verify all shapes have new coordinates (translated by 10,15)

### Test Case 11: Scale All Shapes by Factor of 2
1. Select option 7 (Scale all shapes)
2. Enter scale factor: 2
3. Select option 1 (Multiply)
4. Select option 5 to display all shapes
5. Verify all dimensions have been doubled

### Test Case 12: Display All Shapes After Scaling
1. Select option 5
2. Verify all dimensions are doubled and positions are maintained

### Test Case 13: Error Handling - Create Invalid Shape
1. Select option 1 (Add Shape)
2. Try to create a shape with invalid dimensions (e.g., negative width)
3. Observe how the system handles this

### Test Case 14: Error Handling - Remove Shape at Invalid Position
1. Select option 2 (Remove Shape by position)
2. Enter position: 20 (out of bounds)
3. Verify appropriate error message is displayed

### Test Case 15: Error Handling - Display Shape at Invalid Position
1. Select option 4 (Area and perimeter of a shape by position)
2. Enter position: 100 (out of bounds)
3. Verify appropriate error message is displayed

## Evidence Collection Guidelines

For each test case, document:
1. The inputs provided
2. The console output or response
3. Whether the actual result matches the expected result
4. Any observations or issues discovered

## Test Results Summary

After completing all tests, summarize:
1. Number of tests passed vs. failed
2. Any unexpected behavior
3. Recommendations for improvements 