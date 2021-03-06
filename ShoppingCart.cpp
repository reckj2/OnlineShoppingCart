/*
* File: ShoppingCart.cpp
* Author: Joshua Reck
* NetID: reckj2
*
* Description: Creates an ‘online’ shopping cart that prompts users for entries.
*
*/

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

//Default constructor
ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2016";
}

//Parametized constructor
ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	currentDate = date;
}


//Getters and setters 
string ShoppingCart::GetCustomerName() const {
	return customerName;
}

void ShoppingCart::setCustomerName(string name) {
	customerName = name;
}

string ShoppingCart::GetDate() const {
	return currentDate;
}

void ShoppingCart::setDate(string date) {
	currentDate = date;
}

//Adds item of class ItemToPurchase to cartItems
void ShoppingCart::AddItem(ItemToPurchase item) {
	cartItems.push_back(item);
}

//Removes item of class ItemToPurchase from cartItems
void ShoppingCart::RemoveItem(string name) {
	int p=0;
	//Cycles through list of items and compares name of item
	for (unsigned int i = 0; i < cartItems.size(); i++) {
		if (name.compare(cartItems[i].GetName()) == 0) {
			cartItems.erase(cartItems.begin() + i);
			p = 1;
		}
	}
	if (p == 0) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
}

//Modify items in shopping cart given type ItemToPurchase
void ShoppingCart::ModifyItem(ItemToPurchase item) {
	int p = 0;
	int check = 0;
	cout << "Enter the new quantity:" << endl;
	cin >> p;
	
	//Cycles through items and changes quantity
	for (unsigned int i = 0; i < cartItems.size(); i++) {
		if (item.GetName().compare(cartItems[i].GetName()) == 0) {
			check = 1;
			cartItems[i].SetQuantity(p);
		}
	}
	if (check == 0) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
}

//returns number of items in cart
int ShoppingCart::GetNumItemsInCart() const{
	int temp = 0;
	for (unsigned int i = 0; i < cartItems.size(); i++) {
		temp = temp + (cartItems[i].GetQuantity());
	}
	return temp;
}

//Adds up total cost of cart
int ShoppingCart::GetCostOfCart() const{
	int temp =0;
	for (unsigned int i = 0; i < cartItems.size(); i++) {
		temp = temp + (cartItems[i].GetPrice() * cartItems[i].GetQuantity());
	}
	return temp;
}


//Prints out each item, the quantity and the total price
void ShoppingCart::PrintTotal() {
	int temp;
	
	if (cartItems.size() == 0) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	else {

		for (unsigned int i = 0; i < cartItems.size(); i++) {
			temp = cartItems[i].GetQuantity() *cartItems[i].GetPrice();
			cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = $" << temp << endl;
			
		}
	}

}

//Prints items and their decriptions
void ShoppingCart::PrintDescriptions() {

	if (cartItems.size() == 0) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	else {
		cout << "Item Descriptions" << endl;

		for (unsigned int i = 0; i < cartItems.size(); i++) {

			cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;

		}
	}
}
