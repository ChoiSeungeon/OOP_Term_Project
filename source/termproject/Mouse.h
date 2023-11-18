#pragma once
#include "Product.h"

class Mouse : public Product {
	static int num;
	bool mouse_cable;
public:
	static int getNum();
	void view();
	void write();
	Mouse(string name, string manufacturer, bool mouse_cable);
};
