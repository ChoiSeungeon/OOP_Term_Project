#include "Person.h"

Person::Person(string id, string password, string name, string pos) {
	this->name = name;
	this->id = id;
	this->password = password;
	this->pos = pos;
}

string Person::getName() {
	return name;
}

string Person::getId() {
	return id;
}

string Person::getPassword() {
	return password;
}

string Person::getPos() {
	return pos;
}

void Person::write(ostream& os) {
	os << id << " " << password << " " << name << " " << pos << endl;
}