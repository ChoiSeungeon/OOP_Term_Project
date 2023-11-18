#include "ProductManager.h"

vector<Product*> getProducts() {
	vector<Product*> products;
	string line, detail, name, manufacturer;
	Product* product;
	ifstream file("Products.txt");

	if (file.is_open()) {
		while (getline(file, line)) {
			stringstream data(line);
			data >> detail;
			data >> name;
			data >> manufacturer;
			if (detail == "k") {
				string arragement, type;
				data >> arragement;
				data >> type;
				product = new Keyboard(name, manufacturer, arragement, type);
			}
			else if (detail == "m") {
				string temp;
				bool mouse_cable;
				data >> temp;
				if (temp == "true")
					mouse_cable = true;
				else
					mouse_cable = false;
				product = new Mouse(name, manufacturer, mouse_cable);
			}
			products.push_back(product);
		}
		file.close();
	}
	else {
		cout << "Unable to open file";
	}

	return products;
}