#pragma once
#include "Product.h"

class Mouse : public Product {
	static int mouseNum;
	string type;			// 광, 레이저, 적외선,,,
	int	sensitivity;		// 감도
	bool wired;				// 유무선 여부
public:
	static int getMouseNum();
	Mouse(string name, string type, int sensitivity, bool wired);
};
