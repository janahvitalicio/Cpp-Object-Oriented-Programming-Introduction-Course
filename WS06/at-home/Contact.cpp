/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 8, 2019 (Week 8, Workshop 6)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include "Contact.h"

using namespace std;

namespace sict
{
	bool Contact::isValidPN(const long long pn) {
		string tempPN = std::to_string(pn);
		char *charTempPN = new char[tempPN.length() + 1];
		strcpy(charTempPN, tempPN.c_str());

		int length = tempPN.length();

		bool validNumber = false;

		if (length == 11) {
			validNumber = charTempPN[0] != '0' && charTempPN[1] != '0' && charTempPN[4] != '0';
		}
		else if (length == 12) {
			validNumber = charTempPN[0] != '0' && charTempPN[2] != '0' && charTempPN[5] != '0';
		}

		delete[] charTempPN;

		return validNumber;
	}

	Contact::Contact(){
		name[0] = '\0';
		phoneNumbers = nullptr;
		size = 0;
	}

	Contact::Contact(const Contact& src){
		phoneNumbers = nullptr;
		*this = src;
	}

	Contact& Contact::operator=(const Contact& source){
		if (this != &source){
			strcpy(name, source.name);
			size = source.size;

			delete[] phoneNumbers;

			if (source.phoneNumbers != nullptr){
				phoneNumbers = new long long[size];

				for (int i = 0; i < size; i++){
					phoneNumbers[i] = source.phoneNumbers[i];
				}
			}
			else{
				phoneNumbers = nullptr;
			}
		}

		return *this;
	}

	Contact& Contact::operator+=(long long pn) {
		if (!isEmpty()) {
			if (pn != 0 && isValidPN(pn)) {
				size++;

				long long* temp = new long long[size];

				for (int i = 0; i < size - 1; i++) {
					temp[i] = phoneNumbers[i];
				}

				temp[size - 1] = pn;
				delete[] phoneNumbers;
				phoneNumbers = temp;
			}
		}

		return *this;
	}

	Contact::Contact(const char *n, const long long *pn, const int s){
		if (n != nullptr && n[0] != '\0'){
			strncpy(name, n, max_name_size - 1);
			name[15] = '\0';
		}
		else{
			name[0] = '\0';
		}

		if (pn != nullptr && pn[0] != 0 && s != 0){
			phoneNumbers = new long long[s];
			size = 0;
			for (int i = 0; i < s; i++){
				if (isValidPN(pn[i])) {
					size += 1;
					phoneNumbers[size - 1] = pn[i];
				}
			}
		}
		else {
			phoneNumbers = nullptr;
			size = 0;
		}
	}

	Contact::~Contact(){
		delete[] phoneNumbers;
		phoneNumbers = nullptr;
	}

	bool Contact::isEmpty() const{
		if (name[0] == '\0' && phoneNumbers == nullptr && size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Contact::display() const{
		if (isEmpty()){
			cout << "Empty contact!" << endl;
		}
		else{
			cout << name << endl;

			if (phoneNumbers != nullptr && phoneNumbers[0] != '\0'){
				for (int i = 0; i < size; i++){
					string tempPN = std::to_string(phoneNumbers[i]);
					int length = tempPN.length();

					if (length == 11){
						cout << "(+" << tempPN[0] << ") "
							<< tempPN[1] << tempPN[2] << tempPN[3] << " "
							<< tempPN[4] << tempPN[5] << tempPN[6]
							<< "-" << tempPN[7] << tempPN[8] << tempPN[9]
							<< tempPN[10] << endl;
					}
					else{
						cout << "(+" << tempPN[0] << tempPN[1] << ") "
							<< tempPN[2] << tempPN[3] << tempPN[4] << " "
							<< tempPN[5] << tempPN[6] << tempPN[7]
							<< "-" << tempPN[8] << tempPN[9] << tempPN[10]
							<< tempPN[11] << endl;
					}
				}
			}
		}
	}

}