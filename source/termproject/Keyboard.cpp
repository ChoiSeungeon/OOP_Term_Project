#include "Keyboard.h"
int Keyboard::getNum() { return num; }

void Keyboard::setNum(int num) { this->num = num; }

void Keyboard::view() {
	cout << "이름 : " << getName() << endl;
	cout << "키 배열 : " << arragement << endl;
	cout << "타입 : " << type << endl;
	cout << "수량 : " << this->num << endl;
}

void Keyboard::write(ofstream& os) {
	os << "k " << getName() << " " << getManufacturer() << " " << arragement << " "
		<< type << " " << getDate() << endl;
}

Keyboard::Keyboard(string name, string manufacturer, string arragement, string type, string date) : Product(name, manufacturer, date){
	this->type = type;
	this->arragement = arragement;
	num = 1;
}