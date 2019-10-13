//
//  main.cpp
//  selfcheck5
//
//  Created by Jason Ha on 10/12/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
using namespace std;

//question 1
char* strcpy(char* des, const char* src);
//question 2
void swapFunc(int* a1, int* a2,int arrSize);


int main(int argc, const char * argv[]) {
    // Question1
    char greeting[30] = "hello,everybody";
    char echo[20] = "\0";
    cout << "Source greeting string is:  "<<greeting <<endl;
    cout << "Before copy, echo array is:  "<<echo <<endl;
    strcpy(echo, greeting);
    cout << "After copy, echo array is:  "<<echo <<endl;
    
    // question 2
    cout <<"---------------------------------"<<endl;
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {6,7,8,9,10};
    size_t arrSize{5};
    cout << "Original arr1: "<<endl;
    for(int i{0}; i <arrSize; i++){
        cout <<arr1[i]<<' ';
    }
    cout <<endl;
    cout << "Original arr2: "<<endl;
    for(int i{0}; i <arrSize; i++){
        cout <<arr2[i] << ' ';
    }
    cout <<endl;
    swapFunc(arr1, arr2, static_cast<int>(arrSize));
    cout << "After swaping arr1: "<<endl;
    for(int i{0}; i <arrSize; i++){
        cout <<arr1[i]<<' ';
    }
    cout <<endl;
    cout << "After swaping arr2: "<<endl;
    for(int i{0}; i <arrSize; i++){
        cout <<arr2[i]<<' ';
    }
    cout << endl;
    
    return 0;
}

char *strcpy(char* des, const char* src){
    int i;
    for (i =0;src[i] != '\0' ; i++){
        des[i] = src[i];
    }
    //des[i] = '\0';
    return des;
}

void swapFunc(int* a1, int* a2,int arrSize){

    int* temp = new int(0);
    for (int i = 0; i <arrSize;i++){
        *temp = *(a1+i);
        *(a1+i) = *(a2+i);
        *(a2+i) = *temp;
    }
}
