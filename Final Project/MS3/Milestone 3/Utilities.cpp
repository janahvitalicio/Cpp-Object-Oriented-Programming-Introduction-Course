/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 24, 2019 (Week 10, Milestone 3)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string.h>
#include <string>

#include "Utilities.h"

using namespace std;

namespace ama {

	double& operator+=(double& total, const Product& prod) {
		return total += prod.total_cost();
	}

	std::ostream& operator<<(std::ostream& out, const Product& prod) {
		return prod.write(out, 2);
	}

	std::istream& operator>>(istream& in, Product& prod) {
		prod.read(in, true);
		return in;
	}

}