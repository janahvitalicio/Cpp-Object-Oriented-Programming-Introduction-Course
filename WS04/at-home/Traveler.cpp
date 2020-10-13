/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 8, 2019 (Week 5, Workshop 4)
 **********************************************************/

#include <iostream>
#include <cstring>
#include "Traveler.h"

using namespace std;

namespace sict {

	Traveler::Traveler() {
		firstName[0] = '\0';
		lastName[0] = '\0';
		destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;
	}

	Traveler::Traveler(const char* fn, const char* ln, const char* d) {
		if (fn != '\0' && ln != '\0' && d != '\0') {
			strncpy(firstName, fn, max_name_size - 1);
			strncpy(lastName, ln, max_name_size - 1);
			strncpy(destination, d, max_destination_size - 1);
			year = 2019;
			month = 7;
			day = 1;
		}
		else {
			*this = Traveler();
		}
	}

	Traveler::Traveler(const char* fn, const char* ln, const char* dest, int y, int m, int day_) {
		if (fn != '\0' && ln != '\0' && dest != '\0'
			&& (y >= 2019 && y <= 2022) && (m >= 1 && m <= 12) && (day_ >= 1 && day_ <= 31)) {
			strncpy(firstName, fn, max_name_size - 1);
			strncpy(lastName, ln, max_name_size - 1);
			strncpy(destination, dest, max_destination_size - 1);
			year = y;
			month = m;
			day = day_;
		}
		else {
			*this = Traveler();
		}
	}

	bool Traveler::isEmpty() const {
		bool valid = ((strlen(firstName) > 0) && (strlen(lastName) > 0) && (strlen(destination) > 0));
		return !valid;
	}

	void Traveler::display() const {
		if (isEmpty() == true) {
			cout << "--> Not a valid traveler! <--" << endl;
		}
		else {
			cout << lastName << ", " << firstName << " goes to " << destination
				<< " on " << year << "/";
			cout.fill('0');
			cout.width(2);
			cout << month << "/";
			cout.fill('0');
			cout.width(2);
			cout << day << endl;
		}
	}

	const char* Traveler::name(void) const {
		return firstName;
	}

	bool Traveler::canTravelWith(const Traveler& t) {
		int destValid = strcmp(this->destination, t.destination);

		if ((destValid == 0) && (this->year == t.year)
			&& (this->month == t.month) && (this->day == t.day)) {
			return true;
		}
		return false;
	}
}


