//
//  main.cpp
//  sf10
//
//  Created by Jason Ha on 11/29/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
template<class T>
bool test(const vector<T> vec){
    auto r{vec.crbegin()};
    auto i{vec.cbegin()};
    while(r != vec.crend() && i != vec.cend()){
        if(*r != *i){
            return false;
        }
        r++;
        i++;
    }
    return true;
}

template<class T>
void printVec(const vector<T> vec){
    if(vec.empty()){
        cout << "vector is empty" << endl;
    }else{
        ostream_iterator<T> output{cout, " "};
        copy(vec.cbegin(),vec.cend(),output);
    }
    
    
}
int main(){
    vector<int> iv;
    vector<int> ic;
    int x{0};
    for(int i = 75; i >= 65; i--){
        iv.push_back(i);
        ic.push_back(i+x);
        if(i <=70){
            x+=2;
        }
    }
    printVec(iv);
    cout << endl;
    printVec(ic);
    cout << endl;
    cout << test(iv) << endl;
    cout << test(ic) << endl;
    return 0;
}
