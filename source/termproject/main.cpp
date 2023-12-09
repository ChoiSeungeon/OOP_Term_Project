#include "menu.h"
#include "SystemManager.h"

int main(void) {
	SystemManager systemManager;

	for (auto& p : systemManager.product_list)
		p->view();

	//main_menu();
}