#include "menu.h"
#include "ProductManager.h"

int main(void) {
	vector<Product*> products = getProducts();

	for (auto& p : products)
		p->view();

	//main_menu();
}