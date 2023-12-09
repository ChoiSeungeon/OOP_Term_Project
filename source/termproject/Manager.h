#pragma once
#include "Person.h"

class Manager : public Person {
public:
	Manager(string id, string password, string name, string pos);
	void find(vector<Product*>products);
	void add(vector<Product*>products);
	void deleteProduct(vector<Product*>products);
};