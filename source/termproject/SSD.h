#pragma once
#include "Product.h"

class SSD : public Product {
	static int num;
	string form_factor;
	int capacity;
public:
	static int getNum();
	void view();
	void write();
	SSD(string name, string manufacturer, string form_factor, int capacity);
};