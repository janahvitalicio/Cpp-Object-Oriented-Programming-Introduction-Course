/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 24, 2019 (Week 10, Milestone 3)
 **********************************************************/

#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H

#include <iostream>

#include "Product.h"

namespace ama {

	double& operator+=(double&, const Product&);
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);

}

#endif