#include "SystemManager.h"

SystemManager::SystemManager() {
	string detail, name, manufacturer, temp;
	Product* product;
	ifstream file("Products.txt");
	ifstream file2("Person.txt");

	if (file.is_open()) {
		while (!file.eof()) {
			file >> detail >> name >> manufacturer;
			if (detail == "k") {
				string arragement, type;
				file >> arragement >> type;
				product = new Keyboard(name, manufacturer, arragement, type);
			}
			else if (detail == "m") {
				bool mouse_cable;
				file >> temp;
				mouse_cable = (temp == "1") ? true : false;
				product = new Mouse(name, manufacturer, mouse_cable);
			}
			else if (detail == "c") {
				string classification;
				int core_num, thread_num, L3_cache, bulid_in_graphics;
				file >> classification >> core_num >> thread_num >> L3_cache >> temp;
				bulid_in_graphics = (temp == "1") ? true : false;
				product = new CPU(name, manufacturer, classification, core_num, thread_num, L3_cache, bulid_in_graphics);
			}
			else if (detail == "h") {
				string classification, recording_method;
				int capacity, RPM;
				file >> classification >> recording_method >> capacity >> RPM;
				product = new HDD(name, manufacturer, classification, capacity, RPM, recording_method);
			}
			else if (detail == "M") {
				int inch;
				string scan_rate, resolution;
				file >> inch >> scan_rate >> resolution;
				product = new Monitor(name, manufacturer, inch, scan_rate, resolution);
			}
			else if (detail == "r") {
				string classifiction;
				int capacity;
				file >> classifiction >> capacity;
				product = new RAM(name, manufacturer, classifiction, capacity);
			}
			else if (detail == "s") {
				string form_factor;
				int capacity;
				file >> form_factor >> capacity;
				product = new SSD(name, manufacturer, form_factor, capacity);
			}
			else if (detail == "v") {
				string chip_set, chip_set_detail;
				int port_num, memory;
				file >> chip_set >> chip_set_detail >> port_num >> memory;
				product = new VGA(name, manufacturer, chip_set, chip_set_detail, port_num, memory);
			}

			if(detail != "E")
				product_list.push_back(product);
		}
	}
	else {
		cout << "Unable to open file";
	}
	/*
	if (file2.is_open()) {

	}
	else {
		cout << "Unable to open file";
	}
	*/
}

SystemManager::~SystemManager() {
	ofstream file("Products.txt");
	for (auto& p : product_list) {
		p->write(file);
	}
	file << "E";
}