/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 15, 2019 (Week 6, Workshop 5)
 **********************************************************/

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {

	// Fraction class
	class Fraction {
		// Instance variables
		int numerator;
		int denominator;

		// Private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// Public member functions
		Fraction();
		Fraction(const int, const int);
		bool isEmpty() const;
		void display() const;

		// + operator overload
		Fraction operator+(const Fraction&) const;
	};

}


#endif