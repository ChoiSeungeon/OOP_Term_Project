#include "HDD.h"

int HDD::num = 0;

int HDD::getNum() { return num; }

void HDD::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "���� : " << classification << endl;
	cout << "�뷮 : ";
	if (capacity < 1000)
		cout << capacity << "GB" << endl;
	else
		cout << capacity/1000 << "TB" << endl;
	cout << "ȸ���� : " << RPM << "RPM" << endl;
	cout << "��� ��� : " << recording_method << endl;
}

void HDD::write() {

}

HDD::HDD(string name, string manufacturer, string classification, int capacity, int RPM, string recording_method) : Product(name, manufacturer) {
	this->classification = classification;
	this->capacity = capacity;
	this->RPM = RPM;
	this->recording_method = recording_method;
	num++;
}