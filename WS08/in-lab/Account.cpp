/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 18, 2019 (Week 10, Workshop 8)
 **********************************************************/

#include <iostream>
#include "Account.h"
using namespace std;

namespace sict {

	Account::Account(double balance) {
		if (balance > 0) {
			jv_balance = balance;
		}
		else {
			jv_balance = 0.0;
		}
	}

	bool Account::credit(double amount) {
		if (amount > 0) {
			jv_balance += amount;
			return true;
		}
		else {
			return false;
		}
	}

	bool Account::debit(double amount) {
		if (amount > 0) {
			jv_balance -= amount;
			return true;
		}
		else {
			return false;
		}
	}

	double Account::balance() const {
		return jv_balance;
	}

}