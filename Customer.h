#pragma once
#ifndef STOREBACKEND_H
#define STOREBACKEND_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Product.h"


class Customer {
	int id;
	std::string name;
	bool credit;
	double balance;
	std::vector<Product>productsPurchased;

public:
	Customer(int, std::string, bool);
	int getID() const;
	std::string getName() const;
	void setName(std::string);
	bool getCredit() const;
	void setCredit(bool);
	double getBalance() const;
	void processPayment(double);
	void processPurchase(double, Product);
	std::string getProductsPurchased() const;
};

std::ostream& operator<<(std::ostream& os, const Customer& c);

#endif