#ifndef LAB___4__FUNCTION_H
#define LAB___4__FUNCTION_H

#include "../header /Shape .h"
#include <string>
#include <span>

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

void showAllShapes(std::span<Shape *> shapes);

void show2DShapes(std::span<Shape *> shapes);

void show3DShapes(std::span<Shape *> shapes);

void calculateTotalArea(std::span<Shape *> shapes);

void deleteAllShapes(Shape **&shapes, int &shapeCount, int &capacity);

#endif
