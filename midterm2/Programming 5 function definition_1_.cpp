#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "RationalNumber.h"
using namespace std;

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n, int d)
{
	numerator = n;
	// validate denominator
	if (d > 0)
		denominator = d;
	else
		invalid_argument("Denominator cannot be 0");
	reduction(); // invokes function reduction
} // end RationalNumber constructor

// overloaded + operator
RationalNumber RationalNumber::operator+(const RationalNumber &a)
{
	return RationalNumber(
		numerator * a.denominator + denominator * a.numerator,
		denominator * a.denominator);
} // end function operator+

// overloaded - operator
RationalNumber RationalNumber::operator-(const RationalNumber &s)
{
	return RationalNumber(
		numerator * s.denominator - denominator * s.numerator,
		denominator * s.denominator);
} // end function operator-

// overloaded * operator
RationalNumber RationalNumber::operator*(const RationalNumber &m)
{
	return RationalNumber(numerator * m.numerator,
		denominator * m.denominator);
} // end function operator*

RationalNumber RationalNumber::operator/(const RationalNumber &m)
{
	return RationalNumber(numerator * m.denominator,
		denominator * m.numerator);
} // end function operator*
  
// overloaded == operator
bool RationalNumber::operator==(const RationalNumber &er) const
{
	return numerator == er.numerator && denominator == er.denominator;
} // end function operator==

// overloaded != operator
bool RationalNumber::operator!=(const RationalNumber &er) const
{
	return !(*this == er);
} // end function operator!=

// overloaded = operator
RationalNumber& RationalNumber::operator=(const RationalNumber &er)
{
	numerator = er.numerator;
	denominator = er.denominator;
	this->reduction();
	return *this;
} // end function operator=

// overloaded << operator
ostream& operator<<(ostream& output, const RationalNumber &er)
{
	if (er.numerator == 0) // print fraction as zero
		cout << er.numerator;
	else if (er.denominator == 1) // print fraction as integer
		cout << er.numerator;
	else
		cout << er.numerator << '/' << er.denominator;
	return output;
} // end function operator<<

// overloaded >> operator
istream& operator>>(istream& input, RationalNumber &er)
{
	input >> er.numerator >> er.denominator;
	while (er.denominator == 0)
	{
		cout << "Denominator cannot be 0! Please enter again:" << endl;
		input >> er.numerator >> er.denominator;
	}
	return input;
} // end function operator>>

// function reduction definition
void RationalNumber::reduction()
{
	int gcd = 1; // greatest common divisor;
	int largest = (numerator > denominator) ? numerator : denominator;
	for (int loop = 2; loop <= largest; ++loop)
		if (numerator % loop == 0 && denominator % loop == 0)
			gcd = loop;
	numerator /= gcd;
	denominator /= gcd;
} // end function reduction