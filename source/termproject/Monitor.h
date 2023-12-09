#pragma once
#include "Product.h"

class Monitor : public Product {
	static int num;
	int inch;
	string scan_rate;
	string resolution;	
public:
	static int getNum();
	void view();
	void write(ofstream& os);
	Monitor(string name, string manufacturer, int inch, string scan_rate, string resolution);
};
