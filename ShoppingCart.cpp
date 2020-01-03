#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
	customerName = "none";
	currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
	customerName = name;
	currentDate = date;
}

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

void ShoppingCart::AddItem(ItemToPurchase item) {
	cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
	int p=0;
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

void ShoppingCart::ModifyItem(ItemToPurchase item) {
	int p = 0;
	int check = 0;
	cout << "Enter the new quantity:" << endl;
	cin >> p;

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

int ShoppingCart::GetNumItemsInCart() const{
	int temp = 0;
	for (unsigned int i = 0; i < cartItems.size(); i++) {
		temp = temp + (cartItems[i].GetQuantity());
	}
	return temp;
}

int ShoppingCart::GetCostOfCart() const{
	int temp =0;
	for (unsigned int i = 0; i < cartItems.size(); i++) {
		temp = temp + (cartItems[i].GetPrice() * cartItems[i].GetQuantity());
	}
	return temp;
}

void ShoppingCart::PrintTotal() {
	int temp;


	if (cartItems.size() == 0) {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	else {

		for (unsigned int i = 0; i < cartItems.size(); i++) {
			temp = cartItems[i].GetQuantity() *cartItems[i].GetPrice();
			cout << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << cartItems[i].GetPrice() << " = $" << temp << endl;
			//temp2 = temp2 + temp;
		}

	//	cout << "Total: $" << temp2 << endl;
	}

}

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