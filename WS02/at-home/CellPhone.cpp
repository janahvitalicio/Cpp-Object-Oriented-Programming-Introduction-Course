/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 25, 2019 (Week 3, Workshop 2)
 **********************************************************/


#include <iostream>
#include <cstdio>
#include "CellPhone.h"

using namespace std;
using namespace sict;


namespace sict {

	// Definition for display(...) 
	void display(const struct CellPhone cp) {
		cout << "Phone " << cp.m_model
			<< " costs $" << cp.m_price << "!" << endl;
	}

	void display(const struct CellPhone* cp, int num) {
		float cheap = 2000;
		int i;

		for (i = 0; i < num; i++) {
			if (cp[i].m_price < cheap) {
				cheap = cp[i].m_price;
			}
		}

		cout << "------------------------------\n"
			<< "Phones available at the mall:\n"
			<< "------------------------------" << endl;
		for (i = 0; i < num; i++) {
			cout << i + 1 << ". Phone " << cp[i].m_model
	        << " costs $" << cp[i].m_price << "!" << endl;
		}
		cout << "------------------------------\n"
			<< "The cheapest phone costs $" << cheap << "."
			<< "\n------------------------------" << endl;
	}
}
