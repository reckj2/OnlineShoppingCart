/*
* File: ItemToPurchase.h
* Author: Joshua Reck
* NetID: reckj2
*
* Description: Creates an ‘online’ shopping cart that prompts users for entries.
*
*/

#pragma once

#include <iostream>
#include <string>

using namespace std;

#ifndef ItemToPurchase_H
#define ItemToPurchase_H

class ItemToPurchase {
public:
	//Constructor for classs
	ItemToPurchase();

	ItemToPurchase(string, string, int, int);
	
	//getters and setters for class
	string GetName() const;
	int GetPrice() const;
	int GetQuantity() const;
	string GetDescription() const;

	void SetName(string);
	void SetPrice(int);
	void SetQuantity(int);
	void SetDescription(string);


private:
	
	// private data members for class
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;

};



#endif
