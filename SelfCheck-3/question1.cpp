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


int main () {
    int random,guess;
    char answer = 'y';
    while(answer == 'y'){
        srand(static_cast<int>(time(0)));
        random = (1+rand())%100;
        cout <<"Guess a number between 1 and 100: ";
        while(cin >> guess){
            if(guess == random){
                cout <<"Excellent!\nWould you like to play again?(y or n):";
                cin >>answer;
                break;
            }else if(guess < random){
                cout << "Too low.Try again: ";
            }else{
                cout << "Too high.Try again: ";
            }
        }
    }
    cout << "Have a nice day.\n";
    return 0;
}
