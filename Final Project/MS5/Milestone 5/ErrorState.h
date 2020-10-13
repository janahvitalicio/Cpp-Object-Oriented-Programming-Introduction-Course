/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>

namespace ama {

	class ErrorState {
		char* jv_messageAddress;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator = (const char* pText);
		void message(const char* pText);
		const char* message() const;
		bool isEmpty() const;
	};

	std::ostream& operator<<(std::ostream&, const ErrorState&);
}

#endif