#include "Keyboard.h"

int Keyboard::num = 0;

int Keyboard::getNum() { return num; }

void Keyboard::view() {
	cout << "이름 : " << getName() << endl;
	cout << "키 배열 : " << arragement << endl;
	cout << "타입 : " << type << endl;
}

void Keyboard::write() {

}

Keyboard::Keyboard(string name, string manufacturer, string arragement, string type) : Product(name, manufacturer){
	this->type = type;
	this->arragement = arragement;
	num++;
}