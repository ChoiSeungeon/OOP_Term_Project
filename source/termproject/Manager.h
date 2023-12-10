#pragma once
#include "Person.h"

class Manager : public Person {
public:
	Manager(string id, string password, string name, string pos);
	void view(Product* product);
	void add(vector<Product*>*products);
	void deleteProduct(vector<Product*>*products);
};