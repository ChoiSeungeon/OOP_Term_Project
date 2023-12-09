#pragma once
#include "CPU.h"
#include "HDD.h"
#include "Keyboard.h"
#include "Monitor.h"
#include "Mouse.h"
#include "RAM.h"
#include "SSD.h"
#include "VGA.h"

class SystemManager {
	
	//vector<Person> Person_list
public:
	vector<Product*> product_list;
	SystemManager();
	~SystemManager();
};