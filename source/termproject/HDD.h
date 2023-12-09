#pragma once
#include "Product.h"

class HDD : public Product {
	static int num;
	string classification, recording_method;
	int capacity;
	int RPM;
public:
	static int getNum();
	void view();
	void write(ofstream& os);
	HDD(string name, string manufacturer, string classification, int capacity, int RPM, string recording_method);
};
