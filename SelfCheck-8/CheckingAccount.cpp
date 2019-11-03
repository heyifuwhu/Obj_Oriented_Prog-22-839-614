//
//  CheckingAccount.cpp
//  sf
//
//  Created by Jason Ha on 11/2/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "CheckingAccount.hpp"
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(double initialBalance,double fee)
:Account(initialBalance)
,transactionFree(fee)
{
}
void CheckingAccount::credit(){
    Balance =Balance + transactionFree;
}
bool CheckingAccount::debit(){
    if (transactionFree > Balance){
        cout << "Debit amount exceeded account balance." <<endl;
        return false;
    }else{
        Balance = Balance - transactionFree;
        return true;
    }
}
