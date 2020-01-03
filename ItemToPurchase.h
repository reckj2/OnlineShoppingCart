#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef ItemToPurchase_H
#define ItemToPurchase_H

class ItemToPurchase {
public:
	ItemToPurchase();

	ItemToPurchase(string, string, int, int);
	
	string GetName() const;
	int GetPrice() const;
	int GetQuantity() const;
	string GetDescription() const;

	void SetName(string);
	void SetPrice(int);
	void SetQuantity(int);
	void SetDescription(string);


private:
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;

};



#endif
