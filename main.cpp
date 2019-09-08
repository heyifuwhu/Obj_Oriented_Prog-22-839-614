//
//  main.cpp
//  Practice
//
//  Created by Jason Ha on 9/7/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
using namespace std;


class Invoice{
private:
    string partNumber; // the number of the part being sold
    string partDescription; // description of the part being sold
    int quantity; // how many of the items are being sold
    int pricePerItem; // price per item

public:
    //default constructor
    Invoice()
    {
    }
    
    //constructor
    Invoice(string number, string description,int count, int price){
        partNumber = number;
        partDescription = description;
        if (count >=0){quantity = count;}
        else{quantity = 0;}
        if(price >=0){pricePerItem = price;}
        else{pricePerItem=0;}
    }
    
    // menber function:
    void setPartNumber(string number){
        partNumber = number;
    }
    string getPartNumber(){
        return partNumber;
        
    }
    void setPartDescription(string description){
        partDescription=description;
        
    }
    string getPartDescription(){
        return partDescription;
        
    }
    void setQuantity(int count){
        if (count < 0){
            quantity = 0;
        }else{
            quantity = count;
        }
    }
        
    int getQuantity(){
        return quantity;
    }
    void setPricePerItem(int price){
        if (price <0){
            pricePerItem = 0;
        }else{
            pricePerItem = price;
        }
    }
    int getPricePerItem(){
        return pricePerItem;
    }
    
    // getInvoiceAmount()
    int getInvoiceAmount(){
        return quantity*pricePerItem;
    }
    
};


int main () {
    // Part III
    // Question 1
    cout << "Part III "<<endl<<"Question 1"<<endl;
    cout <<"Please enter your first name:\t";
    string name;
    cin >> name;
    cout <<"Hello, "<< name <<endl;
    
    
    // Question 2
    cout <<"=========================================";
    string fname;
    cout <<"Question 2"<<endl;
    cout <<"Please enter your full name:\t";
    cin.ignore();
    getline(cin,fname);
    cout <<"Hello, "<<fname  << endl;
    
    // Question 3
    cout <<"=========================================";
    cout << "For question 3, please look at the defination of class Invoice." << endl;
    
        return 0; }
