#include "RAM.h"

int RAM::num = 0;

int RAM::getNum() { return num; }

void RAM::view() {
	cout << "이름 : " << getName() << endl;
	cout << "종류 : " << classifiction << endl;
	cout << "용량 : ";
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