#pragma once
#include "Product.h"

class Speaker : public Product {
	static int speakerNum;
	string type;			// PC사운드바, 북셸스피커, 개틀라이트스피커,,,
	int size;				// inch
	bool wired;				// 유무선 여부
public:
	static int getSpeakerNum();
	Speaker(string name, string type, int size, bool wired);
};