#pragma once
#include "Product.h"

class VGA : public Product {
	static int num;
	string chip_set;
	string chip_set_detail;
	int port_num;
	int memory;
public:
	static int getNum();
	void view();
	void write(ofstream& os);
	VGA(string name, string manufacturer, string chip_set, string chip_set_detail, int port_num, int memory);
};

