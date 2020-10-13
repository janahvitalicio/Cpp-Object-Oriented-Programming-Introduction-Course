/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 21, 2019 (Week 3, Workshop 2)
 **********************************************************/

// Workshop 2 - Dynamic Memory
// Version 1.0


#include <iostream>
#include "CellPhone.h"

using namespace std;
using namespace sict;

void read(sict::CellPhone& phone);

int main()
{
	int count = 0;
	// Declares the pPhones pointer
	CellPhone* pPhones = nullptr;

	cout << "==========" << endl
	     << "Input data" << endl
	     << "==========" << endl
	     << "Enter the number of phones: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// Allocates dynamic memory for the pPhones pointer
	pPhones = new CellPhone[count];

	for (int i = 0; i < count; ++i) {
		cout << "Phone #" << i + 1 << ": " << endl;
		// Accepts user input for Phone i
		CellPhone& readPhones = pPhones[i];
		read(readPhones);
	}
	cout << "==========" << endl << endl;

	// Testing that "display(...)" works
	cout << "------------------------------" << endl
	     << "The 1st phone entered is" << endl
	     << "------------------------------" << endl;
	sict::display(pPhones[0]);
	cout << "------------------------------" << endl << endl;

	// Deallocates the dynamic memory
	delete pPhones;
	pPhones = nullptr;

	return 0;
}


// Read accepts data for a Phone from standard input
void read(sict::CellPhone& phone)
{
	cout << "Enter the model of the Phone: ";
	cin.get(phone.m_model, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the price for phone " << phone.m_model << ": ";
	cin >> phone.m_price;
	cin.ignore(2000, '\n');
}
