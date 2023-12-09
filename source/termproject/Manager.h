#pragma once
#include "Person.h"

class Manager : public Person {
public:
	Manager(string name);
	void find(vector<Product>products);
};