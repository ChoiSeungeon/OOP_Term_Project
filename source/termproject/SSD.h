#pragma once
#include "Product.h"

class SSD : public Product {
	static int num;
	string form_factor;
	int capacity;
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	SSD(string name, string manufacturer, string form_factor, int capacity, string date);
};