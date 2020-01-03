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
	ShoppingCart();
	ShoppingCart(string, string);
	string GetCustomerName() const;
	void setCustomerName(string);

	string GetDate()const;
	void setDate(string);

	void AddItem(ItemToPurchase);
	void RemoveItem(string);

	void ModifyItem(ItemToPurchase);

	int GetNumItemsInCart() const;
	int GetCostOfCart() const;

	void PrintTotal();
	void PrintDescriptions();




private:
	string customerName;
	string currentDate;
	vector<ItemToPurchase> cartItems;

};







#endif