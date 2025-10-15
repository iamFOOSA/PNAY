#include <iostream>
#include "../header /Circle.h"
#include "../header /Cube.h"
#include "../header /Cylinder.h"
#include "../header /Shape .h"
#include "../header /Sphere.h"
#include "../header /Square.h"
#include "../header /Triangle.h"
#include "../header /TwoDShape.h"
#include "../header /ThreeDShape.h"
#include <limits>

using namespace std;

Shape** shapes = nullptr;
int shapeCount = 0;
int capacity = 0;
const int INITIAL_CAPACITY = 10;

void initializeShapes() {
    capacity = INITIAL_CAPACITY;
    shapes = new Shape*[capacity];
    shapeCount = 0;
}

void cleanupShapes() {
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
    delete[] shapes;
    shapes = nullptr;
    shapeCount = 0;
    capacity = 0;
}

void resizeShapesArray() {
    int newCapacity = capacity * 2;
    Shape** newShapes = new Shape*[newCapacity];

    for (int i = 0; i < shapeCount; ++i) {
        newShapes[i] = shapes[i];
    }

    delete[] shapes;
    shapes = newShapes;
    capacity = newCapacity;
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getPositiveInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cout << "Error: Please enter a positive number!" << endl;
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return value;
        }
    }
}

void displayMenu() {
    cout << "\n\tGEOMETRIC SHAPES MANAGER" << endl;
    cout << "1. Add Circle" << endl;
    cout << "2. Add Square" << endl;
    cout << "3. Add Triangle" << endl;
    cout << "4. Add Sphere" << endl;
    cout << "5. Add Cube" << endl;
    cout << "6. Add Cylinder" << endl;
    cout << "7. Show All Shapes" << endl;
    cout << "8. Show Only 2D Shapes" << endl;
    cout << "9. Show Only 3D Shapes" << endl;
    cout << "10. Calculate Total Area" << endl;
    cout << "11. Delete All Shapes" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

void addCircle() {
    if (shapeCount >= capacity) {
        resizeShapesArray();
    }

    double radius = getPositiveInput("Enter circle radius: ");
    shapes[shapeCount++] = new Circle(radius);
    cout << "Circle added successfully!" << endl;
}

void addSquare() {
    if (shapeCount >= capacity) {
        resizeShapesArray();
    }

    double side = getPositiveInput("Enter square side length: ");
    shapes[shapeCount++] = new Square(side);
    cout << "Square added successfully!" << endl;
}

void addTriangle() {
    if (shapeCount >= capacity) {
        resizeShapesArray();
    }

    double base = getPositiveInput("Enter triangle base: ");
    double height = getPositiveInput("Enter triangle height: ");
    double side1 = getPositiveInput("Enter first side: ");
    double side2 = getPositiveInput("Enter second side: ");

    try {
        shapes[shapeCount++] = new Triangle(base, height, side1, side2);
        cout << "Triangle added successfully!" << endl;
    } catch (const exception& e) {
        cout << "Error creating triangle: " << e.what() << endl;
        cout << "Please ensure:" << endl;
        cout << "1. All sides are positive" << endl;
        cout << "2. Sum of any two sides > third side" << endl;
        cout << "3. Height matches the given sides" << endl;
    }
}

void addSphere() {
    if (shapeCount >= capacity) {
        resizeShapesArray();
    }

    double radius = getPositiveInput("Enter sphere radius: ");
    shapes[shapeCount++] = new Sphere(radius);
    cout << "Sphere added successfully!" << endl;
}

void addCube() {
    if (shapeCount >= capacity) {
        resizeShapesArray();
    }

    double side = getPositiveInput("Enter cube side length: ");
    shapes[shapeCount++] = new Cube(side);
    cout << "Cube added successfully!" << endl;
}

void addCylinder() {
    if (shapeCount >= capacity) {
        resizeShapesArray();
    }

    double radius = getPositiveInput("Enter cylinder radius: ");
    double height = getPositiveInput("Enter cylinder height: ");
    shapes[shapeCount++] = new Cylinder(radius, height);
    cout << "Cylinder added successfully!" << endl;
}

void showAllShapes() {
    if (shapeCount == 0) {
        cout << "No shapes created!" << endl;
        return;
    }

    cout << "\n\tALL SHAPES (" << shapeCount << ")" << endl;
    for (int i = 0; i < shapeCount; ++i) {
        cout << "\n--- Shape " << i + 1 << " ---" << endl;
        shapes[i]->print();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Volume: " << shapes[i]->volume() << endl;
        cout << "Visualization:" << endl;
        shapes[i]->draw();
    }
}

void show2DShapes() {
    cout << "\n\t2D SHAPES" << endl;
    bool found = false;

    for (int i = 0; i < shapeCount; ++i) {
        TwoDShape* shape2D = dynamic_cast<TwoDShape*>(shapes[i]);
        if (shape2D) {
            found = true;
            cout << "\n--- Shape " << i + 1 << " ---" << endl;
            shapes[i]->print();
            cout << "Area: " << shapes[i]->area() << endl;
            cout << "Perimeter: " << shape2D->perimeter() << endl;
            cout << "Visualization:" << endl;
            shapes[i]->draw();
        }
    }

    if (!found) {
        cout << "No 2D shapes found!" << endl;
    }
}

void show3DShapes() {
    cout << "\n\t3D SHAPES" << endl;
    bool found = false;

    for (int i = 0; i < shapeCount; ++i) {
        ThreeDShape* shape3D = dynamic_cast<ThreeDShape*>(shapes[i]);
        if (shape3D) {
            found = true;
            cout << "\n--- Shape " << i + 1 << " ---" << endl;
            shapes[i]->print();
            cout << "Surface Area: " << shapes[i]->area() << endl;
            cout << "Volume: " << shapes[i]->volume() << endl;
            cout << "Visualization:" << endl;
            shapes[i]->draw();
        }
    }

    if (!found) {
        cout << "No 3D shapes found!" << endl;
    }
}

void calculateTotalArea() {
    if (shapeCount == 0) {
        cout << "No shapes to calculate!" << endl;
        return;
    }

    double totalArea = 0;
    for (int i = 0; i < shapeCount; ++i) {
        totalArea += shapes[i]->area();
    }
    cout << "Total area of all shapes: " << totalArea << endl;
}

void deleteAllShapes() {
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }
    shapeCount = 0;
    cout << "All shapes deleted!" << endl;
}

int main() {
    initializeShapes();
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addCircle();
                break;
            case 2:
                addSquare();
                break;
            case 3:
                addTriangle();
                break;
            case 4:
                addSphere();
                break;
            case 5:
                addCube();
                break;
            case 6:
                addCylinder();
                break;
            case 7:
                showAllShapes();
                break;
            case 8:
                show2DShapes();
                break;
            case 9:
                show3DShapes();
                break;
            case 10:
                calculateTotalArea();
                break;
            case 11:
                deleteAllShapes();
                break;
            case 0:
                cleanupShapes();
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
