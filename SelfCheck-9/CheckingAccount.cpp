//
//  CheckingAccount.cpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "CheckingAccount.hpp"
using namespace std;

CheckingAccount::CheckingAccount(double initialBalance, double fee)
    :Account(initialBalance)
    ,transactionFee(0.0)
{
    if(fee >= 0.0){
        transactionFee = fee;
    }else{
        throw invalid_argument("Transaction fee must be >= 0.0");
    }
}

void CheckingAccount::credit(double amount){
    Account::credit(amount);
    chargeFee();
}
bool CheckingAccount::debit(double amount){
    return Account::debit(amount+transactionFee);
}

void CheckingAccount::chargeFee(){
    balance -= transactionFee;
}
