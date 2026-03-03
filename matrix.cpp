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

 Matrix::Matrix(unsigned int rows, unsigned int cols) : m(rows), n(cols)
 {
    ar = new double*[m];
    for (int i = 0; i < m; i++)
    {
        ar[i] = new double[n](); //parenthesis set all values to zero
    }
 }

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
            ar[m][n] = rhs.ar[m][n];
        }
    }
 }