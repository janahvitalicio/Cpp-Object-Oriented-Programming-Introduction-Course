/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 22, 2019 (Week 10, Workshop 8)
 **********************************************************/

#include <iostream>
#include <cstring>
#include "ChequingAccount.h"

using namespace std;

namespace sict {

	ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance) {
		if (transFee > 0) {
			jv_transFee = transFee;
		}
		else {
			jv_transFee = 0.0;
		}

		if (monthlyFee > 0) {
			jv_monthlyFee = monthlyFee;
		}
		else {
			jv_monthlyFee = 0.0;
		}
	}

	bool ChequingAccount::credit(double amount) {
		if(amount > 0){
			Account::debit(jv_transFee);
			Account::credit(amount);
			return true;
		}
		else{
			return false;
		}
	}

	bool ChequingAccount::debit(double amount) {
		if(amount > 0){
			Account::debit(amount + jv_transFee);
			return true;
		}
		else{
			return false;
		}
	}

	void ChequingAccount::monthEnd() {
		Account::debit(jv_monthlyFee);
	}

	void ChequingAccount::display(std::ostream& out) const {
		out.unsetf(ios::fixed);
		out.precision(2);
		out.setf(ios::fixed);
		out << "Account type: Chequing" << endl;
		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << jv_transFee << endl;
		out << "Monthly Fee: " << jv_monthlyFee << endl;
	}

}