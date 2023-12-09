#include "CPU.h"

int CPU::num = 0;

int CPU::getNum() { return num; }

void CPU::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "���� : " << classification << endl;
	cout << "�ھ� �� : " << core_num << endl;
	cout << "������ �� : " << thread_num << endl;
	cout << "ĳ�� : " << L3_cache << endl;
	if (bulid_in_graphics)
		cout << "����׷��� ���� : O" << endl;
	else
		cout << "����׷��� ���� : X" << endl;
}

void CPU::write(ofstream& os) {
	os << "c " << getName() << " " << getManufacturer() << " " << classification << " "
		<< core_num << " " << thread_num << " " << L3_cache << " " << bulid_in_graphics << endl;
}

CPU::CPU(string name, string manufacturer, string classification, int core_num, int thread_num, int L3_cache, bool bulid_in_graphics) : Product(name, manufacturer) {
	this->classification = classification;
	this->core_num = core_num;
	this->thread_num = thread_num;
	this->L3_cache = L3_cache;
	this->bulid_in_graphics = bulid_in_graphics;
	num++;
}