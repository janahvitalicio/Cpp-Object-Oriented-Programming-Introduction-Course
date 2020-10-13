/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          March 17, 2019 (Week 9, Milestone 2)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string.h>
#include <string>

#include "ErrorState.h"

using namespace std;

namespace ama {

	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			jv_messageAddress = nullptr;
		}
		else {
			int length = strlen(errorMessage);
			jv_messageAddress = new char[length + 1];
			strncpy(jv_messageAddress, errorMessage, length);
		}
	}

	ErrorState::~ErrorState() {
		delete[] jv_messageAddress;
		jv_messageAddress = nullptr;
	}

	ErrorState::operator bool() const {
		if (jv_messageAddress != nullptr && jv_messageAddress[0] != '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	ErrorState& ErrorState::operator = (const char* pText) {
		delete[] jv_messageAddress;
		if (pText == nullptr || pText[0] == '\0') {
			jv_messageAddress = nullptr;
		}
		else {
			int length = strlen(pText);
			jv_messageAddress = new char[length + 1];
			strncpy(jv_messageAddress, pText, length);
		}
		return *this;
	}

	void ErrorState::message(const char* pText) {
		delete[] jv_messageAddress;
		if (pText == nullptr || pText[0] == '\0') {
			jv_messageAddress = nullptr;
		}
		else {
			int length = strlen(pText);
			jv_messageAddress = new char[length + 1];
			strncpy(jv_messageAddress, pText, length);
		}
	}

	const char* ErrorState::message() const {
		if (jv_messageAddress == nullptr || jv_messageAddress == '\0') {
			return nullptr;
		}
		else {
			return jv_messageAddress;
		}
	}

	bool ErrorState::isEmpty() const {
		bool empty = jv_messageAddress == nullptr || jv_messageAddress[0] == '\0';
		return empty;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& es) {
		if (!es.isEmpty()) {
			os << es.message();
		}
		return os;
	}

}