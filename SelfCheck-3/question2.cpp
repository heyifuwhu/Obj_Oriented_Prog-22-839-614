//
//  main.cpp
//  Practice
//
//  Created by Jason Ha on 9/7/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int ackermann(int m, int n){
    if(m == 0) return n+1;
    if(n==0) return ackermann(m-1, 1);
    return ackermann(m-1, ackermann(m, n-1));
}

int main () {
    for (int i=0; i <= 3;i++){
        for (int j=0;j <= 12;j++){
            cout <<"ackermann("<<i<<","<<j<<"):" <<ackermann(i, j)<<endl;
        }
    }
}
