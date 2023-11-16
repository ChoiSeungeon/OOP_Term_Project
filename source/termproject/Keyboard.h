#pragma once
#include "Product.h"

class Keyboard : public Product {
	static int keyboardNum;
	string type;			// 기계식, 무접점, 멤브레인,,,
	string keyType;			// 적축, 갈축, 청축
	bool wired;				// 유무선 여부
public:
	static int getKeyboardNum();
	Keyboard(string name, string type, bool wired);
};