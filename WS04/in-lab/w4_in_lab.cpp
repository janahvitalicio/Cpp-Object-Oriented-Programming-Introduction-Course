/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          February 4, 2019 (Week 5, Workshop 4)
 **********************************************************/


#include <iostream>
#include "Traveler.h"
#include "Traveler.h" // This is intentional

using namespace std;
using namespace sict;

int main() {
	Traveler travelers[] = {
		Traveler(nullptr, nullptr, "Toronto"),
		Traveler(nullptr, "",      "Toronto"),
		Traveler(nullptr, "Smith", "Toronto"),

		Traveler("",      nullptr, "Toronto"),
		Traveler("",      "",      "Toronto"),
		Traveler("",      "Smith", "Toronto"),

		Traveler("John",  nullptr, "Toronto"),
		Traveler("John",  "",      "Toronto"),
		Traveler("John",  "Smith", "Toronto"), // Valid

		Traveler("John",  "Smith", nullptr),
		Traveler("John",  "Smith", ""),
		Traveler(nullptr, nullptr, nullptr),
		Traveler("",      "",      ""),
		Traveler()
	};
	cout << "----------------------------------------" << endl;
	cout << "Testing the validation logic" << endl;
	cout << "(only traveler 9 should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 14; ++i)
	{
		cout << "Traveler " << i + 1 << ": " << (travelers[i].isEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	sict::Traveler vanessa("Vanessa", "Williams", "Paris"),
		            mike("Mike",       "Jones",    "Tokyo"),
		            alice("Alice",     "Miller",   "Rome");

	cout << "----------------------------------------" << endl;
	cout << "Testing the display function" << endl;
	cout << "----------------------------------------" << endl;
	vanessa.display();
	mike.display();
	alice.display();
	travelers[0].display(); // Not valid
	travelers[8].display();
	travelers[13].display(); // Not valid
	cout << "----------------------------------------" << endl << endl;

	return 0;
}
