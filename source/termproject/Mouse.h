#pragma once
#include "Product.h"

class Mouse : public Product {
	static int mouseNum;
	string type;			// ��, ������, ���ܼ�,,,
	int	sensitivity;		// ����
	bool wired;				// ������ ����
public:
	static int getMouseNum();
	Mouse(string name, string type, int sensitivity, bool wired);
};
