/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 4, 2019 (Week 5, Workshop 4)
 **********************************************************/


// Header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

namespace sict {

	const int max_destination_size = 32;
	const int max_name_size = 16;

    // Traveler class
	class Traveler {
		char firstName[max_name_size];
		char lastName[max_name_size];
		char destination[max_destination_size];
	public:
		Traveler();
		Traveler(const char *, const char *, const char *);
		bool isEmpty() const;
		void display() const;
	};
}

#endif