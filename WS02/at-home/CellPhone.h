/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 25, 2019 (Week 3, Workshop 2)
 **********************************************************/

// Header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H


namespace sict {

	// Defines the structure CellPhone in the sict namespace
	struct CellPhone {
		char m_model[32];
		float m_price;
	};

	// Declares the function display(...),
	// also in the sict namespace
	void display(const struct CellPhone cp);

	void display(const struct CellPhone* cp, int num);
}
#endif