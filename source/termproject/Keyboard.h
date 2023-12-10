#pragma once
#include "Product.h"

class Keyboard : public Product {
	int num;
	string arragement;
	string type;
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	Keyboard(string name, string manufacturer, string arragement, string type, string date);
};