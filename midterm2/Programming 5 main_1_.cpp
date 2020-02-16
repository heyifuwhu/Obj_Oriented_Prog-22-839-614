#include <iostream>
#include "RationalNumber.h"
using namespace std;

int main()
{
	RationalNumber c(9, 2), d(6, 18), x;
	cout << "Rational Number c is: " << c << endl;
	cout << "Rational Number c is: " << d << endl;
	cout << " c + d = ";
	x = c + d; // test overloaded operators + and = and <<
	cout << x << endl;

	cout << " c - d = ";
	x = c - d; // test overloaded operators - and = and <<
	cout << x << endl;

	cout << " c * d = ";
	x = c * d; // test overloaded operators * and = and <<
	cout << x << endl;

	cout << " c / d = ";
	x = c / d; // test overloaded operators / and = and <<
	cout << x << endl;

	// test overloaded equal operator
	cout << "c = d ? -> ";
	cout << ((c == d) ? "True" : "False") << endl; // test == 
	
	cout << "c = d ? -> ";
	cout << ((c != d) ? "False" : "True") << endl; // test !=

	// test = operator
	cout << "Please enter a rational number:" << endl;
	cin >> x; // test >>
	cout << "The rational number entered is:" << endl;
	cout << x << endl;

	system("pause");
}