#include "SSD.h"

int SSD::num = 0;

int SSD::getNum() { return num; }

void SSD::setNum(int num) { this->num = num; }

void SSD::view() {
	cout << "ÀÌ¸§ : " << getName() << endl;
	cout << "ÆûÆåÅÍ : " << form_factor << endl;
	cout << "¿ë·® : ";
	if (capacity < 1000)
		cout << capacity << "GB" << endl;
	else
		cout << capacity / 1000 << "TB" << endl;
}

void SSD::write(ofstream& os) {
	os << "s " << getName() << " " << getManufacturer() << " " << form_factor << " "
		<< capacity << " " << getDate() << endl;
}

SSD::SSD(string name, string manufacturer, string form_factor, int capacity, string date) : Product(name, manufacturer, date) {
	this->form_factor = form_factor;
	this->capacity = capacity;
	num++;
}