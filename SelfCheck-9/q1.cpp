//
//  q1.cpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "q1.hpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include "Account.hpp"
#include "SavingsAccount.hpp"
#include "CheckingAccount.hpp"
using namespace std;

int main(){
    vector<Account *> accounts(4);
    accounts[0] = new SavingsAccount(100.0,.05);
    accounts[1] = new CheckingAccount(100.0, 1.0);
    accounts[2] = new SavingsAccount{200.0,.10};
    accounts[3] = new CheckingAccount{300.0, 2.0};
    cout << fixed << setprecision(2);
    for(size_t i{0}; i < accounts.size(); ++i){
        cout << "Account " << i+1 << " balance: $" << accounts[i] -> getBalance();
        double withdrawalAmount(0.0);
        cout <<"\nEnter an amount to withdraw from Account "<< i +1 <<": ";
    }
}
