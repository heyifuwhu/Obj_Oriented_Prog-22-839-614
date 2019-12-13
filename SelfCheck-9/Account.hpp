//
//  Account.hpp
//  sf9
//
//  Created by Jason Ha on 11/10/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
class Account{
public:
    Account(double);
    void credit(double);
    bool debit(double);
    void setBalance(double);
    double getBalance();
protected:
    double balance;
};


#endif /* Account_hpp */
