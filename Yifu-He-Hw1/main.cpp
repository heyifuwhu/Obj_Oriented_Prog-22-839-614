//
//  main.cpp
//  Practice
//
//  Created by Jason Ha on 9/7/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;


int main () {
    cout <<"Welcome to Yifu (Jason) He's future calculation system!"<<endl
    <<"=================================================="<<endl
    // remind user of the range of options
    <<"1.calculate the future value of s sum of money."<<endl
    <<"2.calculate future value of an ordinary annuity."<<endl
    <<"3.calculate future value of an annuity due."<<endl
    <<"4.quit.\n";
    
    string option; // the choose of user
    double principal, interest, period; // 3 input variables
    while(true){
        cout <<"Choose your next step:"<<endl;
        cin >> option;
        // determine further step according to user's option
        if(option == "1"){
            cout << "Input the original principal: ";
            // use a while loop to make sure the format of input variable
            while(cin>>principal){
                if (principal >=0){break;}
                else{
                    cout << "Wrong input: input value should be possitive!\n";
                    cout << "reinput the number again!\n";
                }
            }
            cout << "Input the interest rate: ";
            // Ditto
            while(cin>>interest){
                if (interest >=0){break;}
                else{
                    cout << "Wrong input: input value should be possitive!\n";
                    cout << "reinput the number again!\n";
                }
            }
            
            cout << "Input the time period: ";
            //Ditto
            while(cin>>period){
                if (period >=0){break;}
                else{
                    cout << "Wrong input: input value should be possitive!\n";
                    cout << "reinput the number again!\n";
                }
            }
        
            double result;
            // calculate the result and output it
            result = principal * pow((1 + interest),period);
            cout <<"future value: " << result<<endl;
            cout << "================================"<<endl;

            }else if(option == "2"){
                cout << "Input the annuity: ";
                //Ditto
                while(cin>>principal){
                    if (principal >=0){break;}
                    else{
                        cout << "Wrong input: input value should be possitive!\n";
                        cout << "reinput the number again!\n";
                    }
                }
                cout << "Input the interest rate: ";
                //Ditto
                while(cin>>interest){
                    if (interest >=0){break;}
                    else{
                        cout << "Wrong input: input value should be possitive!\n";
                        cout << "reinput the number again!\n";
                    }
                }
                
                cout << "Input the time period: ";
                //Ditto
                while(cin>>period){
                    if (period >=0){break;}
                    else{
                        cout << "Wrong input: input value should be possitive!\n";
                        cout << "reinput the number again!\n";
                    }
                }
                // calculate the result and output it
                double result;
                result = principal * (pow((1 + interest),period) - 1) / interest;
                cout <<"future value of an ordinary annuity: " << result<<endl;
                cout << "================================"<<endl;
            }
            else if(option =="3"){
                cout << "Input the annuity: ";
                //Ditto
                while(cin>>principal){
                    if (principal >=0){break;}
                    else{
                        cout << "Wrong input: input value should be possitive!\n";
                        cout << "reinput the number again!\n";
                    }
                }
                cout << "Input the interest rate: ";
                //Ditto
                while(cin>>interest){
                    if (interest >=0){break;}
                    else{
                        cout << "Wrong input: input value should be possitive!\n";
                        cout << "reinput the number again!\n";
                    }
                }
                cout << "Input the time period: ";
                //Ditto
                while(cin>>period){
                    if (period >=0){break;}
                    else{
                        cout << "Wrong input: input value should be possitive!\n";
                        cout << "reinput the number again!\n";
                    }
                }
                // calculate the result and output it
                double result;
                result = principal * (pow((1 + interest),period) - 1) / interest * (1 + interest);
                cout <<"future value of an annuity due: " << result<<endl;
            }
            // option 4 to quite
            else if(option =="4"){
                cout <<"======================================="<<endl;
                cout <<"Thank you to use Yifu (Jason) He's future calculation system!\n";
                // use return statement to terminate the function
                return 0;
            }
                // if the option if beyond the range of 1~4, remind user again
            else{
                cout <<"Wrong Option: please choose your option among 1~4."<<endl
                <<"1.calculate the future value of s sum of money."<<endl
                <<"2.calculate future value of an ordinary annuity."<<endl
                <<"3.calculate future value of an annuity due."<<endl
                <<"4.quit.\n";
            }
        }
    }

