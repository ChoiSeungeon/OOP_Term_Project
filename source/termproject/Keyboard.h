#pragma once
#include "Product.h"

class Keyboard : public Product {
	static int num;
	string arragement;
	string type;
public:
	static int getNum();
	void view();
	void write();
	Keyboard(string name, string manufacturer, string arragement, string type);
};