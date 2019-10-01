//
//  Ticket.hpp
//  C++
//
//  Created by Jason Ha on 9/27/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef Ticket_hpp
#define Ticket_hpp

#pragma once
#include <stdio.h>
#include <random>
#include <string>
#include <cmath>
#include "TimeCovert.hpp"
using namespace std;

class Ticket{
private:
    TimeCovert tm_in;
    TimeCovert tm_out;
    double tm_stay;
    int parking_fee;
    
    
public:
    // default constructor
    Ticket(){}
    
    // constructor
    Ticket(int hour, int min, double time);
    
    // accessors and mutators
    double get_time_in(){return tm_in.get_time();}
    double get_time_out(){return tm_out.get_time();}
    string print_time_in(){return tm_in.print_time();}
    string print_time_out(){return tm_out.print_time();}
    int get_parking_fee(){return parking_fee;}
};

#endif /* Ticket_hpp */
