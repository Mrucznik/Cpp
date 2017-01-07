//
// Created by Mrucznik on 04.12.2016.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include <cstring>

//------------Exceptions
class Exception
{
public:
    char* name;

    Exception(const char* name)
    {
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    };
};

class NonEqualSizeException : public  Exception
{
public:
    NonEqualSizeException() :  Exception("NonEqualSizeException") {};
};

class CanNotBeMultipliedException : public Exception
{
public:
    CanNotBeMultipliedException() : Exception("CanNotBeMultipliedException") {};
};

class OutOfRangeException : public Exception
{
public:
    OutOfRangeException() : Exception("OutOfRangeException") {};
};

//------------Declarations
class Matrix;
class MatrixData;
class MatrixRef;

//------------
class Matrix
{
private:
    MatrixData* matrix;

public:
    //konstruktory/dekonstruktory
    Matrix(const Matrix&);
    Matrix(unsigned int);
    Matrix(unsigned int, unsigned int);
    Matrix(std::ifstream& stream);

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
    bool isMatrixDimensionsAreEqual(const Matrix&) const;
    bool isMatrixDimensionsAreMultiplicable(const Matrix&) const;
public:
    double read(unsigned int, unsigned int) const;
    void write(unsigned int, unsigned int, double);
};


//----------------------------------------------------------
class MatrixData
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
    MatrixData(const MatrixData&);
    MatrixData& operator=(const MatrixData&);

    void Initialize();
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
