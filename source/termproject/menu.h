#pragma once
#include "SystemManager.h"

class Menu {
	SystemManager* systemManager;
public:
	Menu(SystemManager* systemManager);
	~Menu();
	void product_add();		// 물품 추가
	void product_delete();	// 물품 삭제
	void product_find();	// 물품 조회
	void product_find_name();// 물품 명으로 조회
	void product_find_category();// 물품 종류로 조회
	void back(int num);	// 이전으로
	void main_menu(Person* person);	// 메인
	void login_menu();
	void login();
	void join();
};
