/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 15, 2019 (Week 6, Workshop 5)
 **********************************************************/

#include <iostream>
#include <cstring>
#include "Fraction.h"

using namespace std;

namespace sict {

	// Default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}

	// Two-argument constructor
	Fraction::Fraction(int n, int d) {
		if (n >= 0 && d > 0) {
			numerator = n;
			denominator = d;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}

	// Max query
	int Fraction::max() const {
		if (numerator > denominator) {
			return numerator;
		}
		else {
			return denominator;
		}
	}

    // Min query
	int Fraction::min() const {
		if (numerator < denominator) {
			return numerator;
		}
		else {
			return denominator;
		}
	}

	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // Min of numerator and denominator
        int mx = max();  // Max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // From mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // Reduce modifier
	void Fraction::reduce() {
		int temp = gcd();
		numerator = numerator / temp;
		denominator = denominator / temp;
	}

    // Display query
	void Fraction::display() const {
		if (isEmpty()) {
			cout << "no fraction stored";
		}
		else if (denominator == 1) {
			cout << numerator;
		}
		else {
			cout << numerator << "/" << denominator;
		}
	}

    // isEmpty query
	bool Fraction::isEmpty() const {
		if (numerator == 0 && denominator == 0) {
			return true;
		}
		else {
			return false;
		}
	}

    // + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {
		if (isEmpty() == false && rhs.isEmpty() == false) {
			Fraction sum;
			int tempNum = ((numerator * rhs.denominator) + (denominator * rhs.numerator));
			int tempDenom = (denominator*rhs.denominator);
			sum = Fraction(tempNum, tempDenom);
			sum.reduce();
			return sum;
		}
		else {
			return Fraction(0, 0);
		}
	}
}