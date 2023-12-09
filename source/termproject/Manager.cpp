#include "Manager.h"
#include <time.h>

Manager::Manager(string id, string password, string name, string pos) :
	Person(id, password, name, pos) { }

void Manager::find(vector<Product*>products) {
	string product_name;
	cout << "찾으려고 하는 물품의 이름을 입력하시오: " << endl;
	for (auto& e : products) {
		if (e->getName() == product_name) {
			e->view();
			cout << e->getDate() << endl;
		}
	}
}

void Manager::add(vector<Product*>products) {
	int type;
	Product* product;
	string name, manufacturer, date;

	time_t now = time(0);
	struct tm tstruct;
	char buffer[80];
	tstruct = *localtime(&now);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tstruct);
	date = string(buffer);

	cout << "추가할 물품의 종류를 고르세요" << endl;
	cout << "1. CPU" << endl;
	cout << "2. HDD" << endl;
	cout << "3. Keyboard" << endl;
	cout << "4. Monitor" << endl;
	cout << "5. Mouse" << endl;
	cout << "6. RAM" << endl;
	cout << "7. SSD" << endl;
	cout << "8. VGA" << endl;

	try{
		cin >> type;
		if (type < 1 || type > 8)
			throw type;

		cout << "이름 : "; cin >> name;
		cout << "제조사 : "; cin >> manufacturer;
		if (type == 1) {
			string classification;
			int core_num, thread_num, L3_cache, bulid_in_graphics;
			cout << "종류 : "; cin >> classification;
			cout << "코어 수 : "; cin >> core_num;
			cout << "스레드 수 : "; cin >> thread_num;
			cout << "L3 캐시 : "; cin >> L3_cache;
			cout << "내장 그래픽 여부(0,1) : "; cin >> bulid_in_graphics;
			product = new CPU(name, manufacturer, classification, core_num, thread_num, L3_cache, bulid_in_graphics, date);
		}
		else if (type == 2) {
			string classification, recording_method;
			int capacity, RPM;
			cout << "종류 : "; cin >> classification;
			cout << "기록 방식 : "; cin >> recording_method;
			cout << "용량 : "; cin >> capacity;
			cout << "회전수 : "; cin >> RPM;;
			product = new HDD(name, manufacturer, classification, capacity, RPM, recording_method, date);
		}
		else if (type == 3) {
			string arragement, type;
			cout << "키 배열 : "; cin >> arragement;
			cout << "타입 : "; cin >> type;
			product = new Keyboard(name, manufacturer, arragement, type, date);
		}
		else if (type == 4) {
			int inch;
			string scan_rate, resolution;
			cout << "크기 : "; cin >> inch;
			cout << "주사율 : "; cin >> scan_rate;
			cout << "해상도 : "; cin >> resolution;
			product = new Monitor(name, manufacturer, inch, scan_rate, resolution, date);
		}
		else if (type == 5) {
			bool mouse_cable;
			cout << "유무선 여부(0,1) :"; cin >> mouse_cable;
			product = new Mouse(name, manufacturer, mouse_cable, date);
		}
		else if (type == 6) {
			string classifiction;
			int capacity;
			cout << "종류 : "; cin >> classifiction;
			cout << "용량 : "; cin >> capacity;
			product = new RAM(name, manufacturer, classifiction, capacity, date);
		}
		else if (type == 7) {
			string form_factor;
			int capacity;
			cout << "폼펙터 : "; cin >> form_factor;
			cout << "용량 : "; ; cin >> capacity;
			product = new SSD(name, manufacturer, form_factor, capacity, date);
		}
		else if (type == 8) {
			string chip_set, chip_set_detail;
			int port_num, memory;
			cout << "칩셋 : "; cin >> chip_set;
			cout << "칩 종류 : ";  cin >> chip_set_detail;
			cout << "포트 수 : ";  cin >> port_num;
			cout << "메모리 : ";  cin >> memory;
			product = new VGA(name, manufacturer, chip_set, chip_set_detail, port_num, memory, date);
		}
		products.push_back(product);
	}
	catch (int) {
		cout << "올바른 숫자를 입력해주세요." << endl;
		Sleep(5000);
		system("cls");
		add(products);
	}
}

void Manager::deleteProduct(vector<Product*>products) {
	string product_name;
	int count = 0;
	cout << "삭제하려고 하는 물품의 이름을 입력하시오: " << endl;
	for (auto& e : products) {
		if (e->getName() == product_name){
			if (e->getNum() == 1)
				products.erase(products.begin() + count);
			else
				e->setNum(e->getNum() - 1);
			e->view();
			cout << "을(를) 삭제합니다." << endl;
		}
		else {
			cout << "해당 이름을 가지는 물품이 없습니다." << endl;
		}
		count++;
	}
}