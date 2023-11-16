#pragma once
#include "pgm.h"

class Product {
	static int totalNum;
	string name;
public:
	Product(string name);
	static int getTotalNum();
};
