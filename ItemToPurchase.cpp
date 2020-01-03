#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0;
	itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string desc, int price, int quant) {
	itemName = name;
	itemDescription = desc;
	itemPrice = price;
	itemQuantity = quant;
}

string ItemToPurchase::GetName() const{
	return itemName;
}

int ItemToPurchase::GetPrice() const {
	return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}

string ItemToPurchase::GetDescription() const {
	return itemDescription;
}

void ItemToPurchase::SetName(string name) {
	itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
	itemPrice = price;
}

void ItemToPurchase::SetQuantity(int quant) {
	itemQuantity = quant;
}

void ItemToPurchase::SetDescription(string desc) {
	itemDescription = desc;
}
