#include <fstream>
#include "Matrix.h"

Matrix::Matrix(const Matrix& m)
{
    m.matrix->referenceCount++;
    matrix = m.matrix;
}

Matrix::Matrix(unsigned int n)
{
    matrix = new MatrixData(n);
}

Matrix::Matrix(unsigned int r, unsigned int c)
{
    matrix = new MatrixData(r, c);
}

Matrix::Matrix(std::ifstream& stream)
{
    unsigned int rows, columns;
    stream >> rows;
    stream >> columns;

    matrix = new MatrixData(rows, columns);
    for (int i = 0; i < matrix->rows; ++i)
    {
        for (int j = 0; j < matrix->columns; ++j)
        {
            stream >> matrix->matrix[i][j];
        }
    }
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
    if(!isMatrixDimensionsAreEqual(m))
        throw NonEqualSizeException();

    for(unsigned int i=0; i<matrix->rows; i++)
    {
        for(unsigned int j=0; j<matrix->columns; j++)
        {
            write(i, j, read(i, j) + m.read(i, j));
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &m)
{
    if(!isMatrixDimensionsAreEqual(m))
        throw NonEqualSizeException();

    for(unsigned int i=0; i<matrix->rows; i++)
    {
        for(unsigned int j=0; j<matrix->columns; j++)
        {
            write(i, j, read(i, j) - m.read(i, j));
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &m)
{
    if(!isMatrixDimensionsAreMultiplicable(m))
        throw CanNotBeMultipliedException();

    unsigned int rows = matrix->rows, columns = m.matrix->columns;

    auto result = new MatrixData(rows, columns, 0);

    int n = rows;
    for (unsigned int i = 0; i < rows; i++)
    {
        for(unsigned int j = 0; j < columns; j++)
        {
            for(unsigned int r = 0; r < n; r++)
            {
                result->matrix[i][j] += read(i,r)*m.read(r,j);
            }
        }
    }
    if(--matrix->referenceCount == 0)
    {
        delete matrix;
    }
    matrix = result;
    return *this;
}

Matrix Matrix::operator+(const Matrix &m) const
{
    Matrix result(*this);
    result += m;
    return result;
}

Matrix Matrix::operator-(const Matrix &m) const
{
    Matrix result(*this);
    result -= m;
    return result;
}

Matrix Matrix::operator*(const Matrix &m) const
{
    if(!isMatrixDimensionsAreMultiplicable(m))
        throw CanNotBeMultipliedException();

    Matrix result(matrix->rows, m.matrix->columns);
    int n = matrix->columns;
    for (unsigned int i = 0; i < matrix->rows; i++)
    {
        for(unsigned int j = 0; j < m.matrix->columns; j++)
        {
            for(unsigned int r = 0; r < n; r++)
            {
                result.write(i,j, result.read(i,j) + read(i,r)*m.read(r,j));
            }
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix &m) const
{
    if(!isMatrixDimensionsAreEqual(m))
        return false;

    for(unsigned int i=0; i<matrix->rows; i++)
    {
        for(unsigned int j=0; j<matrix->columns; j++)
        {
            if(read(i, j) != m.read(i, j))
            {
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

double Matrix::operator()(unsigned int i, unsigned int j) const
{
    return read(i, j);
}

MatrixRef Matrix::operator()(unsigned int i, unsigned int j)
{
    return MatrixRef(*this, i, j);
}

std::basic_ostream<char, std::char_traits<char>> &operator<<(std::ostream &stream, const Matrix &m)
{
    stream << "Matrix (" << m.matrix->rows << ", " << m.matrix->columns << "):\n";
    for (unsigned int i = 0; i < m.matrix->rows; ++i)
    {
        stream << "| ";
        for (unsigned int j = 0; j < m.matrix->columns; ++j)
        {
            stream << m.read(i, j) << ((j==m.matrix->columns-1)?" ":"\t");
        }
        stream << "|\n";
    }
    return stream;
}

double Matrix::read(unsigned int i, unsigned int j) const
{
    if(i < 0 || i >= matrix->rows || j < 0 || j >= matrix->columns)
        throw OutOfRangeException();

    return matrix->matrix[i][j];
}

void Matrix::write(unsigned int i, unsigned int j, double v)
{
    if(i < 0 || i >= matrix->rows || j < 0 || j >= matrix->columns)
        throw OutOfRangeException();

    matrix = matrix->detach();
    matrix->matrix[i][j] = v;
}

bool Matrix::isMatrixDimensionsAreEqual(const Matrix& m) const
{
    return !(matrix->rows != m.matrix->rows || matrix->columns != m.matrix->columns);
}

bool Matrix::isMatrixDimensionsAreMultiplicable(const Matrix &m) const
{
    return matrix->columns == m.matrix->rows;
}

//------------------------------MatrixData----------------------------
void MatrixData::Initialize()
{
    referenceCount = 1;

    matrix = new double*[rows];
    for (unsigned int i = 0; i < rows; ++i)
    {
        matrix[i] = new double[columns];
    }
}

MatrixData::MatrixData(unsigned int n) :
    rows(n), columns(n)
{
    Initialize();
}

MatrixData::MatrixData(unsigned int n, unsigned int m) :
    rows(n), columns(m)
{
    Initialize();
}

MatrixData::MatrixData(unsigned int n, unsigned int m, const double value) :
        rows(n), columns(m)
{
    Initialize();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = value;
        }
    }
}

MatrixData::~MatrixData()
{
    for (unsigned int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

MatrixData *MatrixData::detach()
{
    if (referenceCount == 1)
        return this;
    MatrixData *data = new MatrixData(rows, columns);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            data->matrix[i][j] = matrix[i][j];
        }
    }
    referenceCount--;
    return data;
}

//--------------------------MatrixRef--------------------------------
MatrixRef::MatrixRef(Matrix &m, unsigned int i, unsigned int j) :
    matrix(m), row(i), column(j)
{
}

MatrixRef::operator double() const
{
    return matrix.read(row, column);
}

MatrixRef &MatrixRef::operator=(double value)
{
    matrix.write(row, column, value);
    return *this;
}

MatrixRef &MatrixRef::operator=(const MatrixRef m)
{
    return operator=((double)m);
}