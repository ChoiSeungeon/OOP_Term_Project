#pragma once
#include "Product.h"

class Mouse : public Product {
	int num;
	bool mouse_cable;
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	Mouse(string name, string manufacturer, bool mouse_cable, string date);
};
