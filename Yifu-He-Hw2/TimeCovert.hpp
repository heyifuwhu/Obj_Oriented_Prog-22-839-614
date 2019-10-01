//
//  TimeCovert.hpp
//  C++
//
//  Created by Jason Ha on 9/28/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef TimeCovert_hpp
#define TimeCovert_hpp

#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

class TimeCovert{
private:
    double tm_record;
    string tm_hour;
    string tm_min;
public:
    // default constructor
    TimeCovert(){}
    // constructor
    TimeCovert(double time);
    TimeCovert(int hour,int min);
    
    // accessor and mutator
    double get_time(){return tm_record;}
    string print_time(){return tm_hour + ":" + tm_min;}
    string get_hour(){return tm_hour;}
    string get_min(){return tm_min;}
    //void adjust_time(double time);
    //void adjust_time(int hour, int min);
};
#endif /* TimeCovert_hpp */
