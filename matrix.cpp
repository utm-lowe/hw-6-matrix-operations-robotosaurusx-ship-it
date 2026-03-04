/**
 * @file matrix.cpp
 * @author Logan Jackson (ljacks83@skyhawks.utm.edu)
 * @brief Implementing the matrix.h
 * @version 0.1
 * @date 2026-03-03
 * 
 * @copyright Copyright (c) 2026
 * 
 */

 #include <iomanip>
 #include "matrix.h"
 using namespace std;

 //constructor
 Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols)
 {
    ar = new double*[m];
    for (int i = 0; i < m; i++)
    {
        ar[i] = new double[n](); //parenthesis set all values to zero
    }
 }

 //copy constructor
 Matrix::Matrix(const Matrix& rhs) : m(rhs.m), n(rhs.n)
 {
    ar = new double*[m];
    for (int i = 0; i < m; i++)
    {
        ar[i] = new double[n](); //parenthesis set all values to zero
    }

    for (int i = 0; i < m; i++)
    {
        for (int o = 0; o < n; o++)
        {
            ar[i][o] = rhs.ar[i][o];
        }
    }
 }

 //destructor
 Matrix::~Matrix()
 {
    for (int i = 0; i < m; i++)
    {
        delete[] ar[i];
    }
    delete[] ar;
 }

 //get rows
 int Matrix::getRows() const
 {
    return m;
 }

 //get cols
 int Matrix::getCols() const
 {
    return n;
 }

 //at
 double& Matrix::at(unsigned int row, unsigned int col)
 {
    return ar[row][col];
 } 
 
 //at const
 const double& Matrix::at(unsigned int row, unsigned int col) const
 {
    return ar[row][col];
 } 

 //overload =
 Matrix& Matrix::operator=(const Matrix& rhs)
 {
    //check if its the same
    if (this == &rhs) return *this;

    //destroy current matrix that has data
    for (int i = 0; i < m; i++)
    {
        delete[] ar[i];
    }
    delete[] ar;

    //rebuild the new one
    m = rhs.m;
    n = rhs.n;
    ar = new double*[m];
    for (int i = 0; i < m; i++)
    {
        ar[i] = new double[n];
    }

    //copy data to new
    for (int i = 0; i < m; i++)
    {
        for (int o = 0; o < n; o++)
        {
            ar[i][o] = rhs.ar[i][o];
        }
    }
    return *this;
 }

 //overload +
 Matrix operator+(const Matrix& m1, const Matrix& m2)
 {
    Matrix Result(m1.getRows(), m1.getCols());
    
    for (int i = 0; i < m1.getRows(); i++)
    {
        for (int o = 0; o < m1.getCols(); o++)
        {
            Result.at(i, o) = m1.at(i, o) + m2.at(i, o);
        }
    }

    return Result;
 }

 //overload -
 Matrix operator-(const Matrix& m1, const Matrix& m2)
 {
    Matrix result(m1.getRows(), m1.getCols());

    for (int i = 0; i < m1.getRows(); i++)
    {
        for (int j = 0; j < m1.getCols(); j++)
        {
            result.at(i, j) = m1.at(i, j) - m2.at(i, j);
        }
    }
    return result;
 }

 // matrix * matrix
 Matrix operator*(const Matrix& m1, const Matrix& m2)
 {
    Matrix result(m1.getRows(), m2.getCols());

    for (int i = 0; i < m1.getRows(); i++)
    {
        for (int j = 0; j < m2.getCols(); j++)
        {
            for (int k = 0; k < m1.getCols(); k++)
            {
                result.at(i, j) += m1.at(i, k) * m2.at(k, j);
            }
        }
    }
    return result;
 }

 // scalar * matrix
 Matrix operator*(double scalar, const Matrix& m)
 {
    Matrix result(m.getRows(), m.getCols());

    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            result.at(i, j) = scalar * m.at(i, j);
        }
    }
    return result;
 }

 // matrix * scalar (just flips and calls the one above)
 Matrix operator*(const Matrix& m, double scalar)
 {
    return scalar * m;
 }

 // output
 std::ostream& operator<<(std::ostream& os, const Matrix& m)
 {
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            os << std::setw(10) << m.at(i, j);
        }
        os << " \n";
    }
    return os;
 }

 // input
 std::istream& operator>>(std::istream& is, Matrix& m)
 {
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            is >> m.at(i, j);
        }
    }
    return is;
 }