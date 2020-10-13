/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 18, 2019 (Week 10, Workshop 8)
 **********************************************************/

#include <iostream>
#include "SavingsAccount.h"
using namespace std;

namespace sict {

	const double interestRate = 0.05;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *p = nullptr;
		if (type[0] == 'S') {
			p = new SavingsAccount(balance, interestRate);
			return p;
		}
		else {
			return p;
		}
	}
}