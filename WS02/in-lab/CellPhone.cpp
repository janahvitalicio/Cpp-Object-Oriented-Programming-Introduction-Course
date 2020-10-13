/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 21, 2019 (Week 3, Workshop 2)
 **********************************************************/

#include <iostream>
#include "CellPhone.h"

using namespace std;
using namespace sict;

namespace sict {

    // Definition for display(...) 
	void display(const struct CellPhone cp) {
		cout << "Phone " << cp.m_model
			 << " costs $" << cp.m_price << "!" << endl;
	}
}
