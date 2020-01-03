/*
* File: ShoppingCart.h
* Author: Joshua Reck
* NetID: reckj2
*
* Description: Creates an ‘online’ shopping cart that prompts users for entries.
*
*/

#pragma once

#include "ItemToPurchase.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef ShoppingCart_H
#define ShoppingCart_H

class ShoppingCart {
public:
	//Default constructor
	ShoppingCart();
	
	//Parametized Constructor
	ShoppingCart(string, string);
	
	//Getters and Setters function call
	string GetCustomerName() const;
	void setCustomerName(string);
	string GetDate()const;
	void setDate(string);

	//Add and remove items function call
	void AddItem(ItemToPurchase);
	void RemoveItem(string);

	//Modify item function call
	void ModifyItem(ItemToPurchase);

	
	int GetNumItemsInCart() const;
	int GetCostOfCart() const;

	void PrintTotal();
	void PrintDescriptions();




private:
	//private data members
	string customerName;
	string currentDate;
	vector<ItemToPurchase> cartItems;

};







#endif
