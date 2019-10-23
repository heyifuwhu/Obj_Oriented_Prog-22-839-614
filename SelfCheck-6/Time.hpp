//
//  Time.hpp
//  SF6
//
//  Created by Jason Ha on 10/19/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Time{
public:
    explicit Time(int=0,int =0,int =0);
    void setTime(int,int,int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;
    string toUniversalString() const;
    string toStandardString() const;
private:
    unsigned int time_in_second;
};

#endif /* Time_hpp */
