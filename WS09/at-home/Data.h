/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 25, 2019 (Week 11, Workshop 9)
 **********************************************************/

// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: Chris Szalwinski, based on previous work by Hasan Murtaza
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////

#include <iostream>
#include <cstring>

using namespace std;

namespace sict {
	// These number defines the output column width for a single data field

	const int COLUMN_WIDTH = 15;
	const int LARGEST_NUMBER = 1000000000;
	const int SMALLEST_NUMBER = 0;

	// max returns the largest item in data
	template<typename T>
	T max(const T* data, int n) {
		T max = data[0];

		for (int i = 1; i < n; i++) {
			if (max < data[i]) {
				max = data[i];
			}
		}

		return max;
	}


	// min returns the smallest item in data
	template<typename T>
	T min(const T* data, int n) {
		T min = data[0];

		for (int i = 1; i < n; i++) {
			if (min > data[i]) {
				min = data[i];
			}
		}

		return min;
	}


	// sum returns the sum of n items in data
	template<typename T>
	T sum(const T* data, int n) {
		T sum = 0;

		for (int i = 0; i < n; i++) {
			sum += data[i];
		}

		return sum;
	}

	// average returns the average of n items in data
	template<typename T>
	double average(const T* data, int n) {
		return sum(data, n) / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template<typename T>
	bool read(std::istream& input, T* data, int n) {
		for (int i = 0; i < n; i++) {
			input.ignore();

			input >> data[i];

			if (input.fail()) {
				return false;
			}
		}

		return true;
	}

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << right << name;

		for (int i = 0; i < n; i++) {
			cout.width(15);
			cout << data[i];
		}

		cout << "\n";
	}

	bool readRow(std::istream& input, const char* name, int* data, int n);
	bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

