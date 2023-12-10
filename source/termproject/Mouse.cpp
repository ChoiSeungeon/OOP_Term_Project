#include "Mouse.h"
int Mouse::getNum() { return num; }

void Mouse::setNum(int num) { this->num = num; }

void Mouse::view() {
	cout << "�̸� : " << getName() << endl;
	if(mouse_cable)
		cout << "������ ���� : O" << endl;
	else
		cout << "������ ���� : X" << endl;
	cout << "���� : " << this->num << endl;
}

void Mouse::write(ofstream& os) {
	os << "m " << getName() << " " << getManufacturer() << " " << mouse_cable << " " << getDate() << endl;
}

Mouse::Mouse(string name, string manufacturer, bool mouse_cable, string date) : Product(name, manufacturer, date) {
	this->mouse_cable = mouse_cable;
	num = 1;
}