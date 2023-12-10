#pragma once
#include "Product.h"

class RAM : public Product {
	int num;
	string classifiction;
	int capacity;
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	RAM(string name, string manufacturer, string classifiction, int capacity, string date);
};
