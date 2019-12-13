//
//  Account.cpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "Account.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

Account::Account(double initialBalance):balance(0.0){
    if(initialBalance >= 0.0){
        balance = initialBalance;
    }else{
        throw invalid_argument("Initial balance must be positive");
    }
}

void Account::credit(double amount){
    balance = balance + amount;
}

bool Account::debit(double amount){
    if(amount > balance){
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }else{
        balance = balance -amount;
        return true;
    }
}

void Account::setBalance(double newBalance){
    balance = newBalance;
}

double Account::getBalance(){
    return balance;
}
