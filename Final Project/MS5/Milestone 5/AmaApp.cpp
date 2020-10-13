/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <string>
#include <iomanip>
#include <limits>

#include "AmaApp.h"

using namespace std;

namespace ama {

	AmaApp::AmaApp(const char* filename) {
		strncpy(m_filename, filename, 256);
		m_products[0] = nullptr;
		m_noOfProducts = 0;

		this->loadProductRecords();
	}

	AmaApp::~AmaApp() {
		for (int i = 0; i < m_noOfProducts; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}
	}

	void AmaApp::pause() const {
		cout << "Press Enter to continue..." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int AmaApp::menu() const {
		int selection = 0;;
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1- List products" << endl;
		cout << "2- Search product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to product quantity" << endl;
		cout << "6- Delete product" << endl;
		cout << "7- Sort products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> selection;

		cin.clear();
		cin.ignore();

		if (selection >= 0 && selection <= 7) {
			return selection;
		}
		else {
			return -1;
		}
	}

	void AmaApp::loadProductRecords() {
		for (int i = 0; i < m_noOfProducts; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}

		int index = 0;

		fstream file;
		file.open(m_filename, ios::in);

		if (file.is_open()) {
			while (file.good()) {
				char tag = file.get();
				m_products[index] = createInstance(tag);
				if (createInstance(tag) != nullptr) {
					file.ignore();
					m_products[index]->read(file, false);
					index++;
				}
			}
			m_noOfProducts = index;
			file.close();
		}
		else {
			file.clear();
			file.close();
			file.open(m_filename, ios::out);
			file.close();
		}
	}

	void AmaApp::saveProductRecords() const {
		fstream file;
		file.open(m_filename, ios::out);

		for (int i = 0; i < m_noOfProducts; i++) {
			m_products[i]->write(file, write_condensed);
			file << endl;
		}
		file.close();

	}

	void AmaApp::listProducts() const {
		double total_cost = 0;
		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
		cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

		for (int i = 0; i < m_noOfProducts; i++) {
			cout << "|" << right << setw(4) << i + 1 << " |";
			m_products[i]->write(cout, write_table);
			cout << endl;
			total_cost += m_products[i]->total_cost();
		}

		cout << "------------------------------------------------------------------------------------------------" << endl;
		cout << "|                                                      Total cost of support ($): | ";
		cout << right << setw(10) << fixed << setprecision(2) << total_cost << " |" << endl;
		cout << "------------------------------------------------------------------------------------------------" << endl;
	}

	iProduct* AmaApp::find(const char* sku) const {
		int found = 0;

		iProduct* temp = nullptr;
		for (int i = 0; i < m_noOfProducts; i++) {
			if (*m_products[i] == sku) {
				found = 1;
				temp = m_products[i];
				break;
			}
		}

		if (found == 1) {
			return temp;
		}
		else {
			return nullptr;
		}
	}

	void AmaApp::addQty(iProduct* product) {
		int quantity = 0;
		int needed = product->qtyNeeded() - product->qtyAvailable();
		product->write(cout, write_human);
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> quantity;

		if (cin.fail()) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid quantity value!" << endl;
		}
		else {
			if (quantity <= needed) {
				*product += quantity;
			}
			else {
				cout << "Too many items; only " << needed << " is needed. Please return the extra " <<
					quantity - needed << " items." << endl;
				*product += needed;
			}
			saveProductRecords();
			cout << endl << "Updated!" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	void AmaApp::addProduct(char tag) {
		loadProductRecords();
		if (createInstance(tag) != nullptr) {
			m_products[m_noOfProducts] = createInstance(tag);
		}
		m_products[m_noOfProducts]->read(cin, true);
		if (cin.fail()) {
			cin.clear();
			cout << endl << *m_products[m_noOfProducts] << endl << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			m_noOfProducts++;
			saveProductRecords();
			cout << endl << "Success!" << endl << endl;
		}
	}

	int AmaApp::run() {
		int selection = 0;
		int exit = 1;
		iProduct* temp;


		while (exit != 0) {
			selection = menu();
			if (selection == 1) {
				listProducts();
				cout << endl;
				pause();
			}
			else if (selection == 2) {
				char sku[max_length_sku + 1];
				cout << "Please enter the product SKU: ";
				cin >> sku;
				cout << endl;
				temp = find(sku);
				if (find(sku) == nullptr) {
					cout << "No such product!" << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					pause();
				}
				else {
					temp->write(cout, write_human);
					cout << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					pause();
				}
			}
			else if (selection == 3) {
				addProduct('N');
				loadProductRecords();
			}
			else if (selection == 4) {
				addProduct('P');
				loadProductRecords();
			}
			else if (selection == 5) {
				char sku[max_length_sku + 1];
				cout << "Please enter the product SKU: ";
				cin >> sku;
				cout << endl;
				temp = find(sku);
				if (find(sku) == nullptr) {
					cout << "No such product!" << endl;
				}
				else {
					addQty(temp);
				}
				cout << endl;
			}
			else if (selection == 0) {
				cout << "Goodbye!" << endl;
				exit = 0;
			}
			else {
				cout << "~~~Invalid selection, try again!~~~" << endl;
				pause();
			}
		}
		return 0;
	}

}