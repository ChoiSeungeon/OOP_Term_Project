#include "RAM.h"
int RAM::getNum() { return num; }

void RAM::setNum(int num) { this->num = num; }

void RAM::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "���� : " << classifiction << endl;
	cout << "�뷮 : ";
	cout << capacity << "GB" << endl;
	cout << "���� : " << this->num << endl;
}

void RAM::write(ofstream& os) {
	os << "r " << getName() << " " << getManufacturer() << " " << classifiction << " "
		<< capacity << " " << getDate() << endl;
}

RAM::RAM(string name, string manufacturer, string classifiction, int capacity, string date) : Product(name, manufacturer, date) {
	this->classifiction = classifiction;
	this->capacity = capacity;
	num = 1;
}