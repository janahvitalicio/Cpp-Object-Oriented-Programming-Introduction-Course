/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 22, 2019 (Week 10, Workshop 8)
 **********************************************************/

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include <iostream>
#include "Account.h"

namespace sict {

	class ChequingAccount : public Account {
		double jv_transFee;
		double jv_monthlyFee;

	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};

	
}

#endif
