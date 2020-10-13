/**********************************************************
 * Name:          Janah Vitalicio
 * Date:          April 7, 2019 (Week 12-13, Milestone 5)
 **********************************************************/

#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

#include <iostream>
#include <fstream>

#include "iProduct.h"
#include "Product.h"
#include "Utilities.h"

namespace ama {

	class AmaApp {
		char m_filename[256];
		iProduct* m_products[100];
		int m_noOfProducts;

		AmaApp(const AmaApp& source) = delete;
		AmaApp& operator=(const AmaApp& source) = delete;
		void pause() const;
		int menu() const;
		void loadProductRecords();
		void saveProductRecords() const;
		void listProducts() const;
		iProduct* find(const char* sku) const;
		void addQty(iProduct* product);
		void addProduct(char tag);
	
	public:
		AmaApp(const char*);
		~AmaApp();
		int run();
	};

}

#endif