/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 15, 2019 (Week 6, Workshop 5)
 **********************************************************/

#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace sict {

	class Fraction {
		int numerator;
		int denominator;

		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		Fraction();
		Fraction(const int, const int);
		bool isEmpty() const;
		void display() const;

		Fraction operator+(const Fraction&) const;
		Fraction operator*(const Fraction&) const;
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		Fraction operator+=(const Fraction&);
	};
}
#endif