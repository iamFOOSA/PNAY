#ifndef LAB___1__MATRIX_H
#define LAB___1__MATRIX_H

class Matrix {
    int cols;

    int rows;

    float **M;

public:

    Matrix(int row, int cols);

    Matrix(const Matrix &other);

    ~Matrix();

    Matrix &operator=(const Matrix &) = delete;

    Matrix &operator=(Matrix &&) = delete;

    void create_matrix() const;

    void show_matrix() const;

    Matrix add_matrix(const Matrix &B) const;

    Matrix multiply_matrix(const Matrix &B) const;

};

#endif
