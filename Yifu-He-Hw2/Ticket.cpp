//
//  Ticket.cpp
//  C++
//
//  Created by Jason Ha on 9/27/19.
//  Copyright © 2019 Jason He. All rights reserved.
//
#include <iostream>
#include "Ticket.hpp"
using namespace std;

Ticket::Ticket(int hour, int min, double time){
    
    // record enter time by hour and min
    tm_in = TimeCovert(hour,min);
    // check whether tm_out is greater than 24:00 and adjust tm_out, tm_stay
    // if the time to stay is smaller than zero, make it as 1 min.
    if(time <= 0){
        tm_stay = 1/60;
        }
    // if the exit time is greater than 24:00, make it 24:00
    if(tm_in.get_time() + time >= 24){
        tm_stay = 24 - tm_in.get_time();
        tm_out = TimeCovert(24.0);
    }else{
        tm_stay = time;
        tm_out = TimeCovert(tm_stay+tm_in.get_time());
    }
    
    // convert the time
    int time_calculate = stoi(tm_out.get_hour()) - stoi(tm_in.get_hour());
    
    if (stoi(tm_out.get_min()) - stoi(tm_in.get_min()) > 0){
        time_calculate += 1;
    }
    
    // calculate the parking fee
    if (time_calculate <= 3 ){
        parking_fee = 4;
    }else if (time_calculate <= 9){
        parking_fee = time_calculate + 1;
    }else{
        parking_fee = 10;
    }
}

