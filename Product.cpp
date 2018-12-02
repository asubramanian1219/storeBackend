#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Customer.h"
#include "Product.h"

using namespace std;

Product::Product(int productID, std::string productName) {
	if (productName == "") {
		throw runtime_error("Product name cannot be empty.");

	}
	id = productID;
	name = productName;
	totalPaid = 0;
	inventory = 0;
	numSold = 0;

}
int Product::getID() const {
	return id;
}
std::string Product::getName() const {
	return name;
}
std::string Product::setName(std::string productName) {
	if (productName == "")
		throw runtime_error("Product name cannot be empty");
	name = productName;
	return "";

}
std::string Product::getDescription() const {
	return description;
}
void Product::setDescription(std::string description) {
	this->description = description;
}
int Product::getNumberSold() const {
	return numSold;

}
double Product::getTotalPaid() const {
	return totalPaid;
}
int Product::getInventoryCount() const {
	return inventory;

}
void Product::addShipment(int shipmentQuantity, double shipmentCost) {
	if (shipmentQuantity <= 0) {
		throw runtime_error("Shipment quantity can't be negative.");

	}
	else if (shipmentCost <= 0) {
		throw runtime_error("Shipment cost can't be negative.");

	}
	else {

		this->inventory += shipmentQuantity;
		this->totalPaid += shipmentCost;
	}
}
void Product::reduceInventory(int purchaseQuantity) {
	if (purchaseQuantity > inventory) {
		throw runtime_error("There isn't enough inventory.");

	}
	if (purchaseQuantity < 0) {
		throw runtime_error("Quantity of goods purchased can't be negative.");

	}
	else {
		inventory -= purchaseQuantity;
		numSold += purchaseQuantity;


	}
}
double Product::getPrice() const {
	double price=(totalPaid / (inventory + numSold))*1.25;
	return price;
}

std::ostream& operator<<(std::ostream& os, const Product& p) {
	os << "Product name: " << p.getName() << endl;
	os << "Product ID: " << p.getID() << endl;
	os << "Description: " << p.getDescription() << endl;
	os << "Inventory: " << p.getInventoryCount() << endl;
	os << "Total paid: " << p.getTotalPaid() << endl;
	return os;
}
bool operator== (const Product& n1, const Product& n2) {
	return n1.getName() == n2.getName();
}