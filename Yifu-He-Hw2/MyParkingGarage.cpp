//
//  MyParkingGarage.cpp
//  C++
//
//  Created by Jason Ha on 9/27/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Car.hpp"
using namespace std;

// print the cars in the garage
void printInfo(vector<Car> &carlist,TimeCovert &sys_time);
// add a car in the garage
void addCar(vector<Car> &carlist,double &Time_stay);

// advance 30 minutes
void advanceTime(vector<Car> &carlist,TimeCovert &sys_time);
// search
void uni_search(vector<Car> &carlist);

// bonus
void and_search(vector<Car> &carlist);
void or_search(vector<Car> &carlist);


int main(){
    // welcome and instructions IO
    cout <<"Welcome to Rugters garage system!\n"<<endl;
    
    vector<Car> carlist; // car list
    TimeCovert sys_time(6.0); // // simulation of time
    double Time_stay; // time of cars stay in the garage
    int option; // option to choose
    
    // generate tm_stay ~ N(5.0,2.0)
    default_random_engine generator{static_cast<unsigned int>(10442277)}; // set seed
    normal_distribution<double> distribution(5.0,2.0); // define the distribution
    
    while(sys_time.get_time()<24){
        // instruction for IO
        cout<<"\nInstructions:\n"
        <<"--------------------------------------------------------\n"
        <<"option 1 : Printout all cars’ information in the garage.\n"
        <<"option 2 : Allow a car to enter.\n"
        <<"option 3 : Advance time by 30 minutes.\n"
        <<"option 4 : Search car."<<endl;
        cout << "Choose your option: \n";
        cin >> option;
        switch (option) {
            case 1:{
                cout << "Time: "<<sys_time.print_time()<< " Car in the garage:\n"
                <<"--------------------------------------------------------\n";
                printInfo(carlist,sys_time);
                break;
            }
            case 2:{
                Time_stay = distribution(generator);
                addCar(carlist, Time_stay);
                break;
            }
            case 3:{
                advanceTime(carlist, sys_time);
                break;
            }
            case 4:{
                int option2;
                cout <<"Search target cars in the garage according to:.\n"
                <<"--------------------------------------------------------\n"
                <<"option 1 : single criteria.\n"
                <<"option 2 : Multi criteria -- AND.\n"
                <<"option 3 : Multi criteria -- OR.\n";
                cin >> option2;
                switch(option2){
                    case 1:
                        uni_search(carlist);
                        break;
                    case 2:
                        and_search(carlist);
                        break;
                    case 3:
                        or_search(carlist);
                        break;
                    default:
                        break;
                }
                break;
            }
            default:
                break;
        }
        
    }
    cout <<"\n--------------------------------------------------------\n";
    cout << "Rutgers Garage is closed after 24:00. Good night!\n";
    return 0;
}

void printInfo(vector<Car> &carlist,TimeCovert &sys_time){
    cout<<"Enter-time  Maker     Model     Color    License  Exit-time  Total-Charge"<<endl;
    int total_fee{0};
    for(int i=0; i<carlist.size(); i++){
        if(carlist[i].get_tm_out() > sys_time.get_time()){
            total_fee += carlist[i].get_fee();
            cout << left <<"  "<< setw(10)<<carlist[i].print_tm_in() << setw(10)<<carlist[i].get_maker() <<setw(10)<< carlist[i].get_model() <<setw(9)<< carlist[i].get_color() <<setw(9)<< carlist[i].get_license_num() <<"  "<<setw(9)<< carlist[i].print_tm_out() <<"  $"<<total_fee<<endl;
        }
    }
}

void addCar(vector<Car> &carlist,double &Time_stay){
    // IO
    int hour,min;
    string License, Maker, Model, Color;
    cout <<"Enter Time - hour(6~24 hour): ";
    cin >> hour;
    cout <<"Enter Time - min(0~60 min): ";
    cin >> min;
    cout << "License Number: ";
    cin >> License;
    cout << "Maker: ";
    cin>> Maker;
    cout <<"Model: ";
    cin >>Model;
    cout << "Color: ";
    cin >> Color;
    
    // push the car in the vector
    Car car(License, Time_stay, hour, min, Maker , Model, Color);
    carlist.push_back(car);
    
}


void advanceTime(vector<Car> &carlist, TimeCovert &sys_time){
    sys_time = TimeCovert(sys_time.get_time()+0.5);
    vector<Car> car_out;
    int cursor = 0;
    int length = carlist.size();
    
    // choose out the target car
    for(int i=0; i < length; i++){
        if(carlist[i].get_tm_out() <= sys_time.get_time()){
            car_out.push_back(carlist[i-cursor]);
            carlist.erase(carlist.begin()+i-cursor);
            cursor += 1;
        }
    }
    // erase them from the carlist
    
    
    // print the info of exited car
    cout << "Time: "<< sys_time.print_time()<<" Cars that exited garage in the past 30 minutes:\n"
    <<"--------------------------------------------------------\n";
    cout<<"Enter-time  Maker     Model     Color    License  Exit-time  Total-Charge"<<endl;
    int total_fee{0};
    
    for(int i=0; i <car_out.size();i++){
        total_fee += car_out[i].get_fee();
        cout << left <<"  "<< setw(10)<<car_out[i].print_tm_in() << setw(10)<<car_out[i].get_maker() <<setw(10)<< car_out[i].get_model() <<setw(9)<< car_out[i].get_color() <<setw(9)<< car_out[i].get_license_num() <<"  "<<setw(9)<< car_out[i].print_tm_out() <<"  $"<<total_fee<<endl;
    }
}

void uni_search(vector<Car> &carlist){
    int option;
    cout <<"Single criteria. Choose your criteria:.\n"
    <<"--------------------------------------------------------\n"
    <<"option 1 : Maker.\n"
    <<"option 2 : Model.\n"
    <<"option 3 : Color.\n"
    <<"option 4 : License Number.\n";
    cin >> option;
    string criteria;

    cout << "Input your criteria: ";
    cin >> criteria;
    switch(option){
        case 1:{
            for(int i=0; i<carlist.size(); i++){
                if(carlist[i].get_maker() == criteria){
                    cout << left << setw(10)<<carlist[i].get_maker() <<setw(10)<< carlist[i].get_model() <<setw(9)<< carlist[i].get_color() <<setw(9)<< carlist[i].get_license_num() <<endl;
                }
            }
            cout <<"--------------------------------------------------------\n"
                << "All Car has been chosen\n"<<endl;
            break;
        }
        case 2:{
            for(int i=0; i<carlist.size(); i++){
                if(carlist[i].get_model() == criteria){
                    cout << left << setw(10)<<carlist[i].get_maker() <<setw(10)<< carlist[i].get_model() <<setw(9)<< carlist[i].get_color() <<setw(9)<< carlist[i].get_license_num() <<endl;
                }
            }
            cout <<"--------------------------------------------------------\n"
                << "All Car has been chosen.\n"<<endl;
            
            break;
        }
        case 3:{
            for(int i=0; i<carlist.size(); i++){
                if(carlist[i].get_color() == criteria){
                    cout << left << setw(10)<<carlist[i].get_maker() <<setw(10)<< carlist[i].get_model() <<setw(9)<< carlist[i].get_color() <<setw(9)<< carlist[i].get_license_num() <<endl;
                }
            }
            cout <<"--------------------------------------------------------\n"
                << "All Car has been chosen.\n" <<endl;
            
            break;
        }
        case 4:{
            for(int i=0; i<carlist.size(); i++){
                if(carlist[i].get_license_num() == criteria){
                    cout << left << setw(10)<<carlist[i].get_maker() <<setw(10)<< carlist[i].get_model() <<setw(9)<< carlist[i].get_color() <<setw(9)<< carlist[i].get_license_num() <<endl;
                }
            }
            cout <<"--------------------------------------------------------\n"
                << "All Car has been chosen.\n" <<endl;
            
            break;
        }
        default:
            break;
    }
}


void and_search(vector<Car> &carlist){
    vector<Car> temp = carlist;
    vector<Car> target;
    int feature;
    string variable;
    bool done = false;
    while(!done){
        cout <<"Multi criteria AND.\n"
        <<"--------------------------------------------------------\n"
        <<"option 1 : Maker.\n"
        <<"option 2 : Model.\n"
        <<"option 3 : Color.\n"
        <<"option 4 : License Number.\n"
        <<"option 5 : Finished and print.\n";
        while(!done){
            cout << "Choose your feature: ";
            cin >> feature;

            switch(feature){
                case 1:{
                    cout << "Choose your variable: ";
                    cin >> variable;
                    for(Car item:temp){
                        if(item.get_maker() == variable){
                            target.push_back(item);
                        }
                    }
                    temp = target;
                    target = {};
                    break;
                }
                case 2:{
                    cout << "Choose your variable: ";
                    cin >> variable;
                    for(Car item:temp){
                        if(item.get_model() == variable){
                            target.push_back(item);
                        }
                    }
                    temp = target;
                    target = {};
                    break;
                }
                case 3:{
                    cout << "Choose your variable: ";
                    cin >> variable;
                    for(Car item:temp){
                        if(item.get_color() == variable){
                            target.push_back(item);
                        }
                    }
                    temp = target;
                    target = {};
                    break;
                }
                case 4:{
                    cout << "Choose your variable: ";
                    cin >> variable;
                    for(Car item:temp){
                        if(item.get_license_num() == variable){
                            target.push_back(item);
                        }
                    }
                    temp = target;
                    target = {};
                    break;
                }
                case 5:{
                    cout <<"--------------------------------------------------------\n";
                    for(int i=0; i<temp.size(); i++){
                        cout << left << setw(10)<<temp[i].get_maker() <<setw(10)<< temp[i].get_model() <<setw(9)<< temp[i].get_color() <<setw(9)<< temp[i].get_license_num() <<endl;
                        }
                    cout <<"--------------------------------------------------------\n"
                        << "All Car has been choosen\n.";
                    done = true;
                    break;
                    }
                default:
                    break;
                    
            }
        }
    }
}

void or_search(vector<Car> &carlist){
    // feature and variables
    int feature;
    string variable;
    bool done = false;
    vector<int> features;
    vector<string> variables;
    vector<Car> target;
    
    
    
    // IO process to get the features and variable
    cout <<"Multi criteria OR.\n"
    <<"--------------------------------------------------------\n"
    <<"option 1 : Maker.\n"
    <<"option 2 : Model.\n"
    <<"option 3 : Color.\n"
    <<"option 4 : License Number.\n"
    <<"option 5 : Finished and print.\n";
    
    while(!done){
        cout << "Choose your feature: ";
        cin >> feature;
        if(feature == 5){
            done = true;
            break;
        }else{
            features.push_back(feature);
        }
        
        cout << "Choose your variable: ";
        cin >> variable;
        variables.push_back(variable);
    }
    
    for(int i = 0; i <carlist.size(); i++){
        for(int j = 0; j < features.size(); j++){
            if(features[j] == 1){
                if(variables[j] == carlist[i].get_maker()){
                    target.push_back(carlist[i]);
                    break;
                }
            }
            if(features[j] == 2){
                if(variables[j] == carlist[i].get_model()){
                    target.push_back(carlist[i]);
                    break;
                }
            }
            if(features[j] == 3){
                if(variables[j] == carlist[i].get_color()){
                    target.push_back(carlist[i]);
                    break;
                }
            }
            if(features[j] == 4){
                if(variables[j] == carlist[i].get_license_num()){
                    target.push_back(carlist[i]);
                    break;
                }
            }
        }
    }
    cout <<"--------------------------------------------------------\n";
    for(int i=0; i<target.size(); i++){
        cout << left << setw(10)<<target[i].get_maker() <<setw(10)<< target[i].get_model() <<setw(9)<< target[i].get_color() <<setw(9)<< target[i].get_license_num() <<endl;
        }
    cout <<"--------------------------------------------------------\n"
        << "All Car has been choosen\n.";
}
