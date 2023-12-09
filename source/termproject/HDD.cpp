#include "HDD.h"

int HDD::num = 0;

int HDD::getNum() { return num; }

void HDD::setNum(int num) { this->num = num; }

void HDD::view() {
	cout << "이름 : " << getName() << endl;
	cout << "종류 : " << classification << endl;
	cout << "용량 : ";
	if (capacity < 1000)
		cout << capacity << "GB" << endl;
	else
		cout << capacity/1000 << "TB" << endl;
	cout << "회전수 : " << RPM << "RPM" << endl;
	cout << "기록 방식 : " << recording_method << endl;
}

void HDD::write(ofstream& os) {
	os << "h " << getName() << " " << getManufacturer() << " " << classification << " "
		<< recording_method << " " << capacity << " " << RPM << " " << getDate() << endl;
}

HDD::HDD(string name, string manufacturer, string classification, int capacity, int RPM, string recording_method, string date) : Product(name, manufacturer, date) {
	this->classification = classification;
	this->capacity = capacity;
	this->RPM = RPM;
	this->recording_method = recording_method;
	num++;
}