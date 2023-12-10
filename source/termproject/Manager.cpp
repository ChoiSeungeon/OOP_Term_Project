#include "Manager.h"
#include <time.h>

Manager::Manager(string id, string password, string name, string pos) :
	Person(id, password, name, pos) { }

void Manager::view(Product* product) {
	product->view();
	cout << "�ֱ� ��� ��¥ : " << product->getDate() << endl;
}

void Manager::add(vector<Product*>*products) {
	int type, flag = 0, num;
	Product* product = NULL;
	string name, manufacturer, date;

	time_t now = time(0);
	struct tm tstruct;
	char buffer[80];
	tstruct = *localtime(&now);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tstruct);
	date = string(buffer);

	cout << "�߰��� ��ǰ�� ������ ������" << endl;
	cout << "1. CPU" << endl;
	cout << "2. HDD" << endl;
	cout << "3. Keyboard" << endl;
	cout << "4. Monitor" << endl;
	cout << "5. Mouse" << endl;
	cout << "6. RAM" << endl;
	cout << "7. SSD" << endl;
	cout << "8. VGA" << endl;

	try{
		cout << "�Է� : "; cin >> type;
		if (type < 1 || type > 8)
			throw type;

		cout << "�̸� : "; cin >> name;
		for (auto& e : *products) {
			if (e->getName() == name) {
				cout << "�̸��� ���� ��ǰ�� �����մϴ�." << endl;
				cout << "**********************************" << endl;
				this->view(e);
				cout << "�ش� ��ǰ�� ������ ������ŵ�ϱ�? (1 : yes, 0 : no)" << endl;
				cout << "�Է� : "; cin >> flag;
				if (flag) {
					product = e;
					cout << "���� : "; cin >> num;
					e->setNum(e->getNum() + num);
					e->setDate(date);
					break;
				}
				else {
					cout << "��ǰ�� �̸��� �����Ͽ� �ٽ� �Է����ֽñ� �ٶ��ϴ�." << endl;
					Sleep(2000);
					system("cls");
					return;
				}
			}
		}

		if (!flag) {
			cout << "������ : "; cin >> manufacturer;
			if (type == 1) {
				string classification;
				int core_num, thread_num, L3_cache, bulid_in_graphics;
				cout << "���� : "; cin >> classification;
				cout << "�ھ� �� : "; cin >> core_num;
				cout << "������ �� : "; cin >> thread_num;
				cout << "L3 ĳ�� : "; cin >> L3_cache;
				cout << "���� �׷��� ����(0,1) : "; cin >> bulid_in_graphics;
				product = new CPU(name, manufacturer, classification, core_num, thread_num, L3_cache, bulid_in_graphics, date);
			}
			else if (type == 2) {
				string classification, recording_method;
				int capacity, RPM;
				cout << "���� : "; cin >> classification;
				cout << "��� ��� : "; cin >> recording_method;
				cout << "�뷮 : "; cin >> capacity;
				cout << "ȸ���� : "; cin >> RPM;;
				product = new HDD(name, manufacturer, classification, capacity, RPM, recording_method, date);
			}
			else if (type == 3) {
				string arragement, type;
				cout << "Ű �迭 : "; cin >> arragement;
				cout << "Ÿ�� : "; cin >> type;
				product = new Keyboard(name, manufacturer, arragement, type, date);
			}
			else if (type == 4) {
				int inch;
				string scan_rate, resolution;
				cout << "ũ�� : "; cin >> inch;
				cout << "�ֻ��� : "; cin >> scan_rate;
				cout << "�ػ� : "; cin >> resolution;
				product = new Monitor(name, manufacturer, inch, scan_rate, resolution, date);
			}
			else if (type == 5) {
				bool mouse_cable;
				cout << "������ ����(0,1) :"; cin >> mouse_cable;
				product = new Mouse(name, manufacturer, mouse_cable, date);
			}
			else if (type == 6) {
				string classifiction;
				int capacity;
				cout << "���� : "; cin >> classifiction;
				cout << "�뷮 : "; cin >> capacity;
				product = new RAM(name, manufacturer, classifiction, capacity, date);
			}
			else if (type == 7) {
				string form_factor;
				int capacity;
				cout << "������ : "; cin >> form_factor;
				cout << "�뷮 : "; ; cin >> capacity;
				product = new SSD(name, manufacturer, form_factor, capacity, date);
			}
			else if (type == 8) {
				string chip_set, chip_set_detail;
				int port_num, memory;
				cout << "Ĩ�� : "; cin >> chip_set;
				cout << "Ĩ ���� : ";  cin >> chip_set_detail;
				cout << "��Ʈ �� : ";  cin >> port_num;
				cout << "�޸� : ";  cin >> memory;
				product = new VGA(name, manufacturer, chip_set, chip_set_detail, port_num, memory, date);
			}
			products->push_back(product);
		}
		system("cls");
		cout << "**********************************" << endl;
		cout << "����� ��ǰ ����" << endl;
		cout << "**********************************" << endl;
		this->view(product);
	}
	catch (int) {
		system("cls");
		cout << "�ùٸ� ���ڸ� �Է����ּ���." << endl;
		Sleep(2000);
		system("cls");
		add(products);
	}
}

void Manager::deleteProduct(vector<Product*>*products) {
	string productName;
	int count = 0, productNum;
	Product* product = NULL;
	cout << "�����Ϸ��� �ϴ� ��ǰ�� �̸��� �Է����ּ��� : "; cin >> productName;
	for (auto& e : *products) {
		if (e->getName() == productName){
			product = e;
			break;
		}
		count++;
	}
	system("cls");
	try {
		if (product == NULL)
			throw productName;

		this->view(product);
		cout << "������ �Է��Ͻÿ� : "; cin >> productNum;

		if (productNum > product->getNum() || productNum < 0)
			throw productNum;

		product->setNum(product->getNum() - 1);
		if (product->getNum() == 0) {
			products->erase(products->begin() + count);
		}
		system("cls");
		cout << "**********************************" << endl;
		cout << "������ ��ǰ ����" << endl;
		cout << "**********************************" << endl;
		this->view(product);
		delete product;
	}
	catch (int) {
		cout << "�ùٸ� ������ �Է����ּ���" << endl;
	}
	catch (string) {
		cout << "��ġ�ϴ� ��ǰ�� �����ϴ�." << endl;
	}
}