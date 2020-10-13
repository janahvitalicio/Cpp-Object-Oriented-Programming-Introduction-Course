/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 22, 2019 (Week 10, Workshop 8)
 **********************************************************/

#include <iostream>
#include <cstring>
#include "SavingsAccount.h"

using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		if (interestRate > 0) {
			jv_interest = interestRate;
		}
		else {
			jv_interest = 0.0;
		}
	}

	void SavingsAccount::monthEnd() {
		double interest = (balance() * jv_interest);
		credit(interest);
	}

	void SavingsAccount::display(std::ostream& out) const {
		out.unsetf(ios::fixed);
		out.precision(2);
		out.setf(ios::fixed);
		out << "Account type: Savings" << endl;
		out << "Balance: $" << balance() << endl;
		out << "Interest Rate (%): " << jv_interest * 100 << endl;
	}
}