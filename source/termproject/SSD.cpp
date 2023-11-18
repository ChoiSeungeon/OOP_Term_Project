#include "SSD.h"

int SSD::num = 0;

int SSD::getNum() { return num; }

void SSD::view() {
	cout << "ÀÌ¸§ : " << getName() << endl;
	cout << "ÆûÆåÅÍ : " << form_factor << endl;
	cout << "¿ë·® : ";
	if (capacity < 1000)
		cout << capacity << "GB" << endl;
	else
		cout << capacity / 1000 << "TB" << endl;
}

void SSD::write() {

}

SSD::SSD(string name, string manufacturer, string form_factor, int capacity) : Product(name, manufacturer) {
	this->form_factor = form_factor;
	this->capacity = capacity;
	num++;
}