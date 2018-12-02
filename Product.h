#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <sstream>
#include "Customer.h"
#include "Product.h"

class Product {
	int id;
	int inventory;
	int numSold;
	std::string name;
	std::string description;
	double totalPaid;
public:
	Product(int, std::string);
	int getID() const;
	std::string getName() const;
	std::string setName(std::string);
	std::string getDescription() const;
	void setDescription(std::string);
	int getNumberSold() const;
	double getTotalPaid() const;
	int getInventoryCount() const;
	void addShipment(int, double);
	void reduceInventory(int);
	double getPrice() const;
};


std::ostream& operator<<(std::ostream& os, const Product& p);
bool operator== (const Product& n1, const Product& n2);


#endif


