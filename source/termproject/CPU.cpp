#include "CPU.h"
int CPU::getNum() { return num; }

void CPU::setNum(int num) { this->num = num; }

void CPU::view() {
	cout << "이름 : " << getName() << endl;
	cout << "종류 : " << classification << endl;
	cout << "코어 수 : " << core_num << endl;
	cout << "스레드 수 : " << thread_num << endl;
	cout << "캐쉬 : " << L3_cache << endl;
	if (bulid_in_graphics)
		cout << "내장그래픽 여부 : O" << endl;
	else
		cout << "내장그래픽 여부 : X" << endl;
	cout << "수량 : \t" << this->num << endl;
}

void CPU::write(ofstream& os) {
	os << "c " << getName() << " " << getManufacturer() << " " << classification << " "
		<< core_num << " " << thread_num << " " << L3_cache << " " << bulid_in_graphics << " " << getDate() << endl;
}

CPU::CPU(string name, string manufacturer, string classification, int core_num, int thread_num, int L3_cache, bool bulid_in_graphics, string date) : Product(name, manufacturer, date) {
	this->classification = classification;
	this->core_num = core_num;
	this->thread_num = thread_num;
	this->L3_cache = L3_cache;
	this->bulid_in_graphics = bulid_in_graphics;
	num = 1;
}