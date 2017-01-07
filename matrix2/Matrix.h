//
// Created by Mrucznik on 04.12.2016.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>

//Exceptions
class NonEqualSizeMatrixException;
class CanNotBeMultipliedException;

class Matrix
{
private:
    MatrixData* matrix;

public:
    class MatrixRef;

    //konstruktory/dekonstruktory
    Matrix(Matrix&);
    Matrix(unsigned int);
    Matrix(unsigned int, unsigned int);

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

    double operator()(unsigned int, unsigned int) const;
    MatrixRef operator()(unsigned int, unsigned int);

    friend std::ostream &operator<<(std::ostream&, const Matrix&);

    //metody
private:
    bool isMatrixDimensionsAreEqual(const Matrix&);
    bool isMatrixDimensionsAreMultiplicable(const Matrix&);
public:
    double read(unsigned int, unsigned int) const;
    void write(unsigned int, unsigned int, double);
    void load(std::ifstream);


};


//----------------------------------------------------------
struct MatrixData
{
public:
    unsigned int rows;
    unsigned int columns;
    double** matrix;
    unsigned int referenceCount;

    MatrixData(unsigned int);
    MatrixData(unsigned int, unsigned int);
    MatrixData(unsigned int, unsigned int, const double);

    ~MatrixData();

    MatrixData* detach();
private:
    MatrixData();
    MatrixData(const MatrixData&);
    MatrixData& operator=(const MatrixData&);
};



//----------------------------------------------------------
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
