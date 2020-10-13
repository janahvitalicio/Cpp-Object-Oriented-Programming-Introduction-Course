/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 1, 2019 (Week 4, Workshop 3)
 **********************************************************/

#ifndef SICT_BOOK_H
#define SICT_BOOK_H

namespace sict {

	const int max_title_size = 32;
	const int max_name_size = 16;

	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book {
		char lastName[max_name_size + 1];
		char firstName[max_name_size + 1];
		char title[max_title_size + 1];
		long long isbn;
		int year;
		double price;

	public:
		void set(const char*, const char*, const char*, long long);
		void set(int, double);
		bool isEmpty() const;
		void display(bool line=false) const;
	};

}
#endif