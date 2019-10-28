//
//  main.cpp
//  sc7
//
//  Created by Jason Ha on 10/26/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>

// overload + operator
RationalNumber RationalNumber::operator+(const RationalNumber& a){
    return RationalNumber{numerator* a.denominator + denominator* a.numerator, denominator * a.denominator};
}

// overload * operator
RationalNumber RationalNumber::operator*(const RationalNumer& m){
    return RationalNumber{numerator * m.numerator, denominator * a.denominator};
}

//RationalNumber == operator
bool RationalNumber::operator==(const RationalNumber &er) const{
    return (numerator == er.numerator) && (denominator == er.denominator);
}
bool RationalNumber::operator!=(const RationalNumber &ner) const{
    return !(*this == ner);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
