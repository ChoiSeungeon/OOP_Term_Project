#include "Keyboard.h"

int Keyboard::num = 0;

int Keyboard::getNum() { return num; }

void Keyboard::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "Ű �迭 : " << arragement << endl;
	cout << "Ÿ�� : " << type << endl;
}

void Keyboard::write() {

}

Keyboard::Keyboard(string name, string manufacturer, string arragement, string type) : Product(name, manufacturer){
	this->type = type;
	this->arragement = arragement;
	num++;
}