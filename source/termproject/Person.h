#pragma once
#include "pgm.h"
#include "Product.h"

class Person {
	string name;

public:
	Person(string name);
	virtual void find(vector<Product>products);
};