#include "function.h"
#include "iostream"
#include <array>
#include <utility>

enum class TErrorCode {
    CORRECT,
    NON_NUMERIC,
    OUT_OF_RANGE
};

const int MIN_ARR = 2;
const int MAX_ARR = 10;

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

const std::array<std::string, 4> ERR = {
        "",
        "Error. Non-numeric value. Please try again. ",
        "Error. Out of Range. Please try again. ",
        "Error. incorrect size matrix. please try again."};

void MatrixSetting(int &rows, int &cols) {
    using
    enum TErrorCode;
    TErrorCode error;
    do {
        error = CORRECT;
        std::cout << "Please write size of matrix through the space in the range " << MIN_ARR << " .. " << MAX_ARR
                  << std::endl;
        std::cin >> rows;
        std::cin >> cols;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            error = NON_NUMERIC;
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        if ((rows < MIN_ARR || rows > MAX_ARR) || (cols < MIN_ARR || cols > MAX_ARR)) {
            error = OUT_OF_RANGE;
        }
        if (error != CORRECT) {
            std::cout << ERR[std::to_underlying(error)] << std::endl;
        }
    } while (error != CORRECT);
}

void Matrix::CreateMatrix() const {
    std::cout << "please write elements of the matrix through the space" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> M[i][j];
        }
    }
}

void Matrix::ShowMatrix() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix Matrix::ADD(const Matrix &B) const {
    Matrix C(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C.M[i][j] = M[i][j] + B.M[i][j];
        }
    }
    return C;
}

Matrix Matrix::MULTIPLY(const Matrix &B) const {
    Matrix C(rows, B.cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < B.cols; j++) {
            C.M[i][j] = 0;
            for (int k = 0; k < cols; k++)
                C.M[i][j] += M[i][k] * B.M[k][j];
        }

    return C;
}

void ShowMenu() {
    int choice;
    do {
        std::cout << "\n    Menu    \n";
        std::cout << "1. Matrix addition\n";
        std::cout << "2. Matrix multiplication\n";
        std::cout << "0. exit\n";
        std::cout << "choose point: ";
        std::cin >> choice;

        if (choice == 0) break;

        int rows1;
        int cols1;
        std::cout << "Matrix A:\n";
        MatrixSetting(rows1, cols1);
        Matrix A(rows1, cols1);
        A.CreateMatrix();

        int rows2;
        int cols2;
        std::cout << "Matrix B:\n";
        MatrixSetting(rows2, cols2);
        Matrix B(rows2, cols2);
        B.CreateMatrix();

        if (choice == 1) {
            if (rows1 == rows2 && cols1 == cols2) {
                Matrix C = A.ADD(B);
                std::cout << "Result Matrix:\n";
                C.ShowMatrix();
            } else {
                std::cout << "ERROR, please try again. Must be(rows1 = rows2) and (cols1 = cols2) \n";
            }
        } else if (choice == 2) {
            if (cols1 == rows2) {
                Matrix D = A.MULTIPLY(B);
                std::cout << "Result Matrix:\n";
                D.ShowMatrix();
            } else {
                std::cout << "ERROR, please try again. Must be(cols1 = rows2)\n";
            }
        } else {
            std::cout << "ERROR, please try again.\n";
        }

    } while (true);

    std::cout << "END\n";
}


