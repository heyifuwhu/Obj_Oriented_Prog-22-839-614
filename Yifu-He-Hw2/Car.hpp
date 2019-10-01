//
//  Car.hpp
//  C++
//
//  Created by Jason Ha on 9/27/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#pragma once
#include <stdio.h>
#include "Ticket.hpp"
#include <string>

using namespace std;

class Car{
private:
    string maker;
    string model;
    string color;
    string license_num;
    Ticket ticket;
public:
    // default constructor
    Car(){}
    
    // constructor
    Car(string License, double Time, int hour,int min, string Maker = "Unknown",string Model="Unknown",string Color="Unknown");
    
    //accessors and mutators
    void set_maker(string Maker){maker = Maker;}
    void set_model(string Model){model = Model;}
    void set_color(string Color){color = Color;}
    void set_license_num(string License){license_num = License;}
    string get_maker(){return maker;}
    string get_model(){return model;}
    string get_color(){return color;}
    string get_license_num(){return license_num;}
    double get_tm_in(){return ticket.get_time_in();}
    double get_tm_out(){return ticket.get_time_out();}
    string print_tm_in(){return ticket.print_time_in();}
    string print_tm_out(){return ticket.print_time_out();}
    int get_fee(){return ticket.get_parking_fee();}
    
    
};

#endif /* Car_hpp */
