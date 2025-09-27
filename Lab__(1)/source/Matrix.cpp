#include "../header/function.h"
#include "../header/Matrix.h"
#include "iostream"

Matrix::Matrix(int row, int col)
        : cols(col), rows(row) {
    M = new float *[rows];
    for (int i = 0; i < rows; i++) {
        M[i] = new float[cols];
    }
}

Matrix::Matrix(const Matrix &other)
        : cols(other.cols), rows(other.rows) {
    M = new float *[rows];
    for (int i = 0; i < rows; ++i) {
        M[i] = new float[cols];
        for (int j = 0; j < cols; ++j) {
            M[i][j] = other.M[i][j];
        }
    }


}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] M[i];
    }
    delete[] M;
}

void Matrix::create_matrix() const {
    std::cout << "please write elements of the matrix through the space" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> M[i][j];
        }
    }
}

Matrix Matrix::add_matrix(const Matrix &B) const {
    Matrix C(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C.M[i][j] = M[i][j] + B.M[i][j];
        }
    }
    return C;
}

Matrix Matrix::multiply_matrix(const Matrix &B) const {
    Matrix C(rows, B.cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < B.cols; j++) {
            C.M[i][j] = 0;
            for (int k = 0; k < cols; k++)
                C.M[i][j] += M[i][k] * B.M[k][j];
        }

    return C;
}

void Matrix::show_matrix() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}