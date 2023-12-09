#include "Product.h"

int Product::num = 0;

int Product::getNum() { return num; }

string Product::getName() { return name; }

string Product::getManufacturer() { return manufacturer; }

Product::Product(string name, string manufacturer) {
	this->name = name;
	this->manufacturer = manufacturer;
	num++;
}