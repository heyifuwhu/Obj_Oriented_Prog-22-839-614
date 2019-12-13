//
//  Account.cpp
//  hw5
//
//  Created by Jason Ha on 11/18/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "Account.hpp"

int Account::num = 0;



//Account::Account(){
//    count++;
//}

void Account::setAmount(double money){
    if (money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else{
        amount = money;
    }
}


void SavingAccount::deposit(double money){
    if(money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else{
        amount += money;
        cout << "\tcredit to account:\t"<< money << endl;
        cout << "Saving account Balance:\t"<<amount<<endl;
    }
}

bool SavingAccount::withdraw(double money){
    if(money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }
    if (money > amount){
        cout << "Debit amount exceeded account balance." <<endl;
        return false;
    }else{
        amount = amount - money;
        cout << "\tdebit to account:\t"<< money << endl;
        cout << "Saving account Balance:\t"<< amount<<endl;
        return true;
    }
}

void SavingAccount::interest(double rate){
    amount *=(1+rate);
    cout << "interest rate is "<< rate*100<<"%" <<endl;
    cout << "Saving account banlance:\t" << amount <<endl;
}


void CheckingAccount::deposit(double money){
    if(money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else{
        amount += money;
        cout << "\tcredit to account:\t"<<money << endl;
        cout << "Checking account Balance:\t"<<amount<<endl;
    }
}

bool CheckingAccount::withdraw(double money){
    if(money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else if (money > amount){
        cout << "Debit amount exceeded account balance." <<endl;
        return false;
    }else{
        amount = amount - money;
        cout << "\tdebit to account:\t"<< money << endl;
        cout << "Checking account Balance:\t"<< amount<<endl;
        return true;
    }
}

void CheckingAccount::interest(double rate){
    amount *=(1+rate);
    cout << "interest rate is "<< rate*100<<"%"<<endl;
    cout << "Checking account banlance:\t" << amount << endl;
    
}

void StudentAccount::deposit(double money){
    if(money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else{
        amount += money;
        cout << "\tcredit to account:\t"<<money << endl;
        cout << "Student account Balance:\t"<<amount<<endl;
    }
}

bool StudentAccount::withdraw(double money){
    if(money < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else if (money > amount){
        cout << "Debit amount exceeded account balance." << endl;
        return false;
    }else{
        amount = amount - money;
        if(amount >= threshold){
            cout << "\tdebit to account\t" << money << endl;
            cout << "\tbalance is greater than the minimal threshold ("<<threshold<<")"<< endl;
            cout << "Student account balance:\t" << amount << endl;
            return true;
        }else{
            if(amount >= service){
                amount -= service;
                cout << "\tdebit to account\t" << money << endl;
                cout << "\tbalance is less than the minimal threshold ("<<threshold<<")"<< endl;
                cout << "\tcharge service fee\t"<< service << endl;
                cout << "Student account balance:\t" << amount << endl;
                return true;
            }else{
                cout << "Not enouth money (" << amount
                <<") in balance to pay for the service fee ("<<service<<")"<<endl;
                amount += money;
                cout << "Cannot make this transaction"<<endl;
                cout << "Student account balance:\t" << amount << endl;
                return false;
            }
        }
    }
}

void StudentAccount::interest(double rate){
    cout << "Student account has no interest"<<endl;
}

void StudentAccount::setService(double value){
    if (value < 0.0){
        throw invalid_argument("Error: Amount cannot smaller than 0\n");
    }else{
        service = value;
    }
}
void StudentAccount::setThreshold(double value){
    if(value < 0.0){
        throw  invalid_argument("Error: Amount cannot smaller than 0\n");
    }else{
        threshold = value;
    }
}
