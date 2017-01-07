
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
    if(!isMatrixDimensionsAreEqual(m))
        throw NonEqualSizeMatrixException();

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
    if(!isMatrixDimensionsAreEqual(m))
        throw NonEqualSizeMatrixException();

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
    if(!isMatrixDimensionsAreMultiplicable(m))
        throw CanNotBeMultipliedException();

    if(--matrix->referenceCount == 0)
    {
        delete matrix;
    }
    auto result = new MatrixData(matrix->rows, m.matrix->columns);

    int n = matrix->columns;
    for (int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < m.matrix->columns; j++)
        {
            for(int r = 0; r < n; r++)
            {
                result->matrix[i][j] = read(i,r)*m.read(r,j);
            }
        }
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
    Matrix result(matrix->rows, m.matrix->columns);
    int n = matrix->columns;
    for (int i = 0; i < matrix->rows; i++)
    {
        for(int j = 0; j < m.matrix->columns; j++)
        {
            for(int r = 0; r < n; r++)
            {
                result.write(i,j, read(i,r)*m.read(r,j));
            }
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix &m) const
{
    for(int i=0; i<matrix->rows; i++)
    {
        for(int j=0; j<matrix->columns; j++)
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
    return matrix->matrix[i][j];
}

MatrixRef Matrix::operator()(unsigned int i, unsigned int j)
{
    return MatrixRef(*this, i, j);
}

std::basic_ostream<char, std::char_traits<char>> &operator<<(std::ostream &, const Matrix &)
{
    return <#initializer#>;
}

double Matrix::read(int i, int j) const
{
    return matrix->matrix[i][j];
}

void Matrix::write(int i, int j, double v)
{
    matrix->matrix[i][j] = v;
}

void Matrix::load(std::istream)
{

}

bool Matrix::isMatrixDimensionsAreEqual(const Matrix& m)
{
    return !(matrix->rows != m.matrix->rows || matrix->columns != m.matrix->columns);
}

bool Matrix::isMatrixDimensionsAreMultiplicable(const Matrix &m)
{
    return matrix->columns == m.matrix->rows;
}

//----------------------------------------------------------
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


//----------------------------------------------------------
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