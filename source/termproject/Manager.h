#pragma once
#include "Person.h"

class Manager : public Person {
public:
	Manager();
	void find(vector<Product>products);
}