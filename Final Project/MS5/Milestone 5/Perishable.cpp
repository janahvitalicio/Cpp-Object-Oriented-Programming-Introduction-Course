/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#include <iostream>
#include <iomanip>

#include "Perishable.h"

using namespace std;

namespace ama {

	Perishable::Perishable() : Product('P') {
		
	}

	ostream& Perishable::write(ostream& os, int writeMode) const {
		Product::write(os, writeMode);

		if (isClear() && !isEmpty()) {
			if (writeMode == write_human) {
				os << right << setw(max_length_label)
					<< "Expiry Date: ";
				jv_date.write(os) << endl;
			}
			else if(writeMode == write_table){
				os << " ";
				jv_date.write(os);
				os << " |";
			}
			else {
				os << ',';
				jv_date.write(os);
			}
		}

		return os;
	}

	istream& Perishable::read(istream& is, bool interactive) {
		Date tempDate;

		Product::read(is, interactive);

		if (interactive == true) {
			cout << right << setw(max_length_label) << "Expiry date (YYYY/MM/DD): ";
			is >> tempDate;

			if (tempDate.status() != no_error) {
				is.setstate(ios::failbit);

				if (tempDate.status() == error_year) {
					message("Invalid Year in Date Entry");
				}
				else if (tempDate.status() == error_mon) {
					message("Invaild Month in Date Entry");
				}
				else if (tempDate.status() == error_day) {
					message("Invalid Day in Date Entry");
				}
				else {
					message("Invalid Date Entry");
				}
			}
			else {
				jv_date = tempDate;
			}
		}
		else {
			is.ignore();
			jv_date.read(is);
		}
		return is;
	}

}