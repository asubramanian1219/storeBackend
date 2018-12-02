#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Customer.h"
#include "Product.h"
using namespace std;

int main() {
	try {
		Product g(17, "John");
		g.setDescription("desc_test");
		g.addShipment(10, 472.55);

		cout << g<<endl;
		Customer c(10, "Test", true);
		c.processPayment(0);
		c.processPurchase(10,g);
		cout << c;

		
	}
	catch (runtime_error &e) {
		cerr << "Error: " << e.what() << endl;
	}
	system("pause");
	
}