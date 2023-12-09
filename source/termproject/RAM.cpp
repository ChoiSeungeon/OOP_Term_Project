#include "RAM.h"

int RAM::num = 0;

int RAM::getNum() { return num; }

void RAM::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "���� : " << classifiction << endl;
	cout << "�뷮 : ";
	cout << capacity << "GB" << endl;
}

void RAM::write(ofstream& os) {
	os << "r " << getName() << " " << getManufacturer() << " " << classifiction << " "
		<< capacity << endl;
}

RAM::RAM(string name, string manufacturer, string classifiction, int capacity) : Product(name, manufacturer) {
	this->classifiction = classifiction;
	this->capacity = capacity;
	num++;
}