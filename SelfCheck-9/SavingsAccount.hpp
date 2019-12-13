//
//  SavingsAccount.hpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Account.hpp"

class SavingsAccount : public Account{
public:
    SavingsAccount(double,double);
    
    double calculateInterest();
private:
    double interestRate;
};
#endif /* SavingsAccount_hpp */
