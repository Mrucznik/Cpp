
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
    checkDimensionsEquality(m);
    for(int i=0; i<matrix->rows; i++)
    {
        for(int j=0; j<matrix->columns; j++)
        {
            write(i, j, read(i, j) + m.read(i, j));
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    checkDimensionsEquality(m);
    for(int i=0; i<matrix->rows; i++)
    {
        for(int j=0; j<matrix->columns; j++)
        {
            write(i, j, read(i, j) - m.read(i, j));
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &m)
{
    Matrix ret(*this*m);
    *this = ret;
    return *this;
}

Matrix Matrix::operator+(const Matrix &m) const
{
    checkDimensionsEquality(m);
    return Matrix(*this)+=m;
}

Matrix Matrix::operator-(const Matrix &m) const
{
    checkDimensionsEquality(m);
    return Matrix(*this)-=m;
}

Matrix Matrix::operator*(const Matrix &m) const
{
    if(matrix->columns != m.matrix->rows)
    {
        throw NonEqualDimensionsException();
    }
    Matrix ret(matrix->rows*m.matrix->columns);

    for(int i=0; i < matrix->rows; i++)
    {
        for(int j=0; j < m.matrix->columns; j++)
        {
            for(int r=0; r < matrix->columns > r; r++)
            {
                ret.write(i, j, ret.read(i, j) + read(i, r)*read(r, j));
            }
        }
    }
    return ret;
}

bool Matrix::operator==(const Matrix &m) const
{
    if(matrix->rows == m.matrix->rows && matrix->columns == m.matrix->columns)
    {
        for(int i=0; i<matrix->rows; i++)
        {
            for(int j=0; j<matrix->columns; j++)
            {
                if(read(i, j) != m.read(i, j))
                    return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &m) const
{
    return !(*this==m);
}

double* Matrix::operator[](unsigned int i) const
{
    return matrix->matrix[i];
}

MatrixRef Matrix::operator[](unsigned int i)
{

}

std::basic_ostream<char, std::char_traits<char>> &operator<<(std::ostream &, const Matrix &)
{
    return <#initializer#>;
}

double Matrix::read(int r, int c) const
{
    return matrix->matrix[r][c];
}

void Matrix::write(int r, int c, double value)
{
    matrix->matrix[r][c] = value;
}

void Matrix::load(std::istream)
{

}

bool Matrix::checkDimensionsEquality(const Matrix &m) const
{
    if(matrix->rows != m.matrix->rows || matrix->columns != m.matrix->columns)
    {
        throw NonEqualDimensionsException();
    }
    return true;
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