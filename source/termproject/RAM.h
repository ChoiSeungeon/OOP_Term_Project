#pragma once
#include "Product.h"

class RAM : public Product {
	static int num;
	string classifiction;
	int capacity;
public:
	static int getNum();
	void view();
	void write();
	RAM(string name, string manufacturer, string classifiction, int capacity);

};
