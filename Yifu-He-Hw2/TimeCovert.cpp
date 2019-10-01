//
//  TimeCovert.cpp
//  C++
//
//  Created by Jason Ha on 9/28/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "TimeCovert.hpp"

TimeCovert::TimeCovert(double time){
    tm_record = time;
    
    // covert decimal base into XX:XX
    // convert hour
    if(static_cast<int>(time)<10){
        tm_hour ="0"+tm_hour = to_string(static_cast<int>(time));
    }else{
        tm_hour = to_string(static_cast<int>(time));
    }
    
    
    if(round((time - int(time)) * 60) == 0){
        tm_min = "00";
    }else if(round((time - int(time)) * 60)<10){
        tm_min = "0"+ to_string(int(round((time - int(time)) * 60)));
    }else{
        tm_min = to_string(int(round((time - int(time)) * 60)));
    }
}

TimeCovert::TimeCovert(int hour,int min){
    if(hour < 10){
        tm_hour = "0" + to_string(hour);
    }else{
        tm_hour = to_string(hour);
    }
    if(min < 10){
        tm_min = "0" + to_string(min);
    }else{
        tm_min = to_string(min);
    }
    tm_record = static_cast<double>(hour+min/60.0);
}

