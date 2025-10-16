#include <iostream>
#include "../header /Circle.h"
#include "../header /function.h"


using namespace std;

int main() {
    auto shapes = new Shape*[10];
    int shapeCount = 0;
    int capacity = 10;

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
                addCircle(shapes, shapeCount, capacity);
                break;
            case 2:
                addSquare(shapes, shapeCount, capacity);
                break;
            case 3:
                addTriangle(shapes, shapeCount, capacity);
                break;
            case 4:
                addSphere(shapes, shapeCount, capacity);
                break;
            case 5:
                addCube(shapes, shapeCount, capacity);
                break;
            case 6:
                addCylinder(shapes, shapeCount, capacity);
                break;
            case 7:
                showAllShapes(span<Shape*>(shapes, shapeCount));
                break;
            case 8:
                show2DShapes(span<Shape*>(shapes, shapeCount));
                break;
            case 9:
                show3DShapes(span<Shape*>(shapes, shapeCount));
                break;
            case 10:
                calculateTotalArea(span<Shape*>(shapes, shapeCount));
                break;
            case 11:
                deleteAllShapes(shapes, shapeCount, capacity);
                break;
            case 0:
                for (int i = 0; i < shapeCount; ++i) {
                    delete shapes[i];
                }
                delete[] shapes;
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
