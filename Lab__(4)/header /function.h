#ifndef LAB___4__FUNCTION_H
#define LAB___4__FUNCTION_H

#include "../header /Shape .h"
#include <string>
#include <span>

void clear_input_buffer();

double get_positive_input(const std::string &prompt);

void display_menu();

void resize_shapes_array(Shape **&shapes, int &capacity, int shape_count);

void add_circle(Shape **&shapes, int &shape_count, int &capacity);

void add_square(Shape **&shapes, int &shape_count, int &capacity);

void add_triangle(Shape **&shapes, int &shape_count, int &capacity);

void add_sphere(Shape **&shapes, int &shape_count, int &capacity);

void add_cube(Shape **&shapes, int &shape_count, int &capacity);

void add_cylinder(Shape **&shapes, int &shape_count, int &capacity);

void show_all_shapes(std::span<Shape *> shapes);

void show_2d_shapes(std::span<Shape *> shapes);

void show_3d_shapes(std::span<Shape *> shapes);

void calculate_total_area(std::span<Shape *> shapes);

void delete_all_shapes(Shape **&shapes, int &shape_count, int &capacity);



#endif
