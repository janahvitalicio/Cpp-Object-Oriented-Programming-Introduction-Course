/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 22, 2019 (Week 10, Workshop 8)
 **********************************************************/

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include <iostream>
#include "iAccount.h"

namespace sict {

	class Account : public iAccount {
		double jv_balance;
	protected:
		double balance() const;

	public:
		Account(double);
		bool credit(double);
		bool debit(double);

		~Account() {};
	};

	iAccount* CreateAccount(const char*, double);
}

#endif
