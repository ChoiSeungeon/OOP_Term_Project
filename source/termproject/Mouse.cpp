#include "Mouse.h"
int Mouse::getNum() { return num; }

void Mouse::setNum(int num) { this->num = num; }

void Mouse::view() {
	cout << "이름 : " << getName() << endl;
	if(mouse_cable)
		cout << "유무선 여부 : O" << endl;
	else
		cout << "유무선 여부 : X" << endl;
	cout << "수량 : " << this->num << endl;
}

void Mouse::write(ofstream& os) {
	os << "m " << getName() << " " << getManufacturer() << " " << mouse_cable << " " << getDate() << endl;
}

Mouse::Mouse(string name, string manufacturer, bool mouse_cable, string date) : Product(name, manufacturer, date) {
	this->mouse_cable = mouse_cable;
	num = 1;
}