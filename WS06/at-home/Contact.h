/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 8, 2019 (Week 8, Workshop 6)
 **********************************************************/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {

	const int max_name_size = 16;

	class Contact {
		char name[max_name_size];
		long long* phoneNumbers;
		int size;

	public:
		Contact();
		Contact(const char*, const long long*, const int);
		
		Contact(const Contact&); // Copy constructor
		Contact& operator=(const Contact&); // Copy assignment operator
		Contact& operator+=(long long); // Overloaded += operator
		~Contact();

		bool isEmpty() const;
		void display() const;

	private:
		// User-defined function for checking valid phone number
		bool isValidPN(const long long);
	};


}

#endif