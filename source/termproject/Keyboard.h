#pragma once
#include "Product.h"

class Keyboard : public Product {
	static int keyboardNum;
	string type;			// ����, ������, ��극��,,,
	string keyType;			// ����, ����, û��
	bool wired;				// ������ ����
public:
	static int getKeyboardNum();
	Keyboard(string name, string type, bool wired);
};