#pragma once
#include "Manager.h"
#include "Member.h"

class SystemManager {
	vector<Product*>* product_list;
	vector<Person*>* person_list;
public:
	SystemManager();
	~SystemManager();
	vector<Product*>* getProductV();
	vector<Person*>* getPersonV();
	
};