#include "Member.h"

Member::Member(string id, string password, string name, string pos) :
	Person(id, password, name, pos) {}

void Member::find(vector<Product*>products) {
	string product_name;
	cout << "찾으려고 하는 물품의 이름을 입력하시오: " << endl;
	for (auto& e : products) {
		if (e->getName() == product_name) {
			e->view();
			//e.getDate(); --> 시간 추가
		}
	}
}