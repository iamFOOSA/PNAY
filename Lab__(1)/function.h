#ifndef LAB___1__FUNCTION_H
#define LAB___1__FUNCTION_H

class Matrix {
    int cols;

    int rows;

    float **M;

public:

    Matrix(int row, int cols);

    Matrix(const Matrix &other);

    ~Matrix();

    void CreateMatrix() const;

    void ShowMatrix() const;

    Matrix ADD(const Matrix &B) const;

    Matrix MULTIPLY(const Matrix &B) const;

};

void MatrixSetting(int &rows, int &cols);

void ShowMenu();

#endif
