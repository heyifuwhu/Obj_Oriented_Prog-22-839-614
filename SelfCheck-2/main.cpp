//
//  main.cpp
//  Practice
//
//  Created by Jason Ha on 9/13/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
using namespace std;

int main () {
    // Question 1
    int choice = 0;
    while (choice <1 || choice >3){
        cout << "Please enter your choice (1, or 2 or 3) :";
        cin >> choice;
    }
    cout << "Your choice " << choice <<", Goodbye!\n\n";
    
    // Question 2
    unsigned int count;
    int res,temp;
    cout <<"Enter the number of integars to be processed: ";
    cin >> count;
    cout <<"Enter all the integars: ";
    cin >> res;
    count--;
    while(count >0){
        cin >> temp;
        res = res < temp ? res : temp;
        count--;
    }
    
    cout << "\n"<< "The smallest integar is : " << res <<endl;
    
    // Question 3
    return 0;
    
}
