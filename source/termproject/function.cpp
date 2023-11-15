#include "main.h"

// 물품 추가
void product_add() {
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
	cout << "이전으로 돌아가시겠습니까?(0 : yes, 1 : no) : ";
	cin >> input_back;
	if (input_back == 0) {
		main_menu();
	}
	else if (input_back == 1) {
		product_add();
	}
	else {
		cout << "올바로 된 숫자를 입력하시오";
		cin >> input_back;
	}
}

// 물품 삭제
void product_delete() {
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
}

// 물품 조회
void product_find() {
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
}

void product_find_name() {

}
void product_find_category() {

}

void main_menu() {
	int input_num;
	cout << "**********************************" << endl;
	cout << "물품 관리 서비스" << endl;;
	cout << "**********************************" << endl;
	cout << "무엇을 하시겠습니까?" << endl;
	cout << "1. 물품 추가" << endl;
	cout << "2. 물품 삭제" << endl;
	cout << "3. 물품 조회" << endl;
	cout << "입력 : ";
	cin >> input_num;
	switch (input_num) {
	case 1:
		product_add();
		break;
	case 2:
		product_delete();
		break;
	case 3:
		product_find();
		break;
	}
}