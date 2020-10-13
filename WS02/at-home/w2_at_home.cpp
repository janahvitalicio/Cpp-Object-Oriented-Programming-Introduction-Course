/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 25, 2019 (Week 3, Workshop 2)
 **********************************************************/

 // Workshop 2 - Dynamic Memory
 // Version 1.0


#include <iostream>
#include <cstdio>
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

	// Expands the array of Phones by 1 element
	{
		// Allocates dynamic memory for count + 1 Phones
		CellPhone *newPhones = nullptr;
		newPhones = new CellPhone[count + 1];

		// Copies elements from original array into a newly allocated array
		for (int i = 0; i < count; i++) {
			newPhones[i] = pPhones[i];
		}

		// Deallocates the dynamic memory for the original array
		delete[] pPhones;
		pPhones = nullptr;

		// Copies the address of the newly allocated array into pPhones pointer
		pPhones = newPhones;
	}

	// Adds the new Phone
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Phone #" << count + 1 << ": " << endl;
	// Accepts input for the new element in the array
	CellPhone& readPhones = pPhones[count];
	read(readPhones);

	count++;
	cout << "==========\n" << endl;

	// Testing that the overload of "display(...)" works
	sict::display(pPhones, count);
	cout << endl;

	// Deallocates the dynamic memory here
	delete pPhones;
	pPhones = nullptr;

	return 0;
}


// Read accepts data for a Phone from standard input
void read(CellPhone& phone)
{
	cout << "Enter the model of the Phone: ";
	cin.get(phone.m_model, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the price for phone " << phone.m_model << ": ";
	cin >> phone.m_price;
	cin.ignore(2000, '\n');
}
