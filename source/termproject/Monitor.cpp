#include "Monitor.h"

int Monitor::num = 0;

int Monitor::getNum() { return num; }

void Monitor::view() {
	cout << "이름 : " << getName() << endl;
	cout << "크기 : " << inch << "inch" << endl;
	cout << "주사율 : " << scan_rate << endl;
	cout << "해상도 : " << resolution << endl;
}

void Monitor::write(ofstream& os) {
	os << "M " << getName() << " " << getManufacturer() << " " << inch << " "
		<< scan_rate << " " << resolution << endl;
}

Monitor::Monitor(string name, string manufacturer, int inch, string scan_rate, string resolution) : Product(name, manufacturer) {
	this->inch = inch;
	this->scan_rate = scan_rate;
	this->resolution = resolution;
	num++;
}