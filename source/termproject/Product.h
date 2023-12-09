#pragma once
#include "pgm.h"

class Product {
	static int num;
	string name;
	string manufacturer;
	string date;
public:
	Product(string name, string manufacturer, string date);
	virtual int getNum();
	virtual void setNum(int num);
	virtual void view() = 0;
	virtual void write(ofstream& os) = 0;
	string getName();
	string getManufacturer();
	string getDate();
};