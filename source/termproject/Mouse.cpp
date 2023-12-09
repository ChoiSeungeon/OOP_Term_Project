#include "Mouse.h"

int Mouse::num = 0;

int Mouse::getNum() { return num; }

void Mouse::view() {
	cout << "�̸� : " << getName() << endl;
	if(mouse_cable)
		cout << "������ ���� : O" << endl;
	else
		cout << "������ ���� : X" << endl;
}

void Mouse::write(ofstream& os) {
	os << "m " << getName() << " " << getManufacturer() << " " << mouse_cable << endl;
}

Mouse::Mouse(string name, string manufacturer, bool mouse_cable) : Product(name, manufacturer) {
	this->mouse_cable = mouse_cable;
	num++;
}