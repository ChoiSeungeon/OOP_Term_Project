#pragma once
#include "Product.h"

class Monitor : public Product {
	int num;
	int inch;
	string scan_rate;
	string resolution;	
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	Monitor(string name, string manufacturer, int inch, string scan_rate, string resolution, string date);
};
