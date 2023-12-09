#pragma once
#include "Product.h"

class CPU : public Product {
	static int num;
	string classification;
	int core_num;
	int thread_num;
	int L3_cache;
	bool bulid_in_graphics;
public:
	int getNum();
	void setNum(int num);
	void view();
	void write(ofstream& os);
	CPU(string name, string manufacturer, string classification, int core_num, int thread_num, int L3_cache, bool bulid_in_graphics, string date);
};