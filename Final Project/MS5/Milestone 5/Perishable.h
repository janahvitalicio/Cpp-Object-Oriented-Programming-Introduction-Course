/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include <iostream>

#include "Date.h"
#include "Product.h"

namespace ama {

	class Perishable : public Product {
	private:
		Date jv_date;
	public:
		Perishable();

		std::ostream& write(std::ostream&, int) const;
		std::istream& read(std::istream&, bool);
	};

}

#endif