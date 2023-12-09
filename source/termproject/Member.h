#pragma once
#include "Person.h"

class Member : public Person {
public:
	Member(string id, string password, string name, string pos);
	void find(vector<Product*>products);
};