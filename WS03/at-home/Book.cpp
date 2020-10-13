/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 1, 2019 (Week 4, Workshop 3)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ISBN_DIGITS 12 // Excluding the check digit

#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

namespace sict {

	void Book::set(const char* first_Name, const char* last_Name, const char* title_, long long i_sbn) {
		int sum = 0;
		int oddSum = 0;
		int evenSum = 0;
		long long tempISBN = 0;
		int highestInt, diff;
		int i, checkDigit;
		int digits[MAX_ISBN_DIGITS] = { 0 }; // Array of ISBN digits (excluding check digit)

		// Assumes isbn is invalid, then checks if valid
		firstName[0] = '\0';
		lastName[0] = '\0';
		isbn = 0;
		
		tempISBN = i_sbn;
		
		if (i_sbn >= min_isbn_value && i_sbn <= max_isbn_value) {

			checkDigit = tempISBN % 10;
			tempISBN /= 10; // Removes check digit

			// Uses reverse loop to store the digits in an array in the right order
			for (i = MAX_ISBN_DIGITS - 1; i >= 0; i--) {
				isbn = tempISBN % 10;
				digits[i] = isbn;
				tempISBN /= 10;
			}
			
			// Sum of in Odd positions
			for (i = 0; i < MAX_ISBN_DIGITS; i = i + 2) {
				oddSum += digits[i];
			}
			
			// Sum of numbers in Even position
			for (i = 1; i < MAX_ISBN_DIGITS; i = i + 2) {
				evenSum += digits[i];
			}

			// Whole calculation is not stored in one variable for readability
			sum = oddSum + (evenSum * 3);
			highestInt = (sum / 10) + 1;
			diff = (highestInt * 10) - sum;

			if (diff == checkDigit) {
				isbn = i_sbn;
				strncpy(firstName, first_Name, max_name_size + 1);
				firstName[max_name_size] = '\0';
				strncpy(lastName, last_Name, max_name_size + 1);
				lastName[max_name_size] = '\0';
				strncpy(title, title_, max_title_size + 1);
				title[max_title_size] = '\0';
			}
			else {
				isbn = 0;
			}
		}
	}

	void Book::set(int year_, double price_) {
		if (!isEmpty()) {
			year = year_;
			price = price_;
		}
	}

	bool Book::isEmpty() const {
		return !isbn;
	}

	void Book::display(bool line_) const {
		if (!isEmpty() && !line_) {
			cout << "Author: " << lastName << ", " << firstName << endl;
			cout << "Title: " << title << endl;
			cout << "ISBN-13: " << isbn << endl;
			cout << "Publication Year: " << year << endl;
			cout << "Price: " << price << endl;
		}
		else if (isEmpty() && !line_) {
			cout << "The book object is empty!" << endl;
		}
		else if (isEmpty() && line_) {
			cout << "|";
			cout.width(92);
			cout.setf(ios::left);
			cout << "The book object is empty!";
			cout << "|" << endl;
		}
		else if (!isEmpty() && line_) {
			cout << "|";
			cout.width(max_name_size);
			cout.setf(ios::right);
			cout << lastName << "|";
			cout.width(max_name_size);
			cout.setf(ios::right);
			cout << firstName << "|";
			cout.unsetf(ios::right);
			cout.width(max_title_size);
			cout.setf(ios::left);
			cout << title << "|";
			cout.width(13);
			cout.setf(ios::right);
			cout << isbn << "|";
			cout.width(4);
			cout.setf(ios::right);
			cout << year << "|";
			cout.width(6);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << price << "|" << endl;
		}
	}
}