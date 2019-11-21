//
//  Matrix.hpp
//  Matrix
//
//  Created by Jason Ha on 11/15/19.
//  Copyright © 2019 Jason He. All rights reserved.
/*  https://cloud.tencent.com/developer/article/1359605 for inversed matrix
    https://blog.csdn.net/zhurui_idea/article/details/24864155  This is Wrong!!! WTF!
    https://blog.csdn.net/XX_123_1_RJ/article/details/39267665  for  determinant
 */
#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Matrix{

private:
    vector<vector<double>> m_data;
    int m_rows;
    int m_columns;
    // used by determinant()
    void elem_transformation(int i, int j); // exchange the i-th row and j-th row;
    
public:
    
    // private mutator
//    void setRows(int row){m_rows = row;}
//    void setCols(int col){m_columns = col;}
    
public:
    // default constructor and constructor
    Matrix();
    Matrix(const vector<vector<double>>& data);
    Matrix(int row);
    Matrix(int row, int column);
    Matrix(int row, int column, double value);

    // Rule of Three: copy constructor, assign constructor, destructor
    Matrix(const Matrix& mtx);
    Matrix& operator=(const Matrix& mtx);
    ~Matrix(){}
    
    // accessor
    int getRows() const{return m_rows;}
    int getCols() const{return m_columns;}
    double getPos(int row, int column) const;
    
    //  mutator
    void setPos(int row, int column, double elem);
    
    // functions
    
    double Determinant(); // calculate |A| in elementary transformation way.
    // used by inverse()
    double getA(); // calculate |A| by sum(a[0][i] * A(0,i)) i from 0 to n-1.
    Matrix getAdjointMatrix(); // get the adjoint matrix
    
    Matrix Transpose(); // transpose the matrix
    Matrix Identity(); // get the identity matrix in the same dimension;
    Matrix Inverse(); // get the inverse matrix
    
};

ostream& operator<<(ostream& os, const Matrix& m);
istream& operator>>(istream& is, Matrix& m);
Matrix operator+(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, const Matrix& b);
Matrix operator*(const Matrix& a, double b);
Matrix operator*(double b, const Matrix& a);
Matrix operator-(const Matrix& a, const Matrix& b);

#endif /* Matrix_hpp */
