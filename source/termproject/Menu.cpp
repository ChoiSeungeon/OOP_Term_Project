#include "Menu.h"

Menu::Menu(SystemManager* systemManager) {
	this->systemManager = systemManager;
}

Menu::~Menu() {
	delete systemManager;
}

bool Menu::back() {
	int input_back;
	while (true) {
		cout << "이전으로 돌아가시겠습니까?(1 : yes, 0 : no) : ";
		cin >> input_back;
		system("cls");
		if (input_back == 1)
			return false;
		else if (input_back == 0)
			return true;
		else {
			cout << "올바른 숫자를 입력하시오." << endl;;
			Sleep(2000);
			system("cls");
		}
	}
}

// 물품 추가
void Menu::product_add(Person* person) {
	bool flag = true;
	Manager* manager = (Manager*) person;
	vector<Product*>* productList = systemManager->getProductV();
	while (flag) {
		system("cls");
		cout << "**********************************" << endl;
		cout << "물품 추가 " << endl;
		cout << "**********************************" << endl;
		manager->add(productList);
		flag = back();
	}
}

// 물품 삭제
void Menu::product_delete(Person* person) {
	bool flag = true;
	Manager* manager = (Manager*)person;
	vector<Product*>* productList = systemManager->getProductV();
	while (flag) {
		system("cls");
		cout << "**********************************" << endl;
		cout << "물품 삭제 " << endl;
		cout << "**********************************" << endl;
		cout << "물품 목록 " << endl;
		cout << "**********************************" << endl;
		for (auto& p : *productList) {
			person->view(p);
			cout << "**********************************" << endl;
		}
		manager->deleteProduct(productList);
		flag = back();
		system("cls");
	}
}

// 물품 조회
void Menu::product_find(Person* person) {
	int input_num;
	bool flag = true;
	string productName;
	Product* product = NULL;
	vector<Product*>* productList = systemManager->getProductV();
	while (flag) {
		system("cls");
		cout << "**********************************" << endl;
		cout << "물품 조회 " << endl;
		cout << "**********************************" << endl;
		cout << "1. 물품 오름차순으로 출력(이름)" << endl;
		cout << "2. 물품 내림차순으로 출력(이름)" << endl;
		cout << "3. 물품 오름차순으로 출력(수량)" << endl;
		cout << "4. 물품 내림차순으로 출력(수량)" << endl;
		cout << "5. 이름으로 조회" << endl;
		cout << "입력 : "; cin >> input_num;
		system("cls");
		switch (input_num) {
		case 1:
			cout << "**********************************" << endl;
			cout << "물품 오름차순으로 출력(이름)" << endl;
			cout << "**********************************" << endl;
			sort(productList->begin(), productList->end(), [](Product* p1, Product* p2) {
				return p1->getName() > p2->getName(); });
			for (auto& p : *productList) {
				person->view(p);
				cout << "**********************************" << endl;
			}
			break;
		case 2:
			cout << "**********************************" << endl;
			cout << "물품 내림차순으로 출력(이름)" << endl;
			cout << "**********************************" << endl;
			sort(productList->begin(), productList->end(), [](Product* p1, Product* p2) {
				return p1->getName() < p2->getName(); });
			for (auto& p : *productList) {
				person->view(p);
				cout << "**********************************" << endl;
			}
			break;
		case 3:
			cout << "**********************************" << endl;
			cout << "물품 오름차순으로 출력(수량)" << endl;
			cout << "**********************************" << endl;
			sort(productList->begin(), productList->end(), [](Product* p1, Product* p2) {
				return p1->getNum() > p2->getNum(); });
			for (auto& p : *productList) {
				person->view(p);
				cout << "**********************************" << endl;
			}
			break;
		case 4:
			cout << "**********************************" << endl;
			cout << "물품 내림차순으로 출력(수량)" << endl;
			cout << "**********************************" << endl;
			sort(productList->begin(), productList->end(), [](Product* p1, Product* p2) {
				return p1->getNum() < p2->getNum(); });
			for (auto& p : *productList) {
				person->view(p);
				cout << "**********************************" << endl;
			}
			break;
		case 5:
			cout << "조회하려고 하는 물품의 이름을 입력해주세요: "; cin >> productName;
			for (auto& e : *productList) {
				if (e->getName() == productName) {
					product = e;
					break;
				}
			}
			if (product != NULL)
				person->view(product);
			else {
				cout << "해당 물품은 존재하지 않습니다." << endl;
			}
			break;
		}
		flag = back();
	}
}

void Menu::main_menu(Person* person) {
	int input_num;
	while (true) {
		system("cls");
		cout << "**********************************" << endl;
		cout << "물품 관리 서비스" << endl;;
		cout << "**********************************" << endl;
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "1. 물품 추가" << endl;
		cout << "2. 물품 삭제" << endl;
		cout << "3. 물품 조회" << endl;
		cout << "4. 종료 " << endl;
		cout << "입력 : "; cin >> input_num;
		switch (input_num) {
		case 1:
			if (person->getPos() == "M")
				product_add(person);
			else {
				cout << "일반 회원은 사용할 수 없는 기능입니다." << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 2:
			if (person->getPos() == "M")
				product_delete(person);
			else {
				cout << "일반 회원은 사용할 수 없는 기능입니다." << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 3:
			product_find(person);
			break;
		case 4:
			cout << "프로그램을 종료합니다." << endl;
			this->~Menu();
			exit(1);
			break;
		default:
			cout << "올바른 숫자를 입력해주세요." << endl;
			Sleep(2000);
			system("cls");
			break;
		}
	}
}

void Menu::login() {
	string id, password;
	bool flag = true;
	vector<Person*>* person_list = systemManager->getPersonV();
	while (flag) {
		system("cls");
		cout << "아이디 : "; cin >> id;
		cout << "비밀번호 : "; cin >> password;
		for (auto& p : *person_list) {
			if (p->getId() == id && p->getPassword() == password) {
				system("cls");
				main_menu(p);
			}
		}
		cout << "아이디 혹은 비밀번호가 틀렸습니다." << endl;
		flag = back();
	}
}

void Menu::join() {
	string name, id, password, pos = "m";
	bool flag = true, checkFlag = true;
	vector<Person*>* person_list = systemManager->getPersonV();
	while (flag) {
		system("cls");
		cout << "이름 : "; cin >> name;
		cout << "아이디 : "; cin >> id;
		cout << "비밀번호 : "; cin >> password;
		for (auto& p : *person_list) {
			if (p->getId() == id) {
				cout << "중복된 아이디입니다." << endl;
				checkFlag = false;
				break;
			}
		}
		if (checkFlag) {
			Person* person = new Member(id, password, name, pos);
			person_list->push_back(person);
			flag = false;
		}
		else {
			flag = back();
			checkFlag = flag;
		}
	}
	
}

void Menu::login_menu() {
	int input_num;
	while (true) {
		system("cls");
		cout << "**********************************" << endl;
		cout << "로그인" << endl;;
		cout << "**********************************" << endl;
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "1. 로그인 " << endl;
		cout << "2. 회원가입 " << endl;
		cout << "3. 종료 " << endl;
		cout << "입력 : "; cin >> input_num;
		switch (input_num) {
		case 1:
			login();
			break;
		case 2:
			join();
			break;
		case 3:
			cout << "프로그램을 종료합니다." << endl;
			this->~Menu();
			exit(1);
			break;
		default:
			cout << "올바른 숫자를 입력해주세요." << endl;
			Sleep(2000);
			system("cls");
			break;
		}
	}
}