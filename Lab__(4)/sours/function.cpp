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

void clear_input_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double get_positive_input(const string &prompt) {
    double user_input;

    while (true) {
        cout << prompt;
        cin >> user_input;

        if (cin.fail()) {
            cout << "ERROR! Please enter a number (1-11)" << endl;
            clear_input_buffer();
            continue;
        }

        if (user_input <= 0) {
            cout << "ERROR. U dont need use '-' " << endl;
            clear_input_buffer();
            continue;
        }

        clear_input_buffer();
        return user_input;
    }
}

void display_menu() {
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
    cout << "11. Delete All Shapes" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose number: ";
}

void resize_shapes_array(Shape **&shapes, int &capacity, int shape_count) {
    int new_capacity = capacity * 2;
    auto new_shapes = new Shape *[new_capacity];

    for (int i = 0; i < shape_count; ++i) {
        new_shapes[i] = shapes[i];
    }

    delete[] shapes;
    shapes = new_shapes;
    capacity = new_capacity;
}

void add_circle(Shape **&shapes, int &shape_count, int &capacity) {
    if (shape_count >= capacity) {
        resize_shapes_array(shapes, capacity, shape_count);
    }

    double radius = get_positive_input("Enter circle radius: ");
    shapes[shape_count++] = new Circle(radius);
    cout << "Circle added!" << endl;
}

void add_square(Shape **&shapes, int &shape_count, int &capacity) {
    if (shape_count >= capacity) {
        resize_shapes_array(shapes, capacity, shape_count);
    }

    double side = get_positive_input("Enter square side length: ");
    shapes[shape_count++] = new Square(side);
    cout << "Square added!" << endl;
}

void add_triangle(Shape **&shapes, int &shape_count, int &capacity) {
    if (shape_count >= capacity) {
        resize_shapes_array(shapes, capacity, shape_count);
    }

    double base = get_positive_input("Enter base: ");
    double height = get_positive_input("Enter height: ");
    double side1 = get_positive_input("Enter first side: ");
    double side2 = get_positive_input("Enter second side: ");

    try {
        shapes[shape_count++] = new Triangle(base, height, side1, side2);
        cout << "Triangle added!" << endl;
    } catch (const invalid_argument &e) {
        cout << "Error creating triangle: " << e.what() << endl;
        cout << "Please ensure:" << endl;
        cout << "1. All sides are positive" << endl;
        cout << "2. Sum of any two sides > third side" << endl;
        cout << "3. Height matches the given sides" << endl;
        shape_count--;
    }
}

void add_sphere(Shape **&shapes, int &shape_count, int &capacity) {
    if (shape_count >= capacity) {
        resize_shapes_array(shapes, capacity, shape_count);
    }

    double radius = get_positive_input("Enter sphere radius: ");
    shapes[shape_count++] = new Sphere(radius);
    cout << "Sphere added!" << endl;
}

void add_cube(Shape **&shapes, int &shape_count, int &capacity) {
    if (shape_count >= capacity) {
        resize_shapes_array(shapes, capacity, shape_count);
    }

    double side = get_positive_input("Enter cube side length: ");
    shapes[shape_count++] = new Cube(side);
    cout << "Cube added!" << endl;
}

void add_cylinder(Shape **&shapes, int &shape_count, int &capacity) {
    if (shape_count >= capacity) {
        resize_shapes_array(shapes, capacity, shape_count);
    }

    double radius = get_positive_input("Enter cylinder radius: ");
    double height = get_positive_input("Enter cylinder height: ");
    shapes[shape_count++] = new Cylinder(radius, height);
    cout << "Cylinder added!" << endl;
}

void show_all_shapes(span<Shape *> shapes) {
    if (shapes.empty()) {
        cout << "No shapes created!" << endl;
        return;
    }

    cout << "\n\t SHAPES (" << shapes.size() << ")" << endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "\n    Shape " << i + 1 << " ---" << endl;
        shapes[i]->print();
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Volume: " << shapes[i]->volume() << endl;
        cout << "Visualization:" << endl;
        shapes[i]->draw();
    }
}

void show_2d_shapes(span<Shape *> shapes) {
    cout << "\n\t2D SHAPES" << endl;
    bool found = false;

    for (size_t i = 0; i < shapes.size(); ++i) {
        auto shape_2d = dynamic_cast<const TwoDShape *>(shapes[i]);
        if (shape_2d) {
            found = true;
            cout << "\n    Shape " << i + 1 << "    " << endl;
            shapes[i]->print();
            cout << "Area: " << shapes[i]->area() << endl;
            cout << "Perimeter: " << shape_2d->perimeter() << endl;
            cout << "Visualization:" << endl;
            shapes[i]->draw();
        }
    }

    if (!found) {
        cout << "No 2D shapes found!" << endl;
    }
}

void show_3d_shapes(span<Shape *> shapes) {
    cout << "\n\t3D SHAPES" << endl;
    bool found = false;

    for (size_t i = 0; i < shapes.size(); ++i) {
        auto shape_3d = dynamic_cast<const ThreeDShape *>(shapes[i]);
        if (shape_3d) {
            found = true;
            cout << "\n    Shape " << i + 1 << "    " << endl;
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

void calculate_total_area(span<Shape *> shapes) {
    if (shapes.empty()) {
        cout << "No shapes to calculate!" << endl;
        return;
    }

    double total_area = 0;
    for (auto shape: shapes) {
        total_area += shape->area();
    }
    cout << "Total area of all shapes: " << total_area << endl;
}

void delete_all_shapes(Shape **&shapes, int &shape_count, int &capacity) {
    for (int i = 0; i < shape_count; ++i) {
        delete shapes[i];
    }
    delete[] shapes;

    capacity = 10;
    shapes = new Shape *[capacity];
    shape_count = 0;
    cout << "All shapes deleted!" << endl;
}