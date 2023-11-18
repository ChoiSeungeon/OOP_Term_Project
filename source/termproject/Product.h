#pragma once
#include "pgm.h"

class Product {
	static int num;
	string name;
	string manufacturer;
public:
	Product(string name, string manufacturer);
	static int getNum();
	virtual void view() = 0;
	virtual void write() = 0;
	string getName();
};