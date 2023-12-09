#include "Menu.h"

Menu::Menu(SystemManager* systemManager) {
	this->systemManager = systemManager;
}

Menu::~Menu() {
	systemManager->~SystemManager();
}

// 물품 추가
void Menu::product_add() {
	string product_name;
	int product_num;
	int input_back;
	cout << "**********************************" << endl;
	cout << "물품 추가 " << endl;
	cout << "**********************************" << endl;
	cout << "추가하실 물품명을 입력하십시오: ";
	cin >> product_name;
	cout << "추가하실 물품수량을 입력하십시오: ";
	cin >> product_num;
	cout << endl;
	back(1); // 함수 고유 번호 전달해서 아니오 입력했을 때 함수 되돌아오기
	cout << "**********************************" << endl;
}

// 물품 삭제
void Menu::product_delete() {
	string product_name;
	int product_num;
	int input_back;
	cout << "**********************************" << endl;
	cout << "물품 삭제 " << endl;
	cout << "**********************************" << endl;
	cout << "삭제하실 물품명을 입력하십시오: ";
	cin >> product_name;
	cout << "삭제하실 물품수량을 입력하십시오: ";
	cin >> product_num;
	back(2); // 함수 고유 번호 전달해서 아니오 입력했을 때 함수 되돌아오기
}

// 물품 조회
void Menu::product_find() {
	int input_num;
	int input_back;
	cout << "**********************************" << endl;
	cout << "물품 조회 " << endl;
	cout << "**********************************" << endl;
	cout << "어떻게 조회 하시겠습니까?";
	cout << "1. 물품 명";
	cout << "2. 물품 종류";
	cin >> input_num;
	switch (input_num) {
	case 1:
		product_find_name();
		break;
	case 2:
		product_find_category();
		break;
	}
	back(3); // 함수 고유 번호 전달해서 아니오 입력했을 때 함수 되돌아오기
}
void Menu::back(int num) {
	int input_back;
	cout << "이전으로 돌아가시겠습니까?(0 : yes, 1 : no) : ";
	cin >> input_back;
	system("cls");
	switch (input_back) {
	case 0:
		break;
	case 1:
		if (num == 1) product_add();
		else if (num == 2) product_delete();
		else if (num == 3) product_find();
		else if (num == 4) login_menu();
		break;
	default:
		cout << "제대로 된 숫자를 입력하시오." << endl;;
		break;
	}
}

void Menu::product_find_name() {

}

void Menu::product_find_category() {

}

void Menu::main_menu(Person* person) {
	int input_num;
	while (1) {
		cout << "**********************************" << endl;
		cout << "물품 관리 서비스" << endl;;
		cout << "**********************************" << endl;
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "1. 물품 추가" << endl;
		cout << "2. 물품 삭제" << endl;
		cout << "3. 물품 조회" << endl;
		cout << "입력 : ";
		cin >> input_num;
		system("cls");
		switch (input_num) {
		case 1:
			if (person->getPos() == "M")
				product_add();
			else {
				cout << "일반 회원은 사용할 수 없는 기능입니다." << endl;
			}
			break;
		case 2:
			if (person->getPos() == "M")
				product_delete();
			else
				cout << "일반 회원은 사용할 수 없는 기능입니다." << endl;
			break;
		case 3:
			product_find();
			break;
		}
	}
}

void Menu::login() {
	string id, password;
	vector<Person*>* person_list = systemManager->getPersonV();
	while (1) {
		cout << "아이디 : "; cin >> id;
		cout << "비밀번호 : "; cin >> password;
		for (auto& p : *person_list) {
			if (p->getId() == id && p->getPassword() == password) {
				system("cls");
				main_menu(p);
			}
		}
		cout << "아이디 혹은 비밀번호가 틀렸습니다." << endl;
		Sleep(2000);
		system("cls");
		back(4);
	}
}

void Menu::join() {
	string name, id, password, pos = "m";
	vector<Person*>* person_list = systemManager->getPersonV();
	while (1) {
		while (1) {
			cout << "이름 : "; cin >> name;
			cout << "아이디 : "; cin >> id;
			cout << "비밀번호 : "; cin >> password;
			for (auto& p : *person_list) {
				if (p->getId() == id) {
					cout << "중복된 아이디입니다." << endl;
					break;
				}
			}
			Person* person = new Member(id, password, name, pos);
			person_list->push_back(person);
			login_menu();
		}
		Sleep(2000);
		system("cls");
		back(4);
	}
}

void Menu::login_menu() {
	int input_num;
	cout << "**********************************" << endl;
	cout << "로그인" << endl;;
	cout << "**********************************" << endl;
	cout << "무엇을 하시겠습니까?" << endl;
	cout << "1. 로그인 " << endl;
	cout << "2. 회원가입 " << endl;
	cout << "3. 종료 " << endl;
	cout << "입력 : "; cin >> input_num;
	system("cls");
	switch (input_num) {
	case 1:
		login();
		break;
	case 2:
		join();
		break;
	case 3:
		this->~Menu();
		exit(1);
	}
	
}