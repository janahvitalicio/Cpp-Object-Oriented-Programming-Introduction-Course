/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          January 28, 2019 (Week 4, Workshop 4)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict {

	void Book::set(const char* first_Name, const char* last_Name, const char* title_, long long i_sbn) {
		// Assumes isbn is invalid, then checks if valid
		firstName[0] = '\0';
		lastName[0] = '\0';
		isbn = 0;

		if (i_sbn >= min_isbn_value && i_sbn <= max_isbn_value) {
			isbn = i_sbn;
			strncpy(firstName, first_Name, max_name_size + 1);
			firstName[max_name_size] = '\0';
			strncpy(lastName, last_Name, max_name_size + 1);
			lastName[max_name_size] = '\0';
			strncpy(title, title_, max_title_size + 1);
			title[max_title_size] = '\0';
		}
	}
	
	bool Book::isEmpty() const {
		return !isbn;
	}

	void Book::display() const {
		if (!isEmpty()) {
			cout << "Author: " << lastName << ", " << firstName << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << isbn << endl;
		}
		else {
			cout << "The book object is empty!" << endl;
		}
	}
}