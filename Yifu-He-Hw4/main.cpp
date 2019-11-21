//
//  main.cpp
//  Matrix
//
//  Created by Jason Ha on 11/15/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include "Matrix.hpp"
using namespace std;

int main() try{
    Matrix M1;
    cout <<"M1: " << endl;
    cout << M1 << endl;
    cout << endl;
    
    Matrix M2(2);
    cout <<"M2(2): " << endl;
    cout << M2 << endl;
    cout << endl;
    
    Matrix M3(2,3);
    cout <<"M3(2,3): " << endl;
    cout << M3 << endl;
    cout << endl;
    
    cout << "M3.Transpose()" << endl;
    cout << M3.Transpose() << endl;
    cout << endl;
    
    vector<vector<double>> vec_A{
        { 1.0, 0.0, 0.0},
        { 0.0, 1.0, 0.0},
        { 0.0, 0.0, 1.0},
    };
    Matrix M4(3,3,1.0);
    cout <<"M4(3,3,1.0): " << endl;
    cout << M4 << endl;
    cout << endl;
    
    
    
    vector<vector<double>> vec_B{
        { 0.0, 0.0, 1.0},
        { 0.0, 1.0, 0.0},
        { 1.0, 0.0, 0.0}
    };
    Matrix M5(vec_B);
    cout <<"M5(vec_B): " << endl;
    cout << M5 << endl;
    cout << endl;
    
    cout << "M4 - M5:" << endl;
    cout << M4 - M5 << endl;
    cout << endl;
    
    cout << "M4 + M5:" << endl;
    cout << M4 + M5 << endl;
    cout << endl;
    
    cout << "M4 * 2: " <<endl;
    cout << M4 * 2 <<endl;
    cout << endl;
    
    cout << "2 * M4: " <<endl;
    cout << 2 * M4  <<endl;
    cout << endl;
    
    
    
    cout << "M4 * M5: " <<endl;
    cout << (M4 * M5)  <<endl;
    cout << endl;
    
    cout << "M4 * M4: " <<endl;
    cout << (M4 * M4)  <<endl;
    cout << endl;
    
    Matrix M6(M5);
    cout << "Matrix M6(M5); " << endl;
    cout << M6 << endl;
    cout << endl;
    
    M6 = M4;
    cout << "M6 = M4;" << endl;
    cout << M6 << endl;
    cout << endl;
    
    cout << "M4.getA()" << endl;
    //cout << M4.Determinant() << endl; // determinant still have some problem use the second one getA
    cout << M4.getA() << endl;
    cout << endl;
    
    cout << "M5.Determinant()" << endl;
    cout << M5.Determinant() << endl;
    cout << endl;
    
    vector<vector<double>> vec_C{
        { 1.0, 12.0, 10.0, -12.0},
        { 0.0, 1.0, 0.0, 12.0},
        { 0.0, 0.0, -1.0, 4.0},
        { 0.0, 0.0, 1.0, -3.0}
    };
    Matrix M7(vec_C);
    cout << "M7" <<endl;
    cout << M7 <<endl;
    cout << "M7.Determinant(): " << M7.Determinant()
    << "  ---- (calculate |A| in elementary transformation way.)" <<endl;
    cout << "M7.getA(): " << M7.getA()
    << "  ---- (calculate |A| by sum(a[0][i] * A(0,i)) i from 0 to n-1)" <<endl;
    cout << endl;
    cout << "M7.getAdjointMatrix():" << endl;
    cout << M7.getAdjointMatrix() << endl;
    cout << endl;
    cout << "(1/|M7|) * M7(adjoint) * M7: " << endl;
    cout << M7.getAdjointMatrix() * (1/M7.getA()) * M7 << endl;
    cout << endl;
    
    cout << "M7.Inverse():" << endl;
    cout << M7.Inverse() << endl;
    cout << endl;
    cout << "M7^(-1) * M7:" << endl;
    cout << M7 * M7.Inverse() <<endl;
    cout << endl;
    
    cout << "M7.Identity():" << endl;
    cout << M7.Identity() << endl;
    cout << endl;
    
    Matrix M8;
    cout << "Show operator >>:" << endl;
    cin >> M8;
    cout <<endl;

    cout << "Show operator <<, print the Matrix we just input" << endl;
    cout << M8;
    cout <<endl;
    
    // Error handling
//    cout << "M2 * M5: " <<endl;
//    cout << (M2 * M5)  <<endl;
//    cout << endl;
//    
//    cout << "M2 + M5:" << endl;
//    cout << M2 + M5 << endl;
//    cout << endl;
    
//    cout << "M3.Inverse()"<<endl;
//    cout << M3.Inverse()<<endl;
//    cout << endl;
    
//    cout << "M4.Inverse()"<<endl;
//    cout << M4.Inverse()<<endl;
//    cout << endl;
    
    return 0;
} catch (exception& e) {
    cerr << "Error: " << e.what() << "\n";
    return 1;
} catch (...) {
    cerr << "Error: Exception\n";
    return 2;
}
