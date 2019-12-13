//
//  CheckingAccount.hpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef CheckingAccount_hpp
#define CheckingAccount_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Account.hpp"

class CheckingAccount : public Account{
public:
    CheckingAccount(double,double);
    
    virtual void credit(double);
    virtual bool debit(double);
private:
    double transactionFee;
    
    void chargeFee();
};
#endif /* CheckingAccount_hpp */
