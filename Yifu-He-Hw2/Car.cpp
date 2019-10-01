//
//  Car.cpp
//  C++
//
//  Created by Jason Ha on 9/27/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "Car.hpp"
using namespace std;

Car::Car(string License,double Time,int hour, int min, string Maker,string Model,string Color){
    // info that need to be input
    maker = Maker;
    model = Model;
    color = Color;
    license_num = License;
    
    // info generated automatically
    ticket = Ticket(hour, min, Time);
}
