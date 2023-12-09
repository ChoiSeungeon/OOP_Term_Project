#pragma once
#include "Person.h"

class Member : public Person {
public:
	Member(string name);
	void find(vector<Product>products);
};