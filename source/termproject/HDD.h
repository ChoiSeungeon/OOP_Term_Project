#pragma once
#include "Product.h"

class HDD : public Product {
	int num;
	string classification, recording_method, date;
	int capacity;
	int RPM;
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	HDD(string name, string manufacturer, string classification, int capacity, int RPM, string recording_method, string date);
};
