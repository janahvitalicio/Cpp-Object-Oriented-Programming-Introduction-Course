/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 27, 2019 (Week 11, Milestone 4)
 **********************************************************/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include <iostream>

#include "Product.h"

namespace ama {

	double& operator+=(double&, const iProduct&);
	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);

}

#endif