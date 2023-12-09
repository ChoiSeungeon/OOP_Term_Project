#include "menu.h"
#include "SystemManager.h"

int main(void) {
	SystemManager* systemManager = new SystemManager();
	Menu menu(systemManager);

	menu.login_menu();
}