#include "Manager.h"
#include <time.h>

Manager::Manager(string name) : Person(name) { }

void Manager::find(vector<Product>products) {
	string product_name;
	cout << "ã������ �ϴ� ��ǰ�� �̸��� �Է��Ͻÿ�: " << endl;
	for (auto& e : products) {
		if (e.getName() == product_name) {
			e.view();
			
		}
	}
}