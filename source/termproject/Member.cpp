#include "Member.h"

Member::Member(string id, string password, string name, string pos) :
	Person(id, password, name, pos) {}

void Member::view(Product* product) {
	product->view();
}