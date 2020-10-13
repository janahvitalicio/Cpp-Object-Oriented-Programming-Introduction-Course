/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 24, 2019 (Week 10, Milestone 3)
 **********************************************************/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include "ErrorState.h"

namespace ama {

	const int max_length_label = 30;
	const int max_length_sku = 7;
	const int max_length_name = 75;
	const int max_length_unit = 10;
	const int write_condensed = 0;
	const int write_table = 1;
	const int write_human = 2;

	const double tax_rate = 0.13;

	class Product {
		char jv_type;
		char jv_sku[max_length_sku + 1];
		char jv_unit[max_length_unit + 1];
		char* jv_name;
		int jv_quantityOnHand;
		int jv_quantityNeeded;
		double jv_pricebtax;
		bool jv_taxableStatus;
		ErrorState jv_errstate;

	protected:
		void message(const char*);
		bool isClear() const;
		double taxed() const;

	public:
		Product(char type = 'N');
		Product(const char*, const char*, const char*, double pricebtax = 0, int needed = 0,
			int onHand = 0, bool taxable = true);
		Product(const Product& other);
		~Product();
		Product& operator=(const Product&);
		int operator+=(int);
		bool operator==(const char*) const;
		bool operator> (const char*) const;
		bool operator> (const Product&) const;
		int qtyAvailable() const;
		int qtyNeeded() const;
		const char* name() const;
		double total_cost() const;
		bool isEmpty() const;
		std::istream& read(std::istream&, bool);
		std::ostream& write(std::ostream&, int) const;
	};

	
}

#endif