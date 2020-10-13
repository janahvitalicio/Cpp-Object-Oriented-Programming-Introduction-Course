/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string.h>
#include <string>

#include "Utilities.h"

using namespace std;

namespace ama {

	double& operator+=(double& total, const iProduct& prod) {
		return total += prod.total_cost();
	}

	std::ostream& operator<<(std::ostream& out, const iProduct& prod) {
		return prod.write(out, 2);
	}

	std::istream& operator>>(istream& in, iProduct& prod) {
		prod.read(in, true);
		return in;
	}

	iProduct* createInstance(char tag) {
		if (tag == 'N' || tag == 'n') {
			return new Product();
		}
		else if (tag == 'P' || tag == 'p') {
			return new Perishable();
		}
		else {
			return nullptr;
		}
	}

}