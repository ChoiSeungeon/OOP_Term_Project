#pragma once
#include "Person.h"

class Member : public Person {
public:
	Member(string id, string password, string name, string pos);
	void view(Product* product);
};