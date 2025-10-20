#include <iostream>
#include "../header /Circle.h"
#include "../header /function.h"


using namespace std;

int main() {
    const int start_shape = 10;
    const int start_count = 0;
    const int start_capacity = 10;

    auto shapes = new Shape *[start_shape];
    int shape_count = start_count;
    int capacity = start_capacity;

    int choice;

    while (true) {
        display_menu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_circle(shapes, shape_count, capacity);
                break;
            case 2:
                add_square(shapes, shape_count, capacity);
                break;
            case 3:
                add_triangle(shapes, shape_count, capacity);
                break;
            case 4:
                add_sphere(shapes, shape_count, capacity);
                break;
            case 5:
                add_cube(shapes, shape_count, capacity);
                break;
            case 6:
                add_cylinder(shapes, shape_count, capacity);
                break;
            case 7:
                show_all_shapes(span<Shape *>(shapes, shape_count));
                break;
            case 8:
                show_2d_shapes(span<Shape *>(shapes, shape_count));
                break;
            case 9:
                show_3d_shapes(span<Shape *>(shapes, shape_count));
                break;
            case 10:
                calculate_total_area(span<Shape *>(shapes, shape_count));
                break;
            case 11:
                delete_all_shapes(shapes, shape_count, capacity);
                break;
            case 0:
                for (int i = 0; i < shape_count; ++i) {
                    delete shapes[i];
                }
                delete[] shapes;
                cout << "Program is over" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}