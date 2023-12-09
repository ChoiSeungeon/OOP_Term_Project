#include "Manager.h"
#include <time.h>

Manager::Manager(string name) : Person(name) { }

void Manager::find(vector<Product>products) {
	string product_name;
	cout << "찾으려고 하는 물품의 이름을 입력하시오: " << endl;
	for (auto& e : products) {
		if (e.getName() == product_name) {
			e.view();
			
		}
	}
}