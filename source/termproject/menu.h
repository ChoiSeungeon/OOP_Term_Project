#pragma once
#include "SystemManager.h"

class Menu {
	SystemManager* systemManager;
public:
	Menu(SystemManager* systemManager);
	~Menu();
	void product_add(Person* person);		// 물품 추가
	void product_delete(Person* person);	// 물품 삭제
	void product_find(Person* person);	// 물품 조회
	bool back();	// 이전으로
	void main_menu(Person* person);	// 메인
	void login_menu();
	void login();
	void join();
};
