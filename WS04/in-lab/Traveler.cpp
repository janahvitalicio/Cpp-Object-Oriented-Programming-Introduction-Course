/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 4, 2019 (Week 5, Workshop 4)
 **********************************************************/


#include <iostream>
#include <cstring>
#include "Traveler.h"

using namespace std;

namespace sict {
	// Default constructor
	Traveler::Traveler() {
		firstName[0] = '\0';
		lastName[0] = '\0';
		destination[0] = '\0';
	}

	// Constructor with 3 parameters
	Traveler::Traveler(const char * fn, const char * ln, const char * d) {
		if (fn != '\0' && ln != '\0' && d != '\0') {
			strncpy(firstName, fn, max_name_size - 1);
			strncpy(lastName, ln, max_name_size - 1);
			strncpy(destination, d, max_destination_size - 1);
		}
		else {
			*this = Traveler();
		}
	}

	// isEmpty query
	bool Traveler::isEmpty() const {
		bool valid = ((strlen(firstName) > 0) && (strlen(lastName) > 0) && (strlen(destination) > 0));
		return !valid;
	}

	// Display query
	void Traveler::display() const {
		if (isEmpty() == true) {
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else {
			cout << firstName << " " << lastName << " goes to " << destination << endl;
		}
	}
}


