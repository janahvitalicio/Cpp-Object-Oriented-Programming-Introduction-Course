/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include <iostream>

#include "Product.h"
#include "Perishable.h"

namespace ama {

	double& operator+=(double&, const iProduct&);
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);

}

#endif