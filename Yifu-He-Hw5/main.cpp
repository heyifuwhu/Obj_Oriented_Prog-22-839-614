//
//  main.cpp
//  hw5
//
//  Created by Jason Ha on 11/18/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include "Account.hpp"
#include <vector>
using namespace std;

int main() try{
    //SavingAccount a("Yifu",123);
    char option ; // option to be inputed by users
    int account; // account number
    double amount; // amount of money used through input
    char type; // type of account
    vector<Account*> accounts;
    vector<bool> states;
    Account* temp;
    while(1){
        cout << "Choose an Option"<<endl;
        cout << "\t1.Transactoin" <<endl;
        cout << "\t2.Creat New Account"<<endl;
        cout << "\t3.Delete Account"<<endl;
        cout << "\t4.Print All"<<endl;
        cout << "\t5.Exit"<<endl;
        cout << "\t6.Set the minimal balance for all student account"<<endl;
        cout << "\t7.Set the service fee for specific student acoount" << endl;
        cout << endl;
        cout << "Enter your choice -->>  ";
        cin >> option;
        cin.ignore(1024,'\n');
        if(option == '1')
        {
        if (accounts.size() == 0){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        bool empty = true;
        for(int i =0; i < states.size();i++){
        if(states[i]){
        empty = false;
        break;
        }
        }
        if(empty){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        cout << "In Transaction...."<<endl;
        cout << endl;
        while(1){
        cout <<endl;
        cout <<"Choose an Option"<<endl;
        cout <<"\t1.Deposit"<<endl;
        cout <<"\t2.Withdraw"<<endl;
        cout <<"\t3.Transfer from Checking to Saving"<<endl;
        cout <<"\t4.Transfer from Saving to Checking"<<endl;
        cout <<"\t5.Back to Main Menu"<<endl;
        cout <<"\t6.Calculate and add interest"<<endl;
        cout << endl;
        cout << "Enter your choice -->>  ";
        cin >> option;
        cin.ignore(1024,'\n');
        // deposite
        if(option == '1'){
        while(1){
        //cout << accounts.size();
        cout <<"Enter Account Number: ";
        cin >> account;
        if( (account <0) or (account+1 > accounts.size()) or !states[account]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        while(1){
        cout << "Enter Deposit Amount: ";
        cin >> amount;
        if(amount <0.0){
        cout << "Invalid value: Amount cannot be negtive! Input again!"<< endl;
        }else{
        break;
        }
        }
        accounts[account]->deposit(amount);
        // withdraw
        }else if(option == '2'){
        while(1){
        //cout << accounts.size();
        cout <<"Enter Account Number: ";
        cin >> account;
        if( (account <0) or (account+1 > accounts.size()) or !states[account]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        while(1){
        cout << "Enter Withdraw Amount: ";
        cin >> amount;
        if(amount <0.0){
        cout << "Invalid value: Amount cannot be negtive! Input again!"<< endl;
        }else{
        break;
        }
        }
        // (*accounts[account]).withdraw(amount);
        accounts[account]->withdraw(amount);
        // transfer
        }else if(option == '3'){
        
        int account1,account2;
        // C ---> S
        while(1){
        cout <<"Enter Checking account number: ";
        cin >> account1;
        if( (account1 <0) or (account1 +1 > accounts.size()) or !states[account1]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        
        }
        while(1){
        cout <<"Enter Saving account number: ";
        cin >> account2;
        if( (account2 <0) or (account2 +1 > accounts.size()) or !states[account2]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        
        while(1){
        cout<<"Enter transfer amount: ";
        cin >> amount;
        if(amount<0.0){
        cout << "Invalid value: Amount cannot be negtive! Input again!"<< endl;
        }else{
        break;
        }
        }
        
        if( accounts[account1]->withdraw(amount) ){
        accounts[account2]->deposit(amount);
        }else{
        cout << "Fail to transaction!"<<endl;
        }
        
        
        
        }else if(option == '4'){
        int account1,account2;
        // S ---> C
        while(1){
        cout <<"Enter Saving account number: ";
        cin >> account1;
        if( (account1 <0) or (account1 +1 > accounts.size()) or !states[account1]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        
        }
        while(1){
        cout <<"Enter Checking account number: ";
        cin >> account2;
        if( (account2 <0) or (account2 +1 > accounts.size()) or !states[account2]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        
        while(1){
        cout<<"Enter transfer amount: ";
        cin >> amount;
        if(amount<0.0){
        cout << "Invalid value: Amount cannot be negtive! Input again!"<< endl;
        }else{
        break;
        }
        }
        
        if( accounts[account1]->withdraw(amount) ){
        accounts[account2]->deposit(amount);
        }else{
        cout << "Fail to transacti"<<endl;
        }
        
        }else if(option == '5'){
        break;
        }else if(option =='6'){
        while(1){
        //cout << accounts.size();
        cout <<"Enter Account Number: ";
        cin >> account;
        if( (account <0) or (account+1 > accounts.size()) or !states[account]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        while(1){
        cout << "Enter intetest rate: ";
        cin >> amount;
        if(amount <0.0){
        cout << "Invalid value: Amount cannot be negtive! Input again!"<< endl;
        }else{
        break;
        }
        }
        accounts[account]->interest(amount);
        }else{
        cout <<"Wrong Choice: Choice should be between 1~5." << endl;
        }
        }
        
        }else if(option == '2'){
        cout << "Creating Account...." << endl;
        string name="";
        // extra credit
        // name cannot be null
        cout << "Please enter owner name: ";
        cin >> name;
        cin.ignore(1024,'\n');

        // extra credit
        // amount cannot be negative
        while(1){
        cout << "Initial amount: ";
        cin >> amount;
        cin.ignore(1024,'\n');
        if(amount < 0.0){
        cout << "Invalid value: Amount cannot be negtive! Input again!"<< endl;
        }else{
        break;
        }
        }
        // extra credit
        // type should not be out of range
        while(1){
        cout <<"Type of Account c(checking), s(saving), p(pupil): ";
        cin >> type;
        cin.ignore(1024,'\n');
        if((type !='s') && (type!='c') && (type != 'p')){
        cout << "Invalid value: No such account type! Input again!" << endl;
        }else{
        break;
        }
        }
        if(type == 's'){
        temp= new SavingAccount(name, amount);
        }else if(type == 'c'){
        temp = new CheckingAccount(name,amount);
        }else{
        double service;
        while(1){
        cout << "Service Fee for student account: ";
        cin >> service;
        if(service < 0.0){
        cout << "Invalid value: No such account type! Input again!" << endl;
        }else{
        break;
        }
        }
        temp= new StudentAccount(name, amount, service);
        }
        accounts.push_back(temp);
        states.push_back(true);
        }else if(option == '3'){
        // check whether system is empty
        if (accounts.size() == 0){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        bool empty = true;
        for(int i =0; i < states.size();i++){
        if(states[i]){
        empty = false;
        break;
        }
        }
        if(empty){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        
        
        
        cout << "Delete Account"<<endl;
        cout << "Please enter your account number: "<<endl;
        cin >> account;
        if (account<0 or (account+1 > accounts.size()) or !states[account]){
        cout << "No such an account, " << account <<endl;
        }else{
        delete accounts[account];
        states[account] = false;
        }
        }else if(option == '4'){
        // check whether system are empty
        if (accounts.size() == 0){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        bool empty = true;
        for(int i =0; i < states.size();i++){
        if(states[i]){
        empty = false;
        break;
        }
        }
        if(empty){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        
        
        cout << "Print all account"<<endl;
        cout << endl;
        for(int i =0; i < states.size();i++){
        if(states[i]){
        accounts[i]->print();
        cout << endl;
        }
        }
        
        }else if(option == '5'){
        cout << "Bye!"<<endl;
        break;
        }else if(option == '6'){
        
        // check whether system is empty
        if (accounts.size() == 0){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        bool empty = true;
        for(int i =0; i < states.size();i++){
        if(states[i]){
        empty = false;
        break;
        }
        }
        if(empty){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        
        
        
        // set the threshold for student account
        cout << "Setting...." << endl;
        cout << endl;
        while(1){
        //cout << accounts.size();
        cout <<"Enter Account Number: ";
        cin >> account;
        if( (account <0) or (account+1 > accounts.size()) or !states[account]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        
        
        while(1){
        double value;
        cout << "Enter the new threshold: ";
        cin >> value;
        if (value < 0.0){
        cout << "Threshold cannot be negative! Re-enter it" << endl;
        }else{
        accounts[account]->setThreshold(value);
        break;
        }
        }
        
        }else if(option == '7'){
        
        // check whether system is empty
        if (accounts.size() == 0){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        bool empty = true;
        for(int i =0; i < states.size();i++){
        if(states[i]){
        empty = false;
        break;
        }
        }
        if(empty){
        cout << "There is no account in the system!" << endl;
        cout << endl;
        continue;
        }
        
        
        
        while(1){
        //cout << accounts.size();
        cout <<"Enter Account Number: ";
        cin >> account;
        if( (account <0) or (account+1 > accounts.size()) or !states[account]){
        cout << "No such a account number! Re-enter the Acount Number"<<endl;
        }else{
        break;
        }
        }
        
        while(1){
        double value;
        cout <<"Enter the Service Fee: ";
        cin >> value;
        if(value<0.0){
        cout<<"Invalid value: No such account type! Input again!" << endl;
        }else{
        accounts[account]->setService(value);
        break;
        }
        }
        
        
        }else{
        // extra credit
        // option cannot be out of range
        cout <<"Wrong Choice: Choice should be between 1~7.\n" << endl;
    
        }
        }
        return 0;
        }catch (exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
        } catch (...) {
        cerr << "Error: Exception\n";
        return 2;
        }

