#pragma once
#include "Product.h"

class HDD : public Product {
	static int num;
	string classification;
	int capacity;
	int RPM;
	string recording_method;
public:
	static int getNum();
	void view();
	void write();
	HDD(string name, string manufacturer, string classification, int capacity, int RPM, string recording_method);
};
