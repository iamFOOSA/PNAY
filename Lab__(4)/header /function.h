#ifndef LAB___4__FUNCTION_H
#define LAB___4__FUNCTION_H

#include "../header /Shape .h"
#include <string>

void clearInputBuffer();

double getPositiveInput(const std::string &prompt);

void displayMenu();

void resizeShapesArray(Shape **&shapes, int &capacity, int shapeCount);

void addCircle(Shape **&shapes, int &shapeCount, int &capacity);

void addSquare(Shape **&shapes, int &shapeCount, int &capacity);

void addTriangle(Shape **&shapes, int &shapeCount, int &capacity);

void addSphere(Shape **&shapes, int &shapeCount, int &capacity);

void addCube(Shape **&shapes, int &shapeCount, int &capacity);

void addCylinder(Shape **&shapes, int &shapeCount, int &capacity);

void showAllShapes(Shape **shapes, int shapeCount);

void show2DShapes(Shape **shapes, int shapeCount);

void show3DShapes(Shape **shapes, int shapeCount);

void calculateTotalArea(Shape **shapes, int shapeCount);

void deleteAllShapes(Shape **&shapes, int &shapeCount, int &capacity);

#endif
