#pragma once
#include "pgm.h"
#include "CPU.h"
#include "HDD.h"
#include "Keyboard.h"
#include "Monitor.h"
#include "Mouse.h"
#include "RAM.h"
#include "SSD.h"
#include "VGA.h"

class Person {
	string name, id, password, pos;
public:
	Person(string id, string password, string name, string pos);
	string getName();
	string getId();
	string getPassword();
	string getPos();
	void write(ostream& os);
	virtual void view(Product* products) = 0;
};