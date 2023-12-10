#include "VGA.h"
int VGA::getNum() { return num; }

void VGA::setNum(int num) { this->num = num; }

void VGA::view() {
	cout << "이름 : " << getName() << endl;
	cout << "칩셋 : " << chip_set << " " << chip_set_detail << endl;
	cout << "포트 수 : " << port_num << endl;
	cout << "메모리 : " << memory << "GB" << endl;
	cout << "수량 : " << this->num << endl;
}

void VGA::write(ofstream& os) {
	os << "v " << getName() << " " << getManufacturer() << " " << chip_set << " "
		<< chip_set_detail << " " << port_num << " " << memory << " " << getDate() << endl;
}

VGA::VGA(string name, string manufacturer, string chip_set, string chip_set_detail, int port_num, int memory, string date) : Product(name, manufacturer, date) {
	this->chip_set = chip_set;
	this->chip_set_detail = chip_set_detail;
	this->port_num = port_num;
	this->memory = memory;
	num = 1;
}