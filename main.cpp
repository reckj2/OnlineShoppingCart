/*
* File: main.cpp
* Author: Joshua Reck
* NetID: reckj2
*
* Description: Creates an ‘online’ shopping cart that prompts users for entries.
*
*/

#include <iostream>
#include <string>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;



int main(void) {

	//temporary variables for user input
	string tempName, cusName, tempDate, tempDesc, userRemove, userChange;
	int tempPrice;
	int tempQuant;
	int totalCost;
	char userOption = 'p';

	//Create class type ShoppingCart
	ShoppingCart cart;
	
	//Create class type ItemToPurchase
	ItemToPurchase item;

	//Get user input
	cout << "Enter customer's name:" << endl;
	getline(cin, cusName);
	
	
	cout << "Enter today's date:" << endl;
	getline(cin, tempDate);


	cart.setCustomerName(cusName);
	cart.setDate(tempDate);

	cout << endl;

	cout << "Customer name: " << cart.GetCustomerName() << endl;
	cout << "Today's date: " << cart.GetDate() << endl;

	cout << endl;
	
	
	//While the customer does not want to quit the program
	while (userOption != 'q') {

		//Prints list of options for customer
		cout << "MENU" << endl;
		cout << "a - Add item to cart" << endl;
		cout << "d - Remove item from cart" << endl;
		cout << "c - Change item quantity" << endl;
		cout << "i - Output items' descriptions" << endl;
		cout << "o - Output shopping cart" << endl;
		cout << "q - Quit" << endl;
		cout << endl;

		//gets user input
		cout << "Choose an option:";
		cin >> userOption;
		cout << endl;
		
		//If the user does not choose a given option
		while (userOption != 'a' && userOption != 'd' && userOption != 'c' && userOption != 'i' && userOption != 'o' && userOption != 'q') {
			cout << "Choose an option:";
			cin >> userOption;
			cout << endl;
			
		}
		
		//if user chooses to add an item to the cart
		if (userOption == 'a') {
			
			//Gets item name, quantity, price and description
			cout << "ADD ITEM TO CART" << endl;
			cin.ignore(256, '\n');
			cout << "Enter the item name:" << endl;
			getline(cin, tempName);
			cout << "Enter the item description:" << endl;
			getline(cin, tempDesc);
			cout << "Enter the item price:" << endl;
			cin >> tempPrice;
			cout << "Enter the item quantity:" << endl;
			cin >> tempQuant;

			cin.ignore(256, '\n');

			item.SetName(tempName);
			item.SetPrice(tempPrice);
			item.SetQuantity(tempQuant);
			item.SetDescription(tempDesc);

			cart.AddItem(item);
			cout << endl;
		}
		
		//If user chooses to remove an item from the cart
		if (userOption == 'd') {
		
			//gets name of item
			cout << "REMOVE ITEM FROM CART" << endl;
			cin.ignore(256, '\n');
			cout << "Enter name of item to remove:" << endl;
			getline(cin, userRemove);
			
			cart.RemoveItem(userRemove);
			cout << endl;
		}
		
		//if user decides to change the item quantity
		if (userOption == 'c') {
			
			//gets item name that user wants to change
			cout << "CHANGE ITEM QUANTITY" << endl;
			cin.ignore(256, '\n');
			cout << "Enter the item name:" << endl;
			getline(cin, userChange);

			item.SetName(userChange);

			cart.ModifyItem(item);
			cout << endl;

		}
		
		//if user wants to output the items descriptions
		if (userOption == 'i') {
		
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
			cout << cart.GetCustomerName() << "'s Shopping Cart - " << cart.GetDate() << endl;
			cout << endl;
			//calls print description function
			cart.PrintDescriptions();
			cout << endl;
			
		}
		
		//if user wants to output everything in cart
		if (userOption == 'o') {
			
			cout << "OUTPUT SHOPPING CART" <<endl;
			
			cout << cart.GetCustomerName() << "'s Shopping Cart - " << cart.GetDate() << endl;
		
			cout << "Number of Items: " << cart.GetNumItemsInCart() << endl;
			cout << endl;
			cart.PrintTotal();
			cout << endl;
			totalCost = cart.GetCostOfCart();
			cout << "Total: $" << totalCost << endl;
			cout << endl;

		}
		

	}

	return 0;
}
