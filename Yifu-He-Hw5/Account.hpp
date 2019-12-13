//
//  Account.hpp
//  hw5
//
//  Created by Jason Ha on 11/18/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


class Account{

protected:
    // account number
    static int num;
    int count;
    string owner;
    double amount;

public:
    // default constructor
    //Account(){}
    // constructor
    Account(string owner_, double amount_)
    : owner(owner_)
    , amount(amount_)
    , count(num){
        num++;
        cout << "Your account number is " << count << endl;
        cout << endl;
    }
    //Destructor
    virtual ~Account(){}
    
    
    // accessor
    int getCount(){return count;}
    string getOwner(){return owner;}
    double getAmount(){return amount;}
    // mutator
    void setAmount(double money);
    virtual void setService(double value)=0;
    virtual void setThreshold(double value) = 0;
    // deposit and withdraw
    virtual void deposit(double money) = 0;
    virtual bool withdraw(double money) = 0;
    virtual void interest(double rate) = 0;
    
    
    // print
    virtual void print()=0;
};

class CheckingAccount:public Account{

public:
    CheckingAccount(string owner_, double amount_):Account(owner_,amount_){}
    virtual void deposit(double money);
    virtual bool withdraw(double money);
    virtual void interest(double rate);
    virtual void setService(double value){cout << "Checking acount has no service fee"<<endl;}
    virtual void setThreshold(double value){cout << "Checking acount has no minimal banlance"<<endl;}
    virtual void print(){
        cout << "Account number -- " << count << endl;
        cout << "Account holder -- " << owner << endl;
        cout << "Checking Account balance -- " << amount << endl;
    }
    virtual ~CheckingAccount(){}
};


class SavingAccount:public Account{

    
public:
    SavingAccount(string owner_, double amount_):Account(owner_,amount_){}
    virtual void deposit(double money);
    virtual bool withdraw(double money);
    virtual void interest(double rate);
    virtual void setService(double value){cout << "Saving acount has no service fee"<<endl;}
    virtual void setThreshold(double value){cout << "Saving acount has no minimal banlance"<<endl;}
    
    virtual void print(){
        cout << "Account number -- " << count << endl;
        cout << "Account holder -- " << owner << endl;
        cout << "Saving Account balance -- " << amount << endl;
    }
    virtual ~SavingAccount(){}
};


class StudentAccount:public Account{
    
public:
    double service;
    double threshold{0.0};
public:
    StudentAccount(string owner_, double amount_,double service_)
    :Account(owner_,amount_)
    ,service(service_){}
    
    
    //
    double getService(){return service;}
    virtual void deposit(double money);
    virtual bool withdraw(double money);
    virtual void setService(double value);
    virtual void interest(double rate);
    virtual void setThreshold(double value);
    
    virtual void print(){
        cout << "Account number -- " << count << endl;
        cout << "Account holder -- " << owner << endl;
        cout << "Student Account balance -- " << amount << endl;
    }
    virtual ~StudentAccount(){}
    
};
#endif /* Account_hpp */
