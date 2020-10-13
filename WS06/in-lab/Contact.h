/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 4, 2019 (Week 8, Workshop 6)
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
		Contact(const char*, const long long*, int);
		~Contact();

		bool isEmpty() const;
		void display() const;
	public:
		Contact(const Contact& other) = delete;
		Contact& operator=(const Contact& other) = delete;
	};
	

}

#endif