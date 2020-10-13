/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 10, 2019 (Week 8, Milestone 1)
 **********************************************************/

 //DATE CLASS------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <string.h>

#include "Date.h"

using namespace std;

namespace ama {

	void Date::status(int newStatus) {
		jv_status = newStatus;
	}

	int Date::mdays(int year, int mon) {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0))
			|| (year % 400 == 0));
	}

	Date::Date() {
		jv_year = 0;
		jv_month = 0;
		jv_day = 0;
		jv_status = no_error;
	}

	Date::Date(int year, int month, int day) {
		int invalidYear = 1;
		int invalidMonth = 1;
		int invalidDay = 1;

		int daysInMonth = mdays(year, month);
		
		if ((year >= min_year && year <= max_year) && year > 0) {
			invalidYear = 0;
		}
		if (month >= 1 && month <= 12) {
			invalidMonth = 0;
		}
		if (daysInMonth != 13 && day <= daysInMonth && day != 0 && day > 0) {
			invalidDay = 0;
		}

		if (invalidYear || invalidMonth || invalidDay) {
			*this = Date();
		}

		if (invalidYear == 1) {
			jv_status = error_year;
		}
		else if (invalidMonth == 1) {
			jv_status = error_mon;
		}
		else if (invalidDay == 1) {
			jv_status = error_day;
		}
		else {
			jv_year = year;
			jv_month = month;
			jv_day = day;
			jv_status = no_error;
		}
	}

	int Date::status() const {
		return jv_status;
	}

	void Date::clearError() {
		jv_status = no_error;
	}

	bool Date::isGood() {
		bool good = jv_year != 0 && jv_month != 0 && jv_day != 0 && jv_status == no_error;
		return good;
	}

	Date& Date::operator+=(int days) {
		int temp = 0;
		bool invalidDate = (this->jv_status != no_error || this->jv_year == 0) || (this->jv_month == 0
			|| this->jv_day == 0);

		int daysInMonth = mdays(this->jv_year, this->jv_month);
		temp = daysInMonth + days;
		
		bool invalidDays = temp > daysInMonth;

		if ((invalidDate && invalidDays) || temp < 0 || temp < daysInMonth) {
			jv_status = error_invalid_operation;
			return *this;
		}
		else {
			jv_day += days;
			return *this;
		}
	}

	Date& Date::operator++() {
		int temp = 0;
		bool invalidDate = (this->jv_status != no_error || this->jv_year == 0) || (this->jv_month == 0
			|| this->jv_day == 0);

		int daysInMonth = mdays(this->jv_year, this->jv_month);
		temp = this->jv_day + 1; //add one day

		bool invalidDays = 0;
		if (daysInMonth != 0) {
			invalidDays = (temp > daysInMonth);
		}

		if (invalidDays) {
			this->jv_status = error_invalid_operation;
			return *this;
		}
		else if (invalidDate) {
			this->jv_status = error_invalid_operation;

			
			return *this;
		}
		else {
			this->jv_day++;
			return *this;
		}
	}

	Date Date::operator++(int) {
		int temp = 0;
		bool invalidDate = (this->jv_status != no_error || this->jv_year == 0) || (this->jv_month == 0
			|| this->jv_day == 0);

		int daysInMonth = mdays(this->jv_year, this->jv_month);
		temp = this->jv_day + 1; //add one day

		bool invalidDays = 0;
		if (daysInMonth != 0) {
			invalidDays = (temp > daysInMonth);
		}

		if (invalidDate && invalidDays) {
			this->jv_status = error_invalid_operation;
			return *this;
		}
		else {
			Date d = *this;
			++(*this);
			return d;
		}
	}

	Date Date::operator+(int days) {
		int temp = 0;
		bool invalidDate = (this->jv_status != no_error || this->jv_year == 0) || (this->jv_month == 0
			|| this->jv_day == 0);

		int daysInMonth = mdays(this->jv_year, this->jv_month);
		temp = this->jv_day + days;

		bool invalidDays = temp > daysInMonth;

		if (invalidDate) {
			Date d = *this;
			d.jv_status = error_invalid_operation;
			return d;
		}
		else if (invalidDays) {
			Date d = *this;
			d.jv_status = error_invalid_operation;
			return d;
		}
		else {
			Date d = *this;
			d.jv_day += days;
			return d;
		}
	}

	bool Date::operator==(const Date& rhs) const {
		bool year = this->jv_year == rhs.jv_year;
		bool month = this->jv_month == rhs.jv_month;
		bool day = this->jv_day == rhs.jv_day;
		
		bool equal = year && month && day;
		
		return equal;
	}

	bool Date::operator!=(const Date& rhs) const {
		return !(*this == rhs);
	}

	int empty;

	bool Date::operator<(const Date& rhs) const {
		empty = 0;
		bool lesserYear = this->jv_year < rhs.jv_year;
		bool lesserMonth = this->jv_month < rhs.jv_month;
		bool lesserDay = this->jv_day < rhs.jv_day;

		if ((this->jv_year == 0 && this->jv_month == 0 && this->jv_day == 0)
			&& rhs.jv_year == 0 && rhs.jv_month == 0 && rhs.jv_day == 0) {
			empty = 1;
		}

		if (lesserYear){
			return true;
		}
		else if (lesserMonth) {
			return true;
		}
		else if (lesserDay) {
			return true;
		}
		else{
			return false;
		}
	}
	
	bool Date::operator>(const Date& rhs) const {
		if ((*this < rhs) == true || empty == 1 || (*this == rhs)) {
			return false;
		}
		else {
			return true;
		}
	}

	bool Date::operator<=(const Date& rhs) const {
		return *this < rhs || *this == rhs;
	}

	bool Date::operator>=(const Date& rhs) const {
		return *this > rhs || *this == rhs;
	}

	istream& Date::read(istream& is) {
		char symbol;
		is.clear();
		is >> jv_year >> symbol >> jv_month >> symbol >> jv_day;

		jv_status = no_error;

		if (is.fail()) {
			*this = Date();
			jv_status = error_input;
		}
		else if (jv_year < min_year || jv_year > max_year){
			*this = Date();
			jv_status = error_year;
		}
		else if (jv_month < 1 || jv_month > 12){
			*this = Date();
			jv_status = error_mon;
		}
		else if (jv_day > mdays(jv_year, jv_month) || jv_day == 0){
			*this = Date();
			jv_status = error_day;
		}

		return is;
	}

	ostream& Date::write(ostream& os) const {
		char slash = '/';

		if (jv_year < 10) {
			os << 0 << 0 << 0;
		}
		else if (jv_year < 100) {
			os << 0 << 0;
		}
		else if (jv_year < 1000) {
			os << 0;
		}
		
		os << jv_year << slash;

		if (jv_month < 10){
			os << 0;
		}

		os << jv_month << slash;

		if (jv_day < 10){
			os << 0;
		}

		os << jv_day;

		return os;
	}

	//Helper functions
	istream& operator>>(istream& is, Date& date) {
		return date.read(is);
	}

	ostream& operator<<(ostream& os, const Date& date) {
		return date.write(os);
	}
}
