//
//  CheckingAccount.hpp
//  sf
//
//  Created by Jason Ha on 11/2/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef CheckingAccount_hpp
#define CheckingAccount_hpp

#include <stdio.h>
#include "Account.hpp"

class CheckingAccount: public Account{
public:
    CheckingAccount(double,double);
    
    void credit();
    bool debit();
private:
    double Balance;
    double transactionFree;
    
};

#endif /* CheckingAccount_hpp */
