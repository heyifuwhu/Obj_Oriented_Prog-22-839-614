//
//  Matrix.cpp
//  Matrix
//
//  Created by Jason Ha on 11/15/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "Matrix.hpp"

Matrix::Matrix(){
    m_rows = 3;
    m_columns = 3;
    vector<vector<double>> A{
        { 0.0, 0.0, 0.0},
        { 0.0, 0.0, 0.0},
        { 0.0, 0.0, 0.0},
    };
    m_data = A;
}

Matrix::Matrix(const vector<vector<double>>& data){
    m_data = data;
    m_rows = static_cast<int>(m_data.size());
    m_columns = static_cast<int>(m_data[0].size());
}

void Matrix::setPos(int row, int column, double elem){
    m_data[row][column] = elem;
}

Matrix::Matrix(int row){
    if(row <= 0){
        throw invalid_argument("Dimention should be greater than 0!\n");
    }
    m_rows = row;
    m_columns = row;
    vector<vector<double>> A(row,vector<double>(row,0.0));
    m_data = A;
}

Matrix::Matrix(int row, int column){
    if(row <=0 || column <=0){
        throw invalid_argument("Row and Column should be greater than 0!\n");
    }
    m_rows = row;
    m_columns = column;
    vector<vector<double>> A(row,vector<double>(column,0.0));
    m_data = A;
}

Matrix::Matrix(int row, int column, double value){
    m_rows = row;
    m_columns = column;
    vector<vector<double>> A(row,vector<double>(column,value));
//    m_data = vector<vector<double>>(row,vector<double>(column,value));
    m_data = A;
}

// copy constructor
Matrix::Matrix(const Matrix& mtx){
    m_columns = mtx.m_columns;
    m_rows = mtx.m_rows;
    m_data = mtx.m_data;
}

// assign operator
Matrix& Matrix::operator=(const Matrix& mtx){
    if(this != &mtx){
        m_columns = mtx.m_columns;
        m_rows = mtx.m_rows;
        m_data = mtx.m_data;
    }
    return *this;
}


double Matrix::getPos(int row, int column) const{
    return m_data[row][column];
}


Matrix Matrix::Transpose(){
    Matrix res(m_columns,m_rows,0.0);
    for(int i = 0 ; i < m_rows; i++){
        for(int j = 0; j < m_columns; j++){
            res.m_data[j][i] = m_data[i][j];
        }
    }
    return res;
}


void Matrix::elem_transformation(int i, int j){
    int temp;
    for(int k = 0; k < m_columns; k++){
        temp = m_data[i][k];
        m_data[i][k] = m_data[j][k];
        m_data[j][k] = temp;
    }
}

double Matrix::Determinant(){
    if(m_rows != m_columns){
        cout << "The matrix is not full rank matrix!" << endl;
        return 0.0;
    }else{
        Matrix M{*this}; // temporary matrix needs to be transformed to triangular matrix
        int n{m_rows};
        int ii,jj,k,u;
        int time = 0;  // record the times of elementary transformation in exchanging rows
        double res{1} , yin;
     
        for(ii=0 ; ii < n; ii++){
            if(M.m_data[ii][ii] == 0)
                
            for(jj=ii; jj<n; jj++)
            {
                if(M.m_data[jj][ii] != 0)
                {
                    M.elem_transformation(ii,jj);//交换两行
                    time++;
                }
            }
     
            for(k=ii+1; k<n; k++)
            {
              yin = -1 * M.m_data[k][ii] / M.m_data[ii][ii] ;
     
              for(u=0; u<n; u++)
              {
                  M.m_data[k][u] = M.m_data[k][u] + M.m_data[ii][u] * yin;
              }
            }
       }
      for(ii=0; ii<n; ii++)  // Calculate the determinant by the timing the diagonal elememt
          res = res * M.m_data[ii][ii];
      // if the exchange time is odd, the result should time -1
      if(time%2 == 1)
          res= -res;
       return (res);
    }
}

//-------------------------------- This is Wrong when rank is greater than 3!!!!!
//double Matrix::Determinant(){
//    if(m_rows != m_columns){
//        cout << "The matrix is not full rank matrix!" << endl;
//        return 0.0;
//    }else{
//        int n = m_rows;
//        int r, c, m;
//        int lop = 0;
//        double result = 0;
//        double mid = 1;
//        if (n != 1){
//            lop = (n == 2) ? 1 : n;   // if n == 2 , loop once; if n >2, loop n times
//
//            for (m = 0; m < lop; m++){
//                mid = 1;            // add the value when the reverse order number is even
//                for (r = 0, c = m; r < n; r++, c++){
//                    mid = mid * (m_data[r%n][c%n]);
//                }
//                result += mid;
//            }
//
//            for (m = 0; m < lop; m++){
//                mid = 1;            // subtract the value when the reverse order number is odd
//                for (r = 0, c = n-1-m+n; r < n; r++, c--){ // tricky part how to set the slicing index
//                    mid = mid * (m_data[r%n][c%n]);
//                }
//                result -= mid;
//            }
//        }else{
//            result = m_data[0][0];
//        }
//        return result;
//    }
//}
//-------------------------------------------------

double Matrix::getA(){
//    if(m_columns != m_rows){
//        throw invalid_argument("The matrix is not full rank matrix!\n");
//    }
    if(m_rows == 1){
        return m_data[0][0];
    }
    int n = m_rows;
    double res = 0.0;
    Matrix M(n-1,n-1,0.0);
    int i,j,k;
    // used for res = a[0][i] * |A(0,i)| for i: 0 -->> n-1
    for(i = 0; i < n; i++){
        // construct the Aij
        for(j = 0;j < n-1; j++){
            for(k = 0; k < n-1; k++){
                M.m_data[j][k] = m_data[j+1][( k>=i ) ? k+1 : k];
            }
        }
        double t = M.getA();
        if( i%2 == 0){
            res += m_data[0][i]*t;
        }else{
            res -= m_data[0][i]*t;
        }
    }
    return res;
}

Matrix Matrix::getAdjointMatrix(){
    Matrix res{m_rows,m_columns,1.0};
//        if(m_columns != m_rows){
//            throw invalid_argument("The matrix is not full rank matrix!\n");
//        }
    if(m_rows == 1){
        return res;
    }else{
        int n = m_rows;
        int i, j, k, t;
        Matrix M;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                for(k = 0; k < n-1; k++){
                    for(t = 0; t < n-1; t++){
                        M.m_data[k][t] = m_data[k >= i ? k+1 : k][t >= j ? t+1: t];
                    }
                }
                res.m_data[j][i] = M.getA();
                if((i+j) % 2 ==1){
                    res.m_data[j][i] = -res.m_data[j][i];
                }
            }
        }
        return res;
    }
}

Matrix Matrix::Inverse(){
    if(m_columns != m_rows){
        throw invalid_argument("Matix is not square! It has no inversed Matrix");
    }
    double determinant = getA();
    Matrix res;
    int n = m_rows;
    if(determinant == 0){
        throw invalid_argument("Matrix is singular! It has no inversed Matrix");
    }
    res = getAdjointMatrix();
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res.m_data[i][j] /= determinant;
        }
    }
    return res;
}

Matrix Matrix::Identity(){
    if(m_rows != m_columns){
        throw invalid_argument("The Matrix should be square!");
    }
    Matrix res(m_rows);
    for(int i =0; i < m_rows; i++){
        res.m_data[i][i] = 1;
    }
    return res;
}

// operator overloading
Matrix operator+(const Matrix& a,const Matrix& b){
    if(a.getCols() != b.getCols() || a.getRows() != b.getRows()){
        throw invalid_argument("Two Matrix have different dimention!\n");
    }
    vector<vector<double>> v2;
    for (int i = 0; i < a.getRows(); ++i) {
        vector<double> v1(0);
        for (int j = 0; j < a.getCols(); ++j) {
            v1.push_back(a.getPos(i, j) + b.getPos(i, j));
        }
        v2.push_back(v1);
    }
    Matrix c{v2};
    return c;
}


Matrix operator*(const Matrix& a, double b){
    vector<vector<double>> v2;
    for (int i = 0; i < a.getRows(); ++i) {
        vector<double> v1(0);
        for (int j = 0; j < a.getCols(); ++j) {
            v1.push_back(a.getPos(i, j) * b);
        }
        v2.push_back(v1);
    }
    Matrix c{v2};
    return c;
}

Matrix operator*(double b, const Matrix& a){
    vector<vector<double>> v2;
    for (int i = 0; i < a.getRows(); ++i) {
        vector<double> v1(0);
        for (int j = 0; j < a.getCols(); ++j) {
            v1.push_back(a.getPos(i, j) * b);
        }
        v2.push_back(v1);
    }
    Matrix c{v2};
    return c;
}



Matrix operator-(const Matrix& a,const Matrix& b){
    Matrix c = b * (-1);
    Matrix d = a + c;
    return d;
}

Matrix operator*(const Matrix& a, const Matrix& b){
    if(a.getCols() != b.getRows()){
        throw invalid_argument("Cannot perform multiplication in those two Matrix!\n");
    }
    vector<vector<double>> v1;
    for (int i = 0; i < a.getRows(); i++ ){
        vector<double> v2;
        for (int j = 0; j < b.getCols(); j++){
            double elem = 0.0;
            for(int k = 0; k < a.getCols(); k++){
                elem += (a.getPos(i, k) * b.getPos(k, j));
            }
            v2.push_back(elem);
        }
        v1.push_back(v2);
    }
    Matrix c{v1};
    return c;
}

ostream& operator<<(ostream& os,const Matrix& m){
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            os << m.getPos(i, j) << '\t';
        }
        if (i < m.getRows() - 1) {
            os << '\n';
        }
    }
    return os;
}

istream& operator>>(istream& is, Matrix& m){
    cout << "the Matrix is a " << m.getRows() << " * " << m.getCols() << " Matrix. " << endl;
    cout << "Input your matrix below:" << endl;
    double elem;
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            is >> elem;
            m.setPos(i, j,elem);
        }
    }
    return is;
}
