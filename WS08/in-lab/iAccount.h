/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 18, 2019 (Week 10, Workshop 8)
 **********************************************************/

#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>

namespace sict {

	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char*, double);
}

#endif