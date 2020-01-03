#include <iostream>
#include <string>

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

using namespace std;



int main(void) {

	string tempName, cusName, tempDate, tempDesc, userRemove, userChange;
	int tempPrice;
	int tempQuant;
	int totalCost;
	char userOption = 'p';

	ShoppingCart cart;
	ItemToPurchase item;

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
	
	

	while (userOption != 'q') {

		cout << "MENU" << endl;
		cout << "a - Add item to cart" << endl;
		cout << "d - Remove item from cart" << endl;
		cout << "c - Change item quantity" << endl;
		cout << "i - Output items' descriptions" << endl;
		cout << "o - Output shopping cart" << endl;
		cout << "q - Quit" << endl;
		cout << endl;

		cout << "Choose an option:";
		cin >> userOption;
		cout << endl;
		

		while (userOption != 'a' && userOption != 'd' && userOption != 'c' && userOption != 'i' && userOption != 'o' && userOption != 'q') {
			cout << "Choose an option:";
			cin >> userOption;
			cout << endl;
			
		}

		if (userOption == 'a') {
			
			cout << "ADD ITEM TO CART" << endl;
			cin.ignore(256, '\n');
			//cin.clear();
			cout << "Enter the item name:" << endl;
			getline(cin, tempName);
			//cin.ignore(256, '\n');
			cout << "Enter the item description:" << endl;
			getline(cin, tempDesc);
			//cin.ignore(256, '\n');
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
		if (userOption == 'd') {
		
			cout << "REMOVE ITEM FROM CART" << endl;
			cin.ignore(256, '\n');
			cout << "Enter name of item to remove:" << endl;
			getline(cin, userRemove);
			
			cart.RemoveItem(userRemove);
			cout << endl;
		}
		if (userOption == 'c') {
		
			cout << "CHANGE ITEM QUANTITY" << endl;
			cin.ignore(256, '\n');
			cout << "Enter the item name:" << endl;
			getline(cin, userChange);

			item.SetName(userChange);

			cart.ModifyItem(item);
			cout << endl;

		}
		if (userOption == 'i') {
		
			cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
			cout << cart.GetCustomerName() << "'s Shopping Cart - " << cart.GetDate() << endl;
			cout << endl;
			cart.PrintDescriptions();
			cout << endl;
			
		}
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


	/*cout << "Item 1" << endl;
	cout << "Enter the item name:" << endl;
	getline(cin, tempName);
	cout << "Enter the item price:" << endl;
	cin >> tempPrice;
	cout << "Enter the item quantity:" << endl;
	cin >> tempQuant;

	ItemToPurchase item;

	cout << endl;

	cout << "Item 2" << endl;
	item.SetName(tempName);
	item.SetPrice(tempPrice);
	item.SetQuantity(tempQuant);



	cin.ignore(256, '\n');

	ItemToPurchase item2;

	cout << "Enter the item name:" << endl;
	getline(cin, tempName);
	cout << "Enter the item price:" << endl;
	cin >> tempPrice;
	cout << "Enter the item quantity:" << endl;
	cin >> tempQuant;  

	item2.SetName(tempName);
	item2.SetPrice(tempPrice);
	item2.SetQuantity(tempQuant);

	cout << endl;


	cout << "TOTAL COST" << endl;
	tempPrice = item.GetPrice()*item.GetQuantity();
	cout << item.GetName() << " " << item.GetQuantity() << " @ $" << item.GetPrice() << " = $" << tempPrice << endl;

	tempPrice2 = item2.GetPrice()*item2.GetQuantity();
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << tempPrice2 << endl;

	cout << endl;

	cout << "Total: $" << (tempPrice + tempPrice2) << endl;

*/

	return 0;
}