#include "SystemManager.h"

SystemManager::SystemManager() {
	product_list = new vector<Product*>();
	string detail, name, manufacturer, temp, date;
	bool duflag = false;
	Product* product = NULL, *duproduct = NULL;
	ifstream file("Product.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			file >> detail >> name >> manufacturer;

			if (detail == "E")
				break;

			for (auto& p : *product_list) {
				if (p->getName() == name) {
					duflag = true;
					duproduct = p;
					break;
				}
			}

			if (detail == "k") {
				string arragement, type;
				file >> arragement >> type >> date;
				product = new Keyboard(name, manufacturer, arragement, type, date);
			}
			else if (detail == "m") {
				bool mouse_cable;
				file >> temp >> date;
				mouse_cable = (temp == "1") ? true : false;
				product = new Mouse(name, manufacturer, mouse_cable, date);
			}
			else if (detail == "c") {
				string classification;
				int core_num, thread_num, L3_cache, bulid_in_graphics;
				file >> classification >> core_num >> thread_num >> L3_cache >> temp >> date;
				bulid_in_graphics = (temp == "1") ? true : false;
				product = new CPU(name, manufacturer, classification, core_num, thread_num, L3_cache, bulid_in_graphics, date);
			}
			else if (detail == "h") {
				string classification, recording_method;
				int capacity, RPM;
				file >> classification >> recording_method >> capacity >> RPM >> date;
				product = new HDD(name, manufacturer, classification, capacity, RPM, recording_method, date);
			}
			else if (detail == "M") {
				int inch;
				string scan_rate, resolution;
				file >> inch >> scan_rate >> resolution >> date;
				product = new Monitor(name, manufacturer, inch, scan_rate, resolution, date);
			}
			else if (detail == "r") {
				string classifiction;
				int capacity;
				file >> classifiction >> capacity >> date;
				product = new RAM(name, manufacturer, classifiction, capacity, date);
			}
			else if (detail == "s") {
				string form_factor;
				int capacity;
				file >> form_factor >> capacity >> date;
				product = new SSD(name, manufacturer, form_factor, capacity, date);
			}
			else if (detail == "v") {
				string chip_set, chip_set_detail;
				int port_num, memory;
				file >> chip_set >> chip_set_detail >> port_num >> memory >> date;
				product = new VGA(name, manufacturer, chip_set, chip_set_detail, port_num, memory, date);
			}

			if (duflag) {
				duproduct->setNum(duproduct->getNum() + 1);
				delete product;
				duflag = false;
			}
			else
				product_list->push_back(product);
		}
	}
	else {
		cout << "Unable to open file";
	}
	file.close();
	
	person_list = new vector<Person*>();
	string id, password, pname, pos;
	ifstream file2("Person.txt");
	
	if (file2.is_open()) {
		while (!file2.eof()) {
			file2 >> id >> password >> pname >> pos;
			Person* person;
			if (pos == "M")
				person = new Manager(id, password, pname, pos);
			else
				person = new Member(id, password, pname, pos);

			if (id != "E")
				person_list->push_back(person);
		}
	}
	else {
		cout << "Unable to open file";
	}
	file2.close();
}

SystemManager::~SystemManager() {
	ofstream file("Product.txt");
	for (auto& p : *product_list) {
		for (int i = 0; i < p->getNum(); i++) {
			p->write(file);
		}
		delete p;
	}
	file << "E";
	file.close();

	ofstream file2("Person.txt");
	for (auto& p : *person_list) {
		p->write(file2);
		delete p;
	}
	file2 << "E";
	file2.close();
}

vector<Product*>* SystemManager::getProductV() {
	return product_list;
}

vector<Person*>* SystemManager::getPersonV() {
	return person_list;
}