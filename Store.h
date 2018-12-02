#pragma once
#ifndef STORE_H
#define STORE_H

#include "Customer.h"
#include "Product.h"

class Store{
	std::vector<Product> products;
	std::vector<Customer> customers;
	std::string name;

public:
	Store();
	Store(std::string name);
	std::string getName()const;
	void setName(std::string);
	void addProduct(int productID, std::string productName);
	Product& getProduct(int productID);
	void addCustomer(int customerID, std::string customerName, bool credit = false);
	Customer& getCustomer(int customerID);
	void takeShipment(int productID, int quantity, double cost);
	void sellProduct(int customerID, int productID, int quantity);
	void takePayment(int customerID, double amount);
	void listProducts()const;
	void listCustomers()const;

};





#endif

