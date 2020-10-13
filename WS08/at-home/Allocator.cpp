/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 22, 2019 (Week 10, Workshop 8)
 **********************************************************/

#include <iostream>
#include "SavingsAccount.h"
#include "ChequingAccount.h"
using namespace std;

namespace sict {

	const double interestRate = 0.05;
	const double transactionFee = 0.50;
	const double monthlyFee = 2.00;

	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *p = nullptr;
		if (type[0] == 'S') {
			p = new SavingsAccount(balance, interestRate);
			return p;
		}
		else if(type[0] == 'C'){
			p = new ChequingAccount(balance, transactionFee, monthlyFee);
			return p;
		}
		else {
			return p;
		}
	}
}