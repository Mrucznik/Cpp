//
// Created by Mrucznik on 04.12.2016.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>

class Matrix
{
private:
    MatrixData matrix;

public:
    class MatrixRef;

    //konstruktory/dekonstruktory
    Matrix(Matrix);
    Matrix(int);
    Matrix(int, int);

    ~Matrix();

    //operatory
    Matrix& operator=(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);

    Matrix operator+(const Matrix&) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator*(const Matrix&) const;

    bool operator==(const Matrix&) const;
    bool operator!=(const Matrix&) const;

    double operator[](unsigned int) const;
    MatrixRef operator[](unsigned int);

    friend std::ostream &operator<<(std::ostream&, const Matrix&);

    //metody
    double read(int, int);
    void write(int, int, double);
    void load(std::istream);


};



struct MatrixData
{
public:
    unsigned int rows;
    unsigned int columns;
    double** matrix;
    int referenceCount;

    MatrixData(int);
    MatrixData(int, int);

    ~MatrixData();

    MatrixData* detach();
    void assign(unsigned int, unsigned int, const double**);
private:
    MatrixData(const MatrixData&);

    MatrixData& operator=(const MatrixData&);
};



class MatrixRef
{
private:
    friend class Matrix;

    Matrix& matrix;
    unsigned int row;
    unsigned int column;

    MatrixRef(Matrix&, unsigned int, unsigned int);
public:
    operator double() const;
    MatrixRef& operator=(double);
    MatrixRef& operator=(const MatrixRef);
};

#endif //MATRIX_MATRIX_H
