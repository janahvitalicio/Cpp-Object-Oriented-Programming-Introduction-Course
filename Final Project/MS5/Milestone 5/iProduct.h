/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H

#include <iostream>
#include "Date.h"

namespace ama {

	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;

	const double tax_rate = 0.13;

	class iProduct {
	public:
		virtual std::ostream& write(std::ostream&, int) const = 0;
		virtual std::istream& read(std::istream&, bool) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual int qtyNeeded() const = 0;
		virtual int qtyAvailable() const = 0;
		virtual const char* name() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iProduct&) const = 0;
		virtual ~iProduct() {};
	};

	iProduct* createInstance(char);

}

#endif