#include "VGA.h"
int VGA::getNum() { return num; }

void VGA::setNum(int num) { this->num = num; }

void VGA::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "Ĩ�� : " << chip_set << " " << chip_set_detail << endl;
	cout << "��Ʈ �� : " << port_num << endl;
	cout << "�޸� : " << memory << "GB" << endl;
	cout << "���� : " << this->num << endl;
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