#include <iostream>
#include "../header /Circle.h"
#include "../header /Cube.h"
#include "../header /Cylinder.h"
#include "../header /Sphere.h"
#include "../header /Square.h"
#include "../header /Triangle.h"
#include <limits>
#include <stdexcept>
#include <span>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getPositiveInput(const string &prompt) {
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
    cout << "\n    MENU    " << endl;
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
    cout << "0. Exit" << endl;
    cout << "Choose number: ";
}

void resizeShapesArray(Shape **&shapes, int &capacity, int shapeCount) {
    int newCapacity = capacity * 2;
    auto newShapes = new Shape *[newCapacity];

    for (int i = 0; i < shapeCount; ++i) {
        newShapes[i] = shapes[i];
    }

    delete[] shapes;
    shapes = newShapes;
    capacity = newCapacity;
}

void addCircle(Shape **&shapes, int &shapeCount, int &capacity) {
    if (shapeCount >= capacity) {
        resizeShapesArray(shapes, capacity, shapeCount);
    }

    double radius = getPositiveInput("Enter circle radius: ");
    shapes[shapeCount++] = new Circle(radius);
    cout << "Circle added!" << endl;
}

void addSquare(Shape **&shapes, int &shapeCount, int &capacity) {
    if (shapeCount >= capacity) {
        resizeShapesArray(shapes, capacity, shapeCount);
    }

    double side = getPositiveInput("Enter square side length: ");
    shapes[shapeCount++] = new Square(side);
    cout << "Square added!" << endl;
}

void addTriangle(Shape **&shapes, int &shapeCount, int &capacity) {
    if (shapeCount >= capacity) {
        resizeShapesArray(shapes, capacity, shapeCount);
    }

    double base = getPositiveInput("Enter base: ");
    double height = getPositiveInput("Enter height: ");
    double side1 = getPositiveInput("Enter first side: ");
    double side2 = getPositiveInput("Enter second side: ");

    try {
        shapes[shapeCount++] = new Triangle(base, height, side1, side2);
        cout << "Triangle added!" << endl;
    } catch (const invalid_argument &e) {
        cout << "Error creating triangle: " << e.what() << endl;
        cout << "Please ensure:" << endl;
        cout << "1. All sides are positive" << endl;
        cout << "2. Sum of any two sides > third side" << endl;
        cout << "3. Height matches the given sides" << endl;
        shapeCount--;
    }
}

void addSphere(Shape **&shapes, int &shapeCount, int &capacity) {
    if (shapeCount >= capacity) {
        resizeShapesArray(shapes, capacity, shapeCount);
    }

    double radius = getPositiveInput("Enter sphere radius: ");
    shapes[shapeCount++] = new Sphere(radius);
    cout << "Sphere added!" << endl;
}

void addCube(Shape **&shapes, int &shapeCount, int &capacity) {
    if (shapeCount >= capacity) {
        resizeShapesArray(shapes, capacity, shapeCount);
    }

    double side = getPositiveInput("Enter cube side length: ");
    shapes[shapeCount++] = new Cube(side);
    cout << "Cube added!" << endl;
}

void addCylinder(Shape **&shapes, int &shapeCount, int &capacity) {
    if (shapeCount >= capacity) {
        resizeShapesArray(shapes, capacity, shapeCount);
    }

    double radius = getPositiveInput("Enter cylinder radius: ");
    double height = getPositiveInput("Enter cylinder height: ");
    shapes[shapeCount++] = new Cylinder(radius, height);
    cout << "Cylinder added!" << endl;
}

void showAllShapes(span<Shape *> shapes) {
    if (shapes.empty()) {
        cout << "No shapes created!" << endl;
        return;
    }

    cout << "\n\t SHAPES (" << shapes.size() << ")" << endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "\n    Shape " << i + 1 << endl;
        shapes[i]->print();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Volume: " << shapes[i]->volume() << endl;
        cout << "Visualization:" << endl;
        shapes[i]->draw();
    }
}

void show2DShapes(span<Shape *> shapes) {
    cout << "\n\t2D SHAPES" << endl;
    bool found = false;

    for (size_t i = 0; i < shapes.size(); ++i) {
        auto shape2D = dynamic_cast<const TwoDShape *>(shapes[i]);
        if (shape2D) {
            found = true;
            cout << "\n    Shape " << i + 1 << endl;
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

void show3DShapes(span<Shape *> shapes) {
    cout << "\n\t3D SHAPES" << endl;
    bool found = false;

    for (size_t i = 0; i < shapes.size(); ++i) {
        auto shape3D = dynamic_cast<const ThreeDShape *>(shapes[i]);
        if (shape3D) {
            found = true;
            cout << "\n    Shape " << i + 1 << endl;
            shapes[i]->print();
            cout << "Surface Area: " << shapes[i]->area() << endl;
            cout << "Volume: " << shapes[i]->volume() << endl;
            cout << "Visualization:" << endl;
            shapes[i]->draw();
        }
    }

    if (!found) {
        cout << "No 3D shapes!" << endl;
    }
}

void calculateTotalArea(span<Shape *> shapes) {
    if (shapes.empty()) {
        cout << "No shapes to calculate!" << endl;
        return;
    }

    double totalArea = 0;
    for (auto shape: shapes) {
        totalArea += shape->area();
    }
    cout << "Total area of all shapes: " << totalArea << endl;
}

