# include <ostream>

#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
	friend std::ostream& operator<<(std::ostream&, const RationalNumber &);
	friend std::istream& operator>>(std::istream&, RationalNumber &);
public:
	explicit RationalNumber(int = 0, int = 1); // default constructor
	RationalNumber operator+(const RationalNumber &); // addition
	RationalNumber operator-(const RationalNumber &); // subtraction
	RationalNumber operator*(const RationalNumber &); // multiplication
	RationalNumber operator/(const RationalNumber &); // division
	// equality operators
	bool operator==(const RationalNumber &) const;
	bool operator!=(const RationalNumber &) const;
	// assignment operator
	RationalNumber& operator=(const RationalNumber &);
private:
	int numerator; // private variable numerator
	int denominator; // private variable denominator
	void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif
