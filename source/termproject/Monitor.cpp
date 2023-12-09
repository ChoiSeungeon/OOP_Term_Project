#include "Monitor.h"

int Monitor::num = 0;

int Monitor::getNum() { return num; }

void Monitor::setNum(int num) { this->num = num; }

void Monitor::view() {
	cout << "�̸� : " << getName() << endl;
	cout << "ũ�� : " << inch << "inch" << endl;
	cout << "�ֻ��� : " << scan_rate << endl;
	cout << "�ػ� : " << resolution << endl;
}

void Monitor::write(ofstream& os) {
	os << "M " << getName() << " " << getManufacturer() << " " << inch << " "
		<< scan_rate << " " << resolution << " " << getDate() << endl;
}

Monitor::Monitor(string name, string manufacturer, int inch, string scan_rate, string resolution, string date) : Product(name, manufacturer, date) {
	this->inch = inch;
	this->scan_rate = scan_rate;
	this->resolution = resolution;
	num++;
}