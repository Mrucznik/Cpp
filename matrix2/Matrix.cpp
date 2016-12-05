
#include "Matrix.h"

Matrix::Matrix(Matrix& m)
{
    m.matrix->referenceCount++;
    matrix = m.matrix;
}

Matrix::Matrix(int n)
{
    matrix = new MatrixData(n);
}

Matrix::Matrix(int r, int c)
{
    matrix = new MatrixData(r, c);
}

Matrix::~Matrix()
{
    if(--matrix->referenceCount == 0)
    {
        delete matrix;
    }
}

Matrix &Matrix::operator=(const Matrix &m)
{
    m.matrix->referenceCount++;
    if (--matrix->referenceCount == 0)
        delete matrix;
    matrix = m.matrix;
    return *this;
}

Matrix &Matrix::operator+=(const Matrix &m)
{
    if(matrix->rows == m.matrix->rows)
    {

    }
    if(matrix->columns == m.matrix->columns)
    {

    }
    for(int i=0; i<matrix->rows; i++)
    {
        for(int j=0; j<matrix->columns; j++)
        {
            write(i, j, read(i, j) + m.read(i, j));
        }
    }
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    if(matrix->rows == m.matrix->rows)
    {

    }
    if(matrix->columns == m.matrix->columns)
    {

    }
    for(int i=0; i<matrix->rows; i++)
    {
        for(int j=0; j<matrix->columns; j++)
        {
            write(i, j, read(i, j) - m.read(i, j));
        }
    }
}

Matrix &Matrix::operator*=(const Matrix &)
{
    return <#initializer#>;
}

Matrix Matrix::operator+(const Matrix &) const
{
    return Matrix(Matrix());
}

Matrix Matrix::operator-(const Matrix &) const
{
    return Matrix(Matrix());
}

Matrix Matrix::operator*(const Matrix &) const
{
    return Matrix(Matrix());
}

bool Matrix::operator==(const Matrix &) const
{
    return false;
}

bool Matrix::operator!=(const Matrix &) const
{
    return false;
}

double Matrix::operator[](unsigned int) const
{
    return 0;
}

MatrixRef Matrix::operator[](unsigned int)
{
    return MatrixRef(Matrix(), 0, 0);
}

std::basic_ostream<char, std::char_traits<char>> &operator<<(std::ostream &, const Matrix &)
{
    return <#initializer#>;
}

double Matrix::read(int, int) const
{
    return 0;
}

void Matrix::write(int, int, double)
{

}

void Matrix::load(std::istream)
{

}

MatrixData::MatrixData(int)
{

}

MatrixData::MatrixData(int, int)
{

}

MatrixData::~MatrixData()
{

}

MatrixData *MatrixData::detach()
{
    return nullptr;
}

void MatrixData::assign(unsigned int, unsigned int, const double **)
{

}

MatrixData::MatrixData(const MatrixData &)
{

}

MatrixData &MatrixData::operator=(const MatrixData &)
{
    return <#initializer#>;
}


MatrixRef::MatrixRef(Matrix &, unsigned int, unsigned int)
{

}

MatrixRef::operator double() const
{
    return 0;
}

MatrixRef &MatrixRef::operator=(double)
{
    return <#initializer#>;
}

MatrixRef &MatrixRef::operator=(const MatrixRef)
{
    return <#initializer#>;
}