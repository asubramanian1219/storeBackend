#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <string>
#include "Customer.h"
#include "Product.h"
#include "Store.h"

using namespace std;

Store::Store() {

}
Store::Store(string name) {
	this->name = name;
}
string Store::getName()const {
	return name;
}
void Store::setName(string name) {
	this->name = name;
}
void Store::addProduct(int productID, string productName) {
	for (int i = 0; i < products.size(); i++) {
		if (products.at(i).getID() == productID) {
			throw runtime_error("Error: Product already exists in list");
			break;
		}
	}
	Product newProduct(productID, productName);
	products.push_back(newProduct);
}
Product& Store::getProduct(int productID) {
	for (int i = 0; i < products.size(); i++) {
		if (products.at(i).getID() == productID)
			return products.at(i);
	}
	throw runtime_error("Error: Product not found.");
}
void Store::addCustomer(int customerID, string customerName, bool credit) {
	for (int i = 0; i < customers.size(); i++) {
		if (customers.at(i).getID() == customerID) {
			throw runtime_error("Error: Customer already exists in list");
			break;
		}
	}
	Customer newCust(customerID, customerName,credit);
	customers.push_back(newCust);

}
Customer& Store::getCustomer(int customerID) {
	for (int i = 0; i < customers.size(); i++) {
		if (customers.at(i).getID() == customerID)
			return customers.at(i);
	}
	throw runtime_error("Error: Customer not found.");
}
void Store::takeShipment(int productID, int quantity, double cost) {
	Product& product = getProduct(productID);
	product.addShipment(quantity, cost);
}
void Store::sellProduct(int customerID, int productID, int quantity) {
	Product& product = getProduct(productID);
	Customer& customer = getCustomer(customerID);
	double amount = quantity * product.getPrice();
	customer.processPurchase(amount, product);
	product.reduceInventory(quantity);

}
void Store::takePayment(int customerID, double amount) {
	Customer& customer = getCustomer(customerID);
	customer.processPayment(amount);
}
void Store::listProducts()const {
	for (int i = 0; i < products.size(); i++)
		cout << products.at(i);

}
void Store::listCustomers()const {
	for (int i = 0; i < customers.size(); i++)
		cout << customers.at(i);
}