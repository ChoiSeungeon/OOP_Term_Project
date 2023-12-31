#include "Monitor.h"
int Monitor::getNum() { return num; }

void Monitor::setNum(int num) { this->num = num; }

void Monitor::view() {
	cout << "이름 : " << getName() << endl;
	cout << "크기 : " << inch << "inch" << endl;
	cout << "주사율 : " << scan_rate << endl;
	cout << "해상도 : " << resolution << endl;
	cout << "수량 : " << this->num << endl;
}

void Monitor::write(ofstream& os) {
	os << "M " << getName() << " " << getManufacturer() << " " << inch << " "
		<< scan_rate << " " << resolution << " " << getDate() << endl;
}

Monitor::Monitor(string name, string manufacturer, int inch, string scan_rate, string resolution, string date) : Product(name, manufacturer, date) {
	this->inch = inch;
	this->scan_rate = scan_rate;
	this->resolution = resolution;
	num = 1;
}