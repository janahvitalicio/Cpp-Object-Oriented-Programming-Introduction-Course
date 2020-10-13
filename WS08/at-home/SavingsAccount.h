/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 22, 2019 (Week 10, Workshop 8)
 **********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {
		double jv_interest;

	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;

		~SavingsAccount() {};
	};


}

#endif