#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Customer.h"
#include "Product.h"

using namespace std;

Customer::Customer(int customerID, std::string name, bool credit) {
	if (name == "") {
		throw std::runtime_error("Product name cannot be empty.");

	}
	id = customerID;
	this->name = name;
	this->credit = credit;
	this->balance = 0;
	
}
int Customer::getID() const {
	return id;
}
std::string Customer::getName() const {
	return name;
}
void Customer::setName(std::string name) {
	if (name == "") {
		throw runtime_error("Name cannot be empty");
	}
	this->name = name;
}
bool Customer::getCredit() const {
	return credit;
}
void Customer::setCredit(bool hasCredit) {
	credit = hasCredit;
}
double Customer::getBalance() const {
	return balance;
}
void Customer::processPayment(double amount) {
	if (amount < 0)
		throw runtime_error("Balance cannot be negative");
	else
		balance += amount;
}
void Customer::processPurchase(double amount, Product product) {
	bool success = false;
	if (amount < 0) {
		throw runtime_error("Amount cannot be negative.");
	}
	else if (credit == true) {
		balance -= amount;
		success = true;
		
	}
	else {
		if (balance >= amount) {


			balance -= amount;
			success = true;
		}
		

			
	}
	if (success == false) {
		throw runtime_error("Balance is too low.");
		
	}
	else {
		bool isThere = false;
		for (int i = 0; i < productsPurchased.size(); i++) {
			if (productsPurchased.at(i) == product) {
				isThere = true;
			}
		}
		if (!isThere)
			productsPurchased.push_back(product);
	}
		
	
	
}

string Customer::getProductsPurchased()const {
	stringstream products;
	for (int i = 0; i < productsPurchased.size(); i++) {
		products << productsPurchased.at(i)<<endl;
	}
	return products.str();
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
	os << "Customer name: " << c.getName() << endl;
	os << "Customer ID: " << c.getID() << endl;
	os << "Has credit: " << c.getCredit() << endl;
	os << "Balance: " << c.getBalance() << endl;
	os << "Products purchased --" << endl<<endl;
	os << c.getProductsPurchased();
	return os;
}
