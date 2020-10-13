/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 27, 2019 (Week 11, Milestone 4)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <iomanip>

#include "Product.h"
#include "ErrorState.h"

using namespace std;

namespace ama {

	char prodType; // Global variable to set the Product Type to the jv_type variable

	Product::Product(char type) {
		jv_type = type;
		jv_sku[0] = '\0';
		jv_unit[0] = '\0';
		jv_name = nullptr;
		jv_quantityOnHand = 0;
		jv_quantityNeeded = 0;
		jv_pricebtax = 0.0;
		jv_taxableStatus = false;

		prodType = type;
	}

	Product::Product(const char* sku, const char* name, const char* unit, double pricebtax, int needed,
		int onHand, bool taxable) {
		if (name != nullptr) {
			strncpy(jv_sku, sku, max_length_sku);
			jv_sku[max_length_sku] = '\0';

			strncpy(jv_unit, unit, max_length_unit);
			jv_unit[max_length_unit] = '\0';

			jv_quantityOnHand = onHand;
			jv_quantityNeeded = needed;
			jv_pricebtax = pricebtax;
			jv_taxableStatus = taxable;

			jv_type = prodType;

			int length = strlen(name);
			jv_name = nullptr;
			jv_name = new char[length];
			for (int i = 0; i < length; i++) {
				jv_name[i] = name[i];
			}
			jv_name[length] = '\0';
		}
		else {
			*this = Product();
		}
	}

	Product::Product(const Product& other) {
		jv_name = nullptr;
		*this = other;
	}

	Product::~Product() {
		delete[] jv_name;
	}

	Product& Product::operator=(const Product& other) {
		if (this != &other) {
			jv_type = other.jv_type;

			strncpy(jv_sku, other.jv_sku, max_length_sku);
			strncpy(jv_unit, other.jv_unit, max_length_unit);

			jv_quantityOnHand = other.jv_quantityOnHand;
			jv_quantityNeeded = other.jv_quantityNeeded;
			jv_pricebtax = other.jv_pricebtax;
			jv_taxableStatus = other.jv_taxableStatus;
			jv_errstate.message(other.jv_errstate.message());

			delete[] jv_name;
			jv_name = nullptr;
			if (other.jv_name != nullptr) {
				int length = strlen(other.jv_name);
				jv_name = new char[length];
				for (int i = 0; i < length; i++) {
					jv_name[i] = other.jv_name[i];
				}
				jv_name[length] = '\0';
			}
			else {
				jv_name = nullptr;
			}

		}

		return *this;
	}

	int Product::operator+=(int cnt) {
		if (cnt > 0) {
			jv_quantityOnHand += cnt;
		}

		return jv_quantityOnHand;
	}

	bool Product::operator==(const char* sku) const {
		int equal = strcmp(this->jv_sku, sku);

		if (equal == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Product::operator> (const char* sku) const {
		int greater = strcmp(jv_sku, sku);

		if (greater > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool Product::operator> (const iProduct& other) const {
		int greater = strcmp(jv_name, other.name());

		if (greater > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int Product::qtyAvailable() const {
		return jv_quantityOnHand;
	}

	int Product::qtyNeeded() const {
		return jv_quantityNeeded;
	}

	const char* Product::name() const {
		return jv_name;
	}

	double Product::total_cost() const {
		double price = jv_pricebtax;

		if (jv_taxableStatus == true) {
			price = jv_pricebtax * (1.00 + tax_rate);
		}

		double total = static_cast<double>(jv_quantityOnHand * price);
		return total;
	}

	double Product::taxed() const {
		double price = jv_pricebtax;

		if (jv_taxableStatus == true) {
			price = jv_pricebtax * (1.00 + tax_rate);
		}

		double total = static_cast<double>(price);
		return total;
	}

	bool Product::isEmpty() const {
		if (jv_name == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void Product::message(const char* pText) {
		jv_errstate.message(pText);
	}

	bool Product::isClear() const {
		if (jv_errstate.isEmpty()) {
			return true;
		}
		else {
			return false;
		}
	}

	std::istream& Product::read(std::istream& in, bool interractive) {
		char sku[max_length_sku + 1];
		char* name = new char[max_length_name + 1];
		char unit[max_length_unit + 1];
		int onHand;
		int needed;
		double pricebtax;
		char tax;
		bool taxable;
		int flag = 0;

		if (interractive == true) {
			cout << right << setw(max_length_label) << "Sku: ";
			in >> sku;

			cout << right << setw(max_length_label) << "Name (no spaces): ";
			in >> name;

			cout << right << setw(max_length_label) << "Unit: ";
			in >> unit;

			cout << right << setw(max_length_label) << "Taxed? (y/n): ";
			in >> tax;

			if (tax == 'Y' || tax == 'y') {
				taxable = true;
			}
			else if (tax == 'N' || tax == 'n') {
				taxable = false;
			}
			else {
				in.setstate(ios::failbit);
				jv_errstate.message("Only (Y)es or (N)o are acceptable!");
				flag = 1;
			}

			if (flag == 0) {
				cout << right << setw(max_length_label) << "Price: ";
				in >> pricebtax;

				if (!jv_errstate && in.fail()) {
					in.setstate(ios::failbit);
					jv_errstate.message("Invalid Price Entry!");
					flag = 1;
				}
			}

			if (flag == 0) {
				cout << right << setw(max_length_label) << "Quantity on hand: ";
				in >> onHand;

				if (!jv_errstate && in.fail()) {
					jv_errstate.message("Invalid Quantity Available Entry!");
					in.setstate(ios::failbit);
					flag = 1;
				}
			}

			if (flag == 0) {
				cout << right << setw(max_length_label) << "Quantity needed: ";
				in >> needed;

				if (!jv_errstate && in.fail()) {
					jv_errstate.message("Invalid Quantity Needed Entry!");
					in.setstate(ios::failbit);
					flag = 1;
				}
			}

		}
		else if (interractive == false) {
			in.getline(sku, max_length_sku, ',');
			in.getline(name, max_length_name, ',');
			in.getline(unit, max_length_unit, ',');

			if (flag == 0) {
				cout.width(max_length_label - 1);
				in >> pricebtax;
				in.ignore(1, ',');

				if (!jv_errstate && in.fail()) {
					in.setstate(ios::failbit);
					jv_errstate.message("Invalid Price Entry!");
					flag = 1;
				}
			}

			in >> tax;
			in.ignore(1, ',');

			if (flag == 0) {
				if (tax == 'Y' || tax == 'y' || tax == '1') {
					taxable = true;
				}
				else if (tax == 'N' || tax == 'n' || tax == '0') {
					taxable = false;
				}
				else {
					in.setstate(ios::failbit);
					jv_errstate.message("Only (Y)es or (N)o are acceptable!");
					flag = 1;
				}
			}

			if (flag == 0) {
				in >> onHand;
				in.ignore(1, ',');

				if (!jv_errstate && in.fail()) {
					in.setstate(ios::failbit);
					jv_errstate.message("Invalid Quantity Available Entry!");
					flag = 1;
				}
			}

			if (flag == 0) {
				in >> needed;

				if (!jv_errstate && in.fail()) {
					in.setstate(ios::failbit);
					jv_errstate.message("Invalid Quantity Needed Entry!");
					flag = 1;
				}
			}
		}

		if (flag == 0) {
			Product temp = Product(sku, name, unit, pricebtax, needed, onHand, taxable);
			*this = temp;
		}

		return in;

		delete[] name;
		name = nullptr;
	}

	std::ostream& Product::write(std::ostream& out, int writeMode) const {
		if (!jv_errstate.isEmpty() && jv_name == nullptr) {
			out << jv_errstate;
		}
		else if (jv_name == nullptr) {
		}
		else if (writeMode == 0) {
			out << jv_type << "," << jv_sku << "," << jv_name << "," << jv_unit
				<< "," << fixed << setprecision(2) << jv_pricebtax << "," << jv_taxableStatus
				<< "," << jv_quantityOnHand << "," << jv_quantityNeeded;
		}
		else if (writeMode == 1) {
			string strName = jv_name;
			string tempName = strName.substr(0, 13);
			string tempTaxStatus;

			if (jv_taxableStatus == true) {
				tempTaxStatus = "yes";
			}
			else {
				tempTaxStatus = "no";
			}

			out << " " << setw(max_length_sku) << right << jv_sku
				<< " | " << setw(13) << tempName << "..."
				<< " | " << setw(10) << left << jv_unit
				<< " | " << setw(7) << right << fixed << setprecision(2) << jv_pricebtax
				<< " | " << setw(3) << right << tempTaxStatus
				<< " | " << setw(6) << right << jv_quantityOnHand
				<< " | " << setw(6) << right << jv_quantityNeeded << " |";
		}
		else if (writeMode == 2) {
			out << right << setw(max_length_label) << "Sku: " << jv_sku << endl;
			out << right << setw(max_length_label) << "Name: " << jv_name << endl;
			out << right << setw(max_length_label) << "Price: " << fixed << setprecision(2) << jv_pricebtax << endl;
			out << right << setw(max_length_label) << "Price after Tax: " << fixed << setprecision(2) << taxed() << endl;
			out << right << setw(max_length_label) << "Quantity Available: " << jv_quantityOnHand << " " << jv_unit << endl;
			out << right << setw(max_length_label) << "Quantity Needed: " << jv_quantityNeeded << " " << jv_unit << endl;
		}

		return out;
	}

}