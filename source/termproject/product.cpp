#include "Product.h"

int Product::num = 0;

int Product::getNum() { return num; }

void Product::setNum(int num) { this->num = num; }

string Product::getName() { return name; }

string Product::getManufacturer() { return manufacturer; }

string Product::getDate() { return date; }

void Product::setDate(string date) {
	this->date = date;
}

Product::Product(string name, string manufacturer, string date) {
	this->name = name;
	this->manufacturer = manufacturer;
	this->date = date;
	num++;
}