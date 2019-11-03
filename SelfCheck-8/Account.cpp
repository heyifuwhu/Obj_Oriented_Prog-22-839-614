//
//  Account.cpp
//  sf
//
//  Created by Jason Ha on 11/2/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "Account.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

Account::Account(double initialBalance)
:Balance(0.0){
    if(initialBalance >=0.0){
        Balance = initialBalance;
}
    else{
        throw invalid_argument("Initial Balance should be greater than 0.");
    }
}

void Account::credit(double amount){
    Balance =Balance + amount;
}

bool Account::debit(double amount){
    if (amount > Balance){
        cout << "Debit amount exceeded account balance." <<endl;
        return false;
    }else{
        Balance = Balance - amount;
        return true;
    }
}

void Account::setBalance(double newBalance){
    Balance = newBalance;
}

double Account::getBalance(){
    return Balance;
}
