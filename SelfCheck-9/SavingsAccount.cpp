//
//  SavingsAccount.cpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "SavingsAccount.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

SavingsAccount:: SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance){
        if(rate < 0.0){
            throw invalid_argument("Interest rate must be >= 0.0");
        }
        interestRate = rate;
}

double SavingsAccount::calculateInterest(){
    return getBalance() * interestRate;
}
