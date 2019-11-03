//
//  Account.hpp
//  sf
//
//  Created by Jason Ha on 11/2/19.
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
    double Balance;
};
#endif /* Account_hpp */
