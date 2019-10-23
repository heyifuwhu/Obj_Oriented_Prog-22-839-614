//
//  Time.cpp
//  SF6
//
//  Created by Jason Ha on 10/19/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "Time.hpp"
#include <iostream>

using namespace std;

void Time::setHour(int h){
    if (h<0 || h >=24){
        throw invalid_argument( "hour must be 0-23" );
    }
    time_in_second = h*3600 + getMinute() * 60 + getSecond();
}

void Time::setMinute(int min){
    if (min <0 || min >=60){
        throw invalid_argument("minute must be 0-59");
    }
    time_in_second = getHour() * 3600 + min * 60 + getSecond();
}

void Time::setSecond(int sec){
    if (sec <0 || sec >=60){
        throw invalid_argument("second must be 0-59");
    }
    time_in_second = getHour() * 3600 + getMinute() * 60 + sec;
}

unsigned int Time::getHour() const{
    return time_in_second/3600;
}

unsigned int Time::getMinute() const{
    return (time_in_second % 3600) / 60;
}

unsigned int Time::getSecond() const{
    return (time_in_second % 3600) % 60;
}

string Time::toUniversalString() const{
    return to_string(getHour())+":"+ to_string(getMinute())+":"+ to_string(getSecond());
}
string Time::toStandardString() const{
    int hour;
    hour = (getHour() ==0 || getHour() == 12) ? 12 : getHour() % 12;
    string ampm = hour <12? "AM":"PM";
    return to_string(hour)+":"+ to_string(getMinute())+":"+ to_string(getSecond()) + " " + ampm;
}
