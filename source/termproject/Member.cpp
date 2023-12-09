#include "Member.h"

Member::Member(string id, string password, string name, string pos) :
	Person(id, password, name, pos) {}

void Member::find(vector<Product*>products) {
	string product_name;
	cout << "ã������ �ϴ� ��ǰ�� �̸��� �Է��Ͻÿ�: " << endl;
	for (auto& e : products) {
		if (e->getName() == product_name) {
			e->view();
			//e.getDate(); --> �ð� �߰�
		}
	}
}