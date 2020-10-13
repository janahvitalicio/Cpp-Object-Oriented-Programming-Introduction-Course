/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 8, 2019 (Week 5, Workshop 4)
 **********************************************************/

#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H

namespace sict {

	const int max_destination_size = 32;
	const int max_name_size = 16;

	class Traveler {
		char firstName[max_name_size];
		char lastName[max_name_size];
		char destination[max_destination_size];
		int year;
		int month;
		int day;
	public:
		Traveler();
		Traveler(const char *, const char *, const char *);
		Traveler(const char *, const char *, const char *, int, int, int);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler&);
	};
}

#endif