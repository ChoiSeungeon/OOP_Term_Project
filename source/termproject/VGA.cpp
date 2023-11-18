#include "VGA.h"

int VGA::num = 0;

int VGA::getNum() { return num; }

void VGA::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "Ĩ�� : " << chip_set << " " << chip_set_detail << endl;
	cout << "��Ʈ �� : " << port_num << endl;
	cout << "�޸� : " << memory << "GB" << endl;
}

void VGA::write() {

}

VGA::VGA(string name, string manufacturer, string chip_set, string chip_set_detail, int port_num, int memory) : Product(name, manufacturer) {
	this->chip_set = chip_set;
	this->chip_set_detail = chip_set_detail;
	this->port_num = port_num;
	this->memory = memory;
	num++;
}